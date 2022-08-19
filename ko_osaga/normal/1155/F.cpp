#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int MAXN = 300005;

inline int Get(int msk, int v){
	return (msk >> v) & 1;
}

int n, m, adj[14][14];
bool path[1 << 14][14][14];
int dp[1 << 14], popcnt[1 << 14];
tuple<int, int, int> trk[1 << 14];

int main(){
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int s, e; cin >> s >> e;
		s--; e--;
		adj[s][e] = adj[e][s] = 1;
	}
	for(int i=1; i<(1<<n); i++){
		popcnt[i] = popcnt[i - (i & -i)] + 1;
	}
	for(int i=0; i<(1<<n); i++){
		for(int j=0; j<n; j++){
			if(!Get(i, j)) continue;
			for(int k=0; k<n; k++){
				if(k == j || Get(i, k) == 0) continue;
				if(popcnt[i] == 2 && adj[j][k]) path[i][j][k] = 1;
				else{
					for(int l=0; l<n; l++){
						if(adj[l][k] && path[i ^ (1 << k)][j][l]){
							path[i][j][k] = 1;
						}
					}
				}
			}
		}
	}
	for(int i=0; i<(1<<n); i++){
		dp[i] = 1e9;
		trk[i] = make_tuple(-1, -1, -1);
		vector<int> v;
		for(int j=0; j<n; j++){
			if(Get(i, j)) v.push_back(j);
		}
		for(auto &j : v){
			for(auto &k : v){
				if(j != k && adj[j][k] && path[i][j][k] && popcnt[i] > 2){
					dp[i] = popcnt[i]; // cycle
					break;
				}
			}
		}
		for(int j = i; j != 0; j = (j - 1) & i){
			for(auto &k : v){
				if(Get(j, k)) continue;
				for(auto &l : v){
					if(!Get(j, l) && path[j | (1<<k) | (1<<l)][k][l] && k != l){
						int nxt = dp[i ^ j] + popcnt[j] + 1;
						if(dp[i] > nxt){
							dp[i] = nxt;
							trk[i] = make_tuple(j, k, l);
						}
					}
					// k is not in cycle path, l is in cycle path
					if(Get(j, l) && path[j | (1<<k)][k][l] && adj[k][l] && popcnt[j] >= 2){
						int nxt = dp[i ^ j] + popcnt[j] + 1;
						if(dp[i] > nxt){
							dp[i] = nxt;
							trk[i] = make_tuple(j, k, k);
						}
					}
				}
			}
		}
	}
	cout << dp[(1<<n) - 1] << endl;
	int msk;
	vector<pi> edg;

	auto addCycle = [&](int msk, int st, int ed){
		if(st == ed){
			for(int k=0; k<n; k++){
				if(adj[k][st] && path[msk][st][k]){
					edg.emplace_back(k, st);
					ed = k;
					break;
				}
			}
		}
		while(popcnt[msk] > 2){
			for(int l = 0; l < n; l++){
				if(Get(msk, l) && path[msk ^ (1<<ed)][st][l] && adj[l][ed]){
					edg.emplace_back(l, ed);
					msk ^= (1 << ed);
					ed = l;
					break;
				}
			}
		}
		edg.emplace_back(st, ed);
	};
	for(msk = (1 << n) - 1; get<0>(trk[msk]) != -1; ){
		int x, y, z;
		tie(x, y, z) = trk[msk];
		addCycle(x | (1<<y) | (1<<z), y, z);
		msk ^= x;
	}
	bool good = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(!good && adj[i][j] && path[msk][i][j]){
				addCycle(msk, i, j);
				edg.emplace_back(i, j);
				good = 1;
			}
		}
	}
	assert(dp[(1<<n) - 1] == edg.size());
	for(auto &i : edg) printf("%d %d\n", i.first + 1, i.second + 1);
}