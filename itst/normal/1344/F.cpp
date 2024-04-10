#include<bits/stdc++.h>
using namespace std;

bitset < 2003 > arr[2003] , val[2003];
int N , K , cnt , ans[1003];

int main(){
	ios::sync_with_stdio(0); cin >> N >> K;
	for(int i = 0 ; i < N ; ++i){val[i].set(i); val[i + N].set(i + N);}

	for(int i = 0 ; i < K ; ++i){
		string str; int num; cin >> str >> num; char ans;
		if(str == "mix"){
			while(num--){int p; cin >> p; --p; arr[cnt] ^= val[p]; arr[cnt + 1] ^= val[p + N];}
			cin >> ans;
			switch(ans){
			case 'W': break;
			case 'R': arr[cnt][2 * N] = 1; arr[cnt + 1][2 * N] = 1; break;
			case 'Y': arr[cnt + 1][2 * N] = 1; break;
			case 'B': arr[cnt][2 * N] = 1; break;
			}
			cnt += 2;
		}
		else{
			char op = 'R' + 'Y' + 'B' - str[0] - str[1];
			while(num--){
				int p; cin >> p; --p;
				switch(op){
				case 'R': swap(val[p] , val[p + N]); break;
				case 'Y': val[p + N] ^= val[p]; break;
				case 'B': val[p] ^= val[p + N]; break;
				}
			}
		}
	}

	int now = 0;
	for(int i = 0 ; i < 2 * N ; ++i){
		int cur = now; while(cur < cnt && !arr[cur][i]) ++cur;
		if(cur == cnt) continue;
		swap(arr[cur] , arr[now]);
		while(++cur < cnt) if(arr[cur][i]) arr[cur] ^= arr[now];
		++now;
	}
	for(int i = 0 ; i < cnt ; ++i) if(arr[i]._Find_first() == 2 * N){cout << "NO"; return 0;}
	for(int i = now - 1 ; ~i ; --i)
		if(arr[i][2 * N]){
			int t = arr[i]._Find_first(); ans[t >= N ? t - N : t] += t >= N ? 2 : 1;
			for(int j = i - 1 ; ~j ; --j) if(arr[j][t]) arr[j].flip(2 * N);
		}

	cout << "YES" << endl;
	for(int i = 0 ; i < N ; ++i)
		cout << (ans[i] == 0 ? '.' : (ans[i] == 1 ? 'B' : (ans[i] == 2 ? 'Y' : 'R')));
	return 0;
}