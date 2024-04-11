    #pragma GCC optimize("O2,unroll-loops")
    #pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
    #include<bits/stdc++.h>
    #define all(x) begin(x), end(x)
    #define apply fuckstl
    using namespace std;
    using ll = long long;
    const int maxn = 1<<18, mod = 1000000007;
    inline int slower_bound(int *a, int n, int x) {
    	int i = -1;
    i += 65536*(i+65536<n&&a[i+65536]<x);
    i += 32768*(i+32768<n&&a[i+32768]<x);
    i += 16384*(i+16384<n&&a[i+16384]<x);
    i += 8192*(i+8192<n&&a[i+8192]<x);
    i += 4096*(i+4096<n&&a[i+4096]<x);
    i += 2048*(i+2048<n&&a[i+2048]<x);
    i += 1024*(i+1024<n&&a[i+1024]<x);
    i += 512*(i+512<n&&a[i+512]<x);
    i += 256*(i+256<n&&a[i+256]<x);
    i += 128*(i+128<n&&a[i+128]<x);
    i += 64*(i+64<n&&a[i+64]<x);
    i += 32*(i+32<n&&a[i+32]<x);
    i += 16*(i+16<n&&a[i+16]<x);
    i += 8*(i+8<n&&a[i+8]<x);
    i += 4*(i+4<n&&a[i+4]<x);
    i += 2*(i+2<n&&a[i+2]<x);
    i += 1*(i+1<n&&a[i+1]<x);
    	return ++i < n && a[i] == x;
    }
    void solve() {	
    	int n, m, k;
    	cin >> n >> m >> k;
    	vector<int> deg(n+1), ded(n+1);
    	vector<vector<int>> g(n+1);
    	for(int f, t, i = 0; i < m; i++) {
    		cin >> f >> t;
    		g[f].push_back(t);
    		g[t].push_back(f);
    		deg[f]++, deg[t]++;
    	}
    	set<array<int, 2>> p;
    	auto remove = [&](int v) {
    		ded[v] = 1;
    		p.erase({deg[v], v});
    		for(auto &i : g[v]) if(!ded[i]) {
    			p.erase({deg[i], i});
    			deg[i]--;
    			p.insert({deg[i], i});
    		}
    	};
    	for(int i = 1; i <= n; i++) p.insert({deg[i], i}), sort(all(g[i]));
    	int C = 1;
    	vector<int> lst(n+1);
    	while(!p.empty() && p.begin()->at(0) < k) {
    		int v = p.begin()->at(1);
    		C++;
    		if(deg[v] == k-1) {
    			int ok = 1;
    			vector<int> cli{v};lst[v] = C;
    			for(auto i : g[v]) if(!ded[i]) ok &= deg[i] >= k-1, cli.push_back(i), lst[i] = C;
    			if(ok) {
    					int cur = 0;
    				for(auto i : cli)
    					for(auto j : cli) if(i < j) cur += slower_bound(g[i].data(), g[i].size(), j);
    				
    					if(cur < k*1ll*(k-1)/2) {ok = 0;}
    				if(ok) {
    					cout << "2\n";
    					for(auto i : cli) cout << i << " "; cout << '\n';
    					return;
    				}
    			}
    		}
    		remove(p.begin()->at(1));
    	}
    	if(p.empty()) {
    		cout << "-1\n";
    		return;
    	}
    	vector<int> ans;
    	for(int i = 1; i <= n; i++) if(!ded[i]) ans.push_back(i);
    	cout << "1 " << ans.size() << '\n';
    	for(auto &i : ans) cout << i << " ";cout << '\n';
    }
    int32_t main() {
    	cin.tie(0)->sync_with_stdio(0);
    	int t;cin >> t;
    	while(t--) {
    		solve();
    	}
    }