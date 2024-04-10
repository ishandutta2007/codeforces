#include<bits/stdc++.h>
using namespace std;

#define int long long
map < int , vector < pair < int , int > > > dist;
#define num bitset < 1003 >
num cur[1003]; int N , x[1003] , y[1003] , ans[1003];

void ins(num &now){
	if(!now.count()) return;
	for(int i = 1 ; i <= N ; ++i)
		if(now[i]){
			for(int j = i - 1 ; j ; --j)
				if(cur[j][i]) cur[j] ^= now;
			cur[i] = now; break;
		}
}

signed main(){
	cin >> N; for(int i = 1 ; i <= N ; ++i) cin >> x[i] >> y[i];
	for(int i = 1 ; i <= N ; ++i)
		for(int j = i + 1 ; j <= N ; ++j)
			dist[(x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])].push_back(make_pair(i , j));
	for(auto t : dist){
		vector < pair < int , int > > tmp = t.second; num temp;
		for(int i = 1 ; i < tmp.size() ; ++i){
			temp.reset();
			temp.flip(tmp[0].first); temp.flip(tmp[0].second);
			temp ^= cur[tmp[0].first]; temp ^= cur[tmp[0].second]; 
			temp.flip(tmp[i].first); temp.flip(tmp[i].second);
			temp ^= cur[tmp[i].first]; temp ^= cur[tmp[i].second];
			ins(temp);
		}
	}
	int pre = 0; vector < int > pot;
	for(int i = 1 ; i <= N ; ++i)
		if(!cur[i].count()){ans[i] = pre; pre ^= 1; if(!pre){for(int j = 1 ; j <= N ; ++j) if(cur[j][i]) ans[j] ^= 1;}}
	for(int i = 1 ; i <= N ; ++i) if(!ans[i]) pot.push_back(i);
	cout << pot.size() << endl; for(auto t : pot) cout << t << ' ';
	return 0;
}