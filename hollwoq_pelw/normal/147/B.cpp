#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")


#include <bits/stdc++.h>

// #define int long long

using namespace std;

const int MAXN = 305;
int graph[MAXN][MAXN];
int n, m;

struct mat {
	vector<vector<int>> a;
	mat() {
	    
	}
	mat(int n) {
		a.resize(n + 1);
		for (int i = 1; i <= n; i++) 
		    a[i].assign(n + 1, -1e9);
		for (int i = 1; i <= n; i++)
		    a[i][i] = 0;
	}
	
	mat operator * (mat b) const {
		mat r(n);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) r.a[i][j] = max(r.a[i][j], a[i][k] + b.a[k][j]);
			}
		return r;
	}
	
	bool chk(){
	    for (int i = 1; i <= n; i++){
	        if (a[i][i] > 0) return 1;
	    }
	    return 0;
	}
};

mat power(mat x, int a) {
	mat res(n);
	while (a) {
		if (a & 1) res = res * x;
		x = x * x;
		a >>= 1;
	}
	return res;
}

mat base[10];

signed main() {
	cin.tie(0)->sync_with_stdio(0); cout.tie(0);
	cin >> n >> m;
	base[0] = mat(n);
// 	return 0;
	for (int i = 1; i <= m; i++) {
		int u, v, uv, vu;
		cin >> u >> v >> uv >> vu;
		base[0].a[u][v] = uv;
		base[0].a[v][u] = vu;
	}
	for (int i = 1; i < 10; i++)
	    base[i] = base[i - 1] * base[i - 1];
	  
	if (!base[9].chk()) return cout << 0, 0;
	
	
	mat cur(n);
	int ans = 1;
	for (int i = 9; i >= 0; i--){
        mat nxt = cur * base[i];
        if (nxt.chk()){
            continue;
        }else{
            ans += (1 << i);
            cur = nxt;
        }
	}
	cout << ans;
}