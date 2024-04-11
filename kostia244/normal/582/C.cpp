    #pragma GCC optimize("O2,unroll-loops")
    #pragma GCC target("avx,avx2,sse,sse2,ssse3")
    #include<bits/stdc++.h>
    #define int long long
    #define all(x) x.begin(), x.end()
    using namespace std;
    using ll = long long;
    const int maxn = 1<<18, mod = 1e9 + 7;
    int n, a[maxn], cop[maxn], mx[maxn], id[maxn], t[maxn], gg[maxn];
    int check(int d) {
    	if(d == n) return 0;
    	memset(mx, -0x3f, sizeof mx);
    	int ans = 0;
    	for(int i = 0; i <= n; i++) id[i] = i >= d ? id[i-d] : i;
    	for(int i = 0; i < n; i++) mx[i%d] = max(mx[id[i]], a[i]);
    	for(int i = 0; i < n; i++) t[i] = a[i>=n?i-n:i] >= mx[id[i]];
    	for(int i = 1; i <= n; i++) cop[i] = cop[i-1] + (i%d == 0 && gg[i]==d);
    	int j = 0;
    	for(int i = 0; i < n; i++) {
    		if(!t[i]) continue;
    		j = max(i, j);
    		while(j < 2*n && t[j>=n?j-n:j]) j++;
    		int len = min(n-1, j-i);
    		ans = (ans + cop[len]);
    	}
    	return ans;
    }
    signed main() {
    	cin.tie(0)->sync_with_stdio(0);
    	cin >> n;
    	for(int i = 0; i < n; i++) cin >> a[i];
    	
    	for(int i = 1; i <= n; i++) gg[i] = __gcd(i, n);
    	int ans = 0;
    	for(int i = 1; i*i <= n; i++) {
    		if(n%i) continue;
    		ans = (check(i) + ans);
    		if(i*i != n)
    			ans = (check(n/i) + ans);
    	}
    	cout << ans << endl;
    }