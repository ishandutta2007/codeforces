#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
const int mod = 1e9 + 7;
const int MAXN = 100005;
const int MAXK = 205;

lint ipow(lint x, lint p){
	lint ret = 1, piv = x;
	while(p){
		if(p & 1) ret = ret * piv % mod;
		piv = piv * piv % mod;
		p >>= 1;
	}
	return ret;
}


int n, k, sz[MAXN];
vector<int> gph[MAXN];
lint dp[MAXN][MAXK]; // (dp, lower edges)
vector<int> ord;

void dfs(int x){
	ord.push_back(x);
	sz[x] = 0;
	for(auto &i : gph[x]){
		gph[i].erase(find(gph[i].begin(), gph[i].end(), x));
		dfs(i);
		sz[x] += sz[i] + 1;
	}
}

lint func[MAXN];
lint DAP[MAXK];
lint con[MAXK][MAXK], fact[MAXN], pwr[MAXN];
int main(){
	scanf("%d %d",&n,&k);
	for(int i=0; i<n-1; i++){
		int s, e; scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	pwr[0] = fact[0] = 1;
	for(int i=1; i<MAXN; i++){
		pwr[i] = pwr[i-1] * 2 % mod;
		func[i] = (pwr[i] - 1) * ipow(pwr[i], mod - 2) % mod;
		fact[i] = i * fact[i-1] % mod;
	}
	con[0][0] = 1;
	for(int i=1; i<MAXK; i++){
		for(int j=1; j<MAXK; j++){
			con[i][j] = con[i-1][j-1] + con[i-1][j] * j;
			con[i][j] %= mod;
		}
	}
	dfs(1);
	reverse(ord.begin(), ord.end());
	for(auto &i : ord){
		int curSz = 0;
		lint fin[MAXK][3] = {};
		fin[0][0] = 1;
		for(auto &j : gph[i]){
			lint nfin[MAXK][3] = {};
			for(int x = 0; x <= curSz && x <= k; x++){
				for(int y = 0; y <= sz[j] && x + y <= k; y++){
					for(int z = 0; z < 3; z++){
						lint cur2 = fin[x][z] * dp[j][y] % mod;
						int isUp = (y != 0);
						nfin[x + y][min(z + isUp, 2)] += cur2;
						nfin[x + y + 1][min(z + 1, 2)] += cur2 * (y == 0 ? func[sz[j] + 1] : 1) % mod; 
					}
				}
			}
			curSz += sz[j] + 1;
			for(int x = 0; x <= k; x++){
				for(int j=0; j<3; j++){
					fin[x][j] = nfin[x][j] % mod;
				}
				lint cur1 = dp[j][x] * (x == 0 ? func[sz[j] + 1] : 1) % mod;
				DAP[x + 1] += cur1 * func[n - sz[j] - 1] % mod;
				DAP[x + 1] %= mod;
			}
		}
		for(int x = 0; x <= k; x++){
			DAP[x] += fin[x][2];
			DAP[x] %= mod;
			dp[i][x] = (fin[x][0] + fin[x][1] + fin[x][2]) % mod;
		}
	}
	lint ret = 0;
	for(int i=1; i<=k; i++){
		lint ans = DAP[i] * (fact[i] * con[k][i] % mod) % mod;
		ret += ans % mod;
		ret %= mod;
	}
	ret *= pwr[n];
	ret %= mod;
	cout << ret << endl;
}