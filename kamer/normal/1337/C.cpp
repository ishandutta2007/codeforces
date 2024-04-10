    #include <iostream>
    #include <vector>
    #include <string>
    #include <map>
    #include <unordered_map>
    #include <set>
    #include <unordered_set>
    #include <queue>
    #include <stack>
    #include <math.h>
    #include <array>
    #include <functional>
    #include <numeric>
    #include <algorithm>
    #include <bitset>
     
     
    using namespace std;
     
    typedef long long ll;
    typedef long double ld;
    typedef pair<int, int> pii;
    typedef vector<int> vi;
    typedef vector<ll> vll;
    typedef vector<ld> vld;
     
    #define LL_MAX 9223372036854775807
    #define LL_MIN -9223372036854775806
    #define read(to, thresh) for(int i=0; i < thresh; ++i) cin >> to[i];
    #define all(x) x.begin(), x.end()
     
    template<class T>
    void smin(T &a, T b) {a = min(a, b);}
    template<class T>
    void smax(T &a, T b) {a = max(a, b);}
    template<class T>
    void print(vector<T> &a, string sep) {for(T el: a) cout << el << sep; cout << endl;}
     
    vector<bool> vis;
    vector<int> num_childs;
    vector<int> depth;
    vector<vector<int>> g;
    vector<int> parent;
     
    int calc_childs(int v, int d) {
        if(vis[v]) return 0;
        vis[v] = true;
        int s = 1;
        for(auto el: g[v]) {
            if(vis[el]) continue;
            parent[el] = v;
            s += calc_childs(el, d+1);
        }
        num_childs[v] = s;
        depth[v] = d;
        return s;
    }
     
    void solve() {
        int n, k; cin >> n >> k;
        num_childs.resize(n+1);
        g.resize(n+1);
        vis.resize(n+1);
        parent.resize(n+1);
        depth.resize(n+1);
        for(int i=1; i<n; i++) {
            int x, y; cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        
        calc_childs(1, 1);
        vector<int> nums(n+1);
        for(int i=1; i <= n; i++) {
            nums[i] = depth[i] - num_childs[i];
        }
        nums[0] = -10000000;
        sort(all(nums));
        reverse(all(nums));
        // print(depth, " ");
        
        ll s = 0;
        vis.clear();
        vis.resize(n+1);
        for(int i=0; i<k; i++) {
            s += nums[i];
            // if(vis[parent[nums[i].second]]) s--;
            // vis[nums[i].second] = true;
        }
        cout << s << endl;
    }
     
    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        // int t; cin >> t;
        
        // while(t--) {
            solve();
        // }
    }