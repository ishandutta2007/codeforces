#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, x; cin >> n >> x;
        multiset<int> st;
        vector<int> a(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            st.insert(a[i]);
        }
        int ans = 0;
        while(!st.empty()){
            auto p = st.begin();
            auto q = st.lower_bound(*p * x);
            if(q != st.end() && *p * x == *q){
                st.erase(q);
            }
            else ++ans;
            st.erase(p);
        }
        cout << ans << '\n';
    }
    return 0;
}