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
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string a,b; cin >> a >> b;
        // change
        int ans=-1;
        auto check = [&](int i) {
            if(ans==-1) ans=i;
            else ans = min(ans,i);
        };
        vector<bool> change(n);
        for(int i=0;i<n;++i) {
            change[i] = a[i]!=b[i];
        }
        for(int rep=0;rep<2;++rep) {
            int res=0, op1=0;
            for(int i=0;i<n;++i) {
                if(change[i]) {
                    res++;
                    if((a[i]=='1')) {
                        op1++;
                    }
                }
            }
            if(op1==(res+1)/2 and res%2 == rep) {
                check(res);
            }
            for(int i=0;i<n;++i) change[i] = !change[i];
        }
        cout << ans << '\n';
    }
}