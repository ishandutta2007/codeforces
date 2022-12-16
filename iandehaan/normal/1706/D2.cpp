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
        
    #define MAXN 100'010
        
    int n, k;
    int a[MAXN];
        
        
    map<int, vi> curr;
     
    int t, mn, out, top, mx, needed, result;
    bool poss;
        
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        cin >> t;
        while (t--) {
            
            cin >> n >> k;
            mn = 1e8;
            rep(i, 0, n) {
                cin >> a[i];
                curr[a[i]].pb(a[i]);
                mn = min(mn, a[i]);
            }
        
            out = (curr.rbegin()->first)-mn;
        
            while (!curr.empty()) {
                mx = curr.rbegin()->first - 1;
                //cerr << "at mx " << mx << endl;
                if (mx < 0) break;
                poss = true;
                for (const int& x : curr.rbegin()->second) {
                    needed = (x+1 + mx) / (mx+1);
                    if (needed > k) {
                        poss = false;
                        break;
                    }
                    result = x / needed;
                    if (result != 0) curr[result].pb(x);
                    //cout << "result " << result << endl;
                    
                    mn = min(mn, result);
        
                }
                //cerr << "blah " << sz(q) << endl;
                curr.erase(prev(curr.end()));
                if (!poss) break;
                if (!curr.empty()) out = min(out, (curr.rbegin()->first)-mn);
                else out = 0;
            }
            //cerr << "fin" << endl;
        
            curr.clear();
        
            cout << out << '\n';
        }
    }