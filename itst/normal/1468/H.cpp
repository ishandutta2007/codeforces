#include<bits/stdc++.h>
using namespace std;

bool vis[200003];

int main(){
	ios::sync_with_stdio(0); int T , N , K , L;
	for(cin >> T ; T ; --T){
		cin >> N >> K >> L; for(int i = 1 ; i <= N ; ++i) vis[i] = 0;
		for(int i = 1 ; i <= L ; ++i){int c; cin >> c; vis[c] = 1;}
		if((N - L) % (K- 1)){cout << "NO\n"; continue;}
		int cnt = 0; bool flg = 0;
		for(int i = 1 ; i <= N ; ++i)
			if(!vis[i]) ++cnt; else flg |= cnt >= (K - 1) / 2 && (N - L - cnt) >= (K - 1) / 2;
		cout << (flg ? "YES\n" : "NO\n");
	}
	return 0;
}