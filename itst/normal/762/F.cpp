#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7 , seed = 233 , P = 998244853;
int N , M , T;

vector < int > nxt[13]; int sz[13] , val[13];
int Hashing(int x , int p){
	vector < pair < int , int > > pot; sz[x] = 1;
	for(auto t : nxt[x])
		if(t != p){
			int p = Hashing(t , x); pot.push_back(make_pair(p , sz[t]));
			sz[x] += sz[t];
		}
	sort(pot.begin() , pot.end()); int sum = 0;
	for(auto t : pot){
		for(int p = 0 ; p < t.second ; ++p) sum = 1ll * sum * seed % P;
		sum = (sum + t.first) % P;
	}
	sum = (1ll * sum * seed + sz[x]) % P; return val[x] = sum;
}

map < int , int > id; vector < pair < int , int > > trs[13];
void prepare(int x , int p){
	for(auto t : nxt[x]) if(t != p) prepare(t , x);
	if(id.find(val[x]) == id.end()){
		int t = id.size(); id[val[x]] = t; map < int , int > cnt; 
		for(auto t : nxt[x]) if(t != p) ++cnt[id[val[t]]];
		trs[t] = vector < pair < int , int > >(cnt.begin() , cnt.end());
	}
}

int upd(int x){return x + (x >> 31 & MOD);}
vector < int > nxt1[1003]; int ans = 0 , dp[1003][12];
void dfs(int x , int p){
	for(auto t : nxt1[x]) if(t != p) dfs(t , x);
	dp[x][0] = 1;
	for(int i = 1 ; i < id.size() ; ++i){
		static int tdp[1 << 11]; memset(tdp , 0 , sizeof(tdp)); tdp[0] = 1;
		vector < pair < int , int > > &tr = trs[i]; 
		int tms[13] , sz = tr.size(); tms[0] = 1;
		for(int j = 0 ; j < sz ; ++j) tms[j + 1] = tms[j] * (tr[j].second + 1);
		for(auto t : nxt1[x])
			if(t != p){
				static int tmp[1 << 11]; memset(tmp , 0 , sizeof(int) * tms[sz]);
				for(int j = 0 ; j < sz ; ++j){
					int p = tr[j].first , q = tr[j].second;
					for(int k = 0 ; k < tms[sz] ; ++k)
						if(k / tms[j] % (q + 1) != q)
							tmp[k + tms[j]] = (tmp[k + tms[j]] + 1ll * tdp[k] * dp[t][p]) % MOD;
				}
				for(int j = 0 ; j < tms[sz] ; ++j) tdp[j] = upd(tdp[j] + tmp[j] - MOD);
			}
		dp[x][i] = tdp[tms[sz] - 1];
	}
	ans = upd(ans + dp[x][id.size() - 1] - MOD);
}

int main(){
	cin >> M; for(int i = 1 ; i < M ; ++i){int p , q; cin >> p >> q; nxt1[p].push_back(q); nxt1[q].push_back(p);}
	cin >> N; for(int p , q , i = 1 ; i < N ; ++i){cin >> p >> q; nxt[p].push_back(q); nxt[q].push_back(p);}
	set < int > found; ans = 0;
	for(int i = 1 ; i <= N ; ++i){
		int t = Hashing(i , 0);
		if(found.find(t) != found.end()) continue;
		found.insert(t); id.clear(); prepare(i , 0); dfs(1 , 0);
	}
	cout << ans; return 0;
}