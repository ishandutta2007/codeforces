    #pragma GCC optimize("O2,unroll-loops")
    #pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4.1,sse4.2,popcnt")
    #include<bits/extc++.h>
    #define all(x) begin(x), end(x)
    using namespace std;
    using ll = long long;
    const int maxn = 1<<17, mod = 1e9 + 7;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int f(int n, int k) {
    	int res = n%k;n -= res;
    	if(res) res--;
    	n/=k;
    	res += n*(k-1);
    	return res - (k-1);
    }
    signed main() {
    	cin.tie(0)->sync_with_stdio(0);
    	int n, k = 1;
    	cin >> n;
    	for(int i = 1; i <= n; i++) if(f(n, i) > f(n, k)) k = i;
    	vector<int> a(n);
    	//cout << k << " " << f(n, k)<< endl;
    	while(count(all(a),1) < f(n, k)) {
    		vector<int> work;
    		for(int i = 0; work.size() < k; i++) {
    			assert(i < n);
    			if((i+1)%k && !a[i]) {
    				work.push_back(i);
    				a[i] = 1;
    			}
    		}
    		cout << work.size() << " ";
    		for(auto &i : work) cout << i+1 << " "; cout << endl;
    		int t;
    		cin >> t;t--;
    		for(int i = 0; i < k; i++) a[(t+i)%n] = 0;
    	}
    	cout << 0 << endl;
    }