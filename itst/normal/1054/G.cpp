#include<bits/stdc++.h>
using namespace std;

#define BS bitset < 2003 >
BS val[2003] , in[2003] , subs[2003]; int N , M , T , fa[2003];

int main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N >> M; for(int i = 1 ; i <= max(M , N) ; ++i){val[i].reset(); in[i].reset(); subs[i].reset();}
		for(int i = 1 ; i <= M ; ++i){
			string s; cin >> s; for(int j = 1 ; j <= N ; ++j) in[i][j] = s[j - 1] - '0';
			if(in[i].count() != 1) for(int j = 1 ; j <= N ; ++j) if(s[j - 1] == '1') val[j].set(i);
		}
		for(int i = 1 ; i <= N ; ++i) for(int j = 1 ; j <= N ; ++j) subs[i][j] = i != j && (val[i] & val[j]) == val[i];
		memset(fa , 0 , sizeof(fa)); bool ans = 1;
		for(int i = 1 ; ans && i <= N - 1 ; ++i){
			bool flg = 0;
			for(int j = 1 ; j <= N && !flg ; ++j)
				if(!fa[j] && subs[j].count()){
					int k = subs[j]._Find_first(); fa[j] = k; flg = 1;
					for(int k = 1 ; k <= N ; ++k) subs[k].reset(j);
					for(int l = 1 ; l <= M ; ++l)
						if(val[j][l]){
							in[l].reset(j);
							if(in[l].count() == 1){
								int t = in[l]._Find_first(); val[t].reset(l);
								for(int p = 1 ; p <= N ; ++p){
									subs[p][t] = p != t && !fa[p] && !fa[t] && (val[p] & val[t]) == val[p];
									subs[t][p] = p != t && !fa[p] && !fa[t] && (val[p] & val[t]) == val[t];
								}
							}
						}
				}
			ans &= flg;
		}
		if(!ans) cout << "NO\n"; else{cout << "YES\n"; for(int i = 1 ; i <= N ; ++i) if(fa[i]) cout << fa[i] << ' ' << i << '\n';}
	}
	return 0;
}