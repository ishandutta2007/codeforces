    #include <bits/stdc++.h>
    using namespace std;
     
    #define rep(i, a, b) for(int i = a; i < (b); ++i)
    #define all(x) begin(x), end(x)
    #define sz(x) (int)(x).size()
    typedef long long ll;
    typedef pair<int, int> pii;
    typedef vector<int> vi;
     
    #define pb push_back
    #define mp make_pair
     
    int main() {
    	//ios_base::sync_with_stdio(false);
        //cin.tie(NULL);
     
        int n;
        cin >> n;
        stack<pair<int, double>> st;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            pair<int, ll> top = mp(1, x);
     
            while (true) {
                if (st.empty()) break;
     
                if (top.second*st.top().first < st.top().second*top.first) {
                    top = mp(top.first + st.top().first, top.second + st.top().second);
                    st.pop();
                } else {
                    break;
                }
            }
            st.push(top);
        }
     
        vector<double> out;
        while (!st.empty()) {
            pair<int, ll> top = st.top(); st.pop();
            double outval = top.second / double(top.first); 
            for (int i = 0; i < top.first; i++) {
                out.pb(outval);
            }
        }
        reverse(all(out));
        for (double x : out) {
            cout << fixed << setprecision(15) << x << '\n';
        }
     
     
    }