#include<bits/stdc++.h>
using namespace std;

const int _ = 5e5 + 7; int fa[_] , val[_] , col[_] , N , M , K , s[_] , t[_]; bool ban[_];
map < pair < int , int > , vector < int > > pot;
int find(int x){
	if(fa[x] == x) return x;
	int t = find(fa[x]);
	val[x] ^= val[fa[x]];
	return fa[x] = t;
}

int main(){
	ios::sync_with_stdio(0); cin >> N >> M >> K;
	for(int i = 1 ; i <= N ; ++i) cin >> col[i];
	for(int i = 1 ; i <= N ; ++i) fa[i] = i; 
	for(int i = 1 ; i <= M ; ++i){
		cin >> s[i] >> t[i];
		if(col[s[i]] == col[t[i]]){
			if(find(s[i]) != find(t[i])){
				int p = find(t[i]) , q = find(s[i]);
				val[p] = val[s[i]] ^ val[t[i]] ^ 1; fa[p] = q;
			}else if(!ban[col[s[i]]] && val[s[i]] == val[t[i]]){ban[col[s[i]]] = 1; --K;}
		}else pot[make_pair(min(col[s[i]] , col[t[i]]) , max(col[s[i]] , col[t[i]]))].push_back(i);
	}
	for(int i = 1 ; i <= N ; ++i) find(i);
	static int tfa[_] , tvl[_]; memcpy(tfa , fa , sizeof(fa)); memcpy(tvl , val , sizeof(val));
	
	long long ans = K * (K - 1ll) / 2;
	for(auto x : pot)
		if(!ban[x.first.first] && !ban[x.first.second]){
			--ans; bool f = 1; vector < int > tc;
			for(auto i : x.second){
				tc.push_back(s[i]); tc.push_back(t[i]);
				if(find(s[i]) != find(t[i])){
					tc.push_back(find(t[i])); int p = find(t[i]) , q = find(s[i]);
					val[p] = val[s[i]] ^ val[t[i]] ^ 1; fa[p] = q;
				}else if(val[s[i]] == val[t[i]]) f = 0;
			}
			ans += f; for(auto p : tc){fa[p] = tfa[p]; val[p] = tvl[p];}
		}
	cout << ans; return 0;
}