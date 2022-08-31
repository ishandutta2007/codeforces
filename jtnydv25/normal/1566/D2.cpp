#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#define endl '\n'
#endif

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define T int
#define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>


int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<int> a(n * m);
        vector<int> b(n * m);
        vector<ordered_set> os(n);
        map<int, vector<pii>> pos;
        for(int i = 0; i < n * m; i++) cin >> a[i];
        b = a;
        sort(all(b));
        for(int i = 0; i < n * m; i++){
            pos[b[i]].push_back(make_pair(i / m, -(i % m)));
        }
        map<int, int> where;
        for(auto& it: pos){
            sort(all(it.second));
            where[it.first] = 0;
        }
        ll ans = 0;
        for(int i = 0; i < n * m; i++){
            auto cell = pos[a[i]][where[a[i]]++];
            int p = cell.first, q = -cell.second;
            ans += os[p].order_of_key(q);
            os[p].insert(q);
        }
        cout << ans << endl;
    }
}