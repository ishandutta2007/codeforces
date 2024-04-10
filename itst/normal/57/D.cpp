#include<bits/stdc++.h>
using namespace std;

#define int long long
bool vis[1003][1003]; vector < int > h , l;
int N , M;

signed main(){
	cin >> N >> M;
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= M ; ++j){
			char c; cin >> c;
			vis[i][j] = c == 'X';
		}
	int cnt = 0 , sum = 0 , ans = 0;
	for(int i = 1 ; i <= N ; ++i){
		int num = 0;
		for(int j = 1 ; j <= M ; ++j)
			num += !vis[i][j];
		ans += 2 * num * (i * cnt - sum);
		cnt += num; sum += num * i;
	}
	cnt = 0; sum = 0;
	for(int i = 1 ; i <= M ; ++i){
		int num = 0;
		for(int j = 1 ; j <= N ; ++j)
			num += !vis[j][i];
		ans += 2 * num * (i * cnt - sum);
		cnt += num; sum += num * i;
	}

#define sgn(x) (x > 0)
	for(int i = 1 ; i <= N + 1 ; ++i){
		vector < int > pot;
		do{
			bool flg = 0;
			for(int j = 1 ; !flg && j <= M ; ++j)
				if(vis[i][j]){pot.push_back(j); flg = 1;}
			if(!flg){
				if(pot.empty()) break;
				int pos = 1;
				while(pos < pot.size()){
					int pos1 = pos; bool f = sgn(pot[pos] - pot[pos - 1]);
					while(pos1 < pot.size() && sgn(pot[pos1] - pot[pos1 - 1]) == f) ++pos1;
					int pre = 0;
					for(int j = pos - 1 ; j < pos1 ; ++j){
						ans += pre * (f ? M - pot[j] : pot[j] - 1) * 2 * 2;
						pre += f ? pot[j] - 1 : M - pot[j];
					}
					pos = pos1;
				}
				for(auto t : pot) ans += (M - t) * (t - 1) * 2 * 2;
				break;
			}
		}while(++i);
	}
	
	for(int i = 1 ; i <= M + 1 ; ++i){
		vector < int > pot;
		do{
			bool flg = 0;
			for(int j = 1 ; !flg && j <= N ; ++j)
				if(vis[j][i]){pot.push_back(j); flg = 1;}
			if(!flg){
				if(pot.empty()) break;
				int pos = 1;
				while(pos < pot.size()){
					int pos1 = pos; bool f = sgn(pot[pos] - pot[pos - 1]);
					while(pos1 < pot.size() && sgn(pot[pos1] - pot[pos1 - 1]) == f) ++pos1;
					int pre = 0;
					for(int j = pos - 1 ; j < pos1 ; ++j){
						ans += pre * (f ? N - pot[j] : pot[j] - 1) * 2 * 2;
						pre += f ? pot[j] - 1 : N - pot[j];
					}
					pos = pos1;
				}
				for(auto t : pot) ans += (N - t) * (t - 1) * 2 * 2;
				break;
			}
		}while(++i);
	}

	cnt = 0;
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= M ; ++j)
			cnt += !vis[i][j];
	cout << fixed << setprecision(10) << 1.0 * ans / cnt / cnt << endl;
	return 0;
}