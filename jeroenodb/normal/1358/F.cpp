#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1, oo = 1e9;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<ll> a(n),b(n);
    for(auto& i : a) cin >> i;
    for(auto& i : b) cin >> i;
    string res;
    if(n==1) {
        if(a[0]==b[0]) {
            cout << "SMALL\n0\n";
        } else cout << "IMPOSSIBLE\n";
        exit(0);
    } else if(n==2) {
        // calculate if answer is big
        auto d = b;
        auto c = a;
        ll sm = d[0]+d[1]-c[0]-c[1],ans=0;
        while(sm>0 and d[0] and d[1]) {
            if(d[0]<d[1]) swap(d[0],d[1]);
            ll total = min(d[0]/d[1],sm/d[1]);
            ans+=total;
            if(!total){
                break;
            }
            d[0]-=d[1]*total;
            sm-=d[1]*total;
        }
        sort(all(c)), sort(all(d));
        if(c!=d) {
            cout << "IMPOSSIBLE\n";
            exit(0);
        }
        if(ans>2e5) {
            cout << "BIG\n" << ans << '\n';
            exit(0);
        }

    }
    bool rev=false; 
    auto ra =a;
    reverse(all(ra));
    int ops=0;
    while(true) {
        if(a==b) break;
        if(ra==b) {
            res.push_back('R');
            break;
        }
        bool bad=false;
        for(int i=0;i<n-1;++i) {
            if(b[i]>=b[i+1]) {
                bad=true;
                break;
            }
        }
        if(bad) {
            if(rev) {
                cout << "IMPOSSIBLE\n";
                exit(0);
            }
            res.push_back('R');
            reverse(all(b));
            rev=true;
        } else {
            rev=false;
            ops++;
            res.push_back('P');
            for(int i=n-1;i>0;--i) {
                b[i]-=b[i-1];
            }
        }
    }
    if(res.size()>2e5) {
        cout << "BIG\n" << ops << '\n';
        exit(0);
    }
    cout << "SMALL\n";
    reverse(all(res));
    cout << res.size() << '\n';
    cout << res << '\n';
    
}