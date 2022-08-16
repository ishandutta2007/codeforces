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
#define T pair<int, int>
#define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>


int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<int> a(n * m);
        int c = 0;
        ordered_set os;
        ll ans = 0;
        for(int i = 0; i < n * m; i++){
            cin >> a[i];
            os.insert({a[i], ++c});
            ans += os.order_of_key({a[i], -1});
        }
        cout << ans << endl;
    }
}