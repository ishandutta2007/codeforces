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
const int mxN = 1e5+1, oo = 1e9, MX=1000;
struct grundy {
    vi g;
    int period;
    grundy() : g(MX+1){
        g[0]=0;
        g[1]=0;
        for(int i=2;i<=MX;++i) {
            set<int> s;
            for(int j=0;j<=i-2;++j) {
                s.insert(g[j]^g[i-2-j]);
            }
            while(s.count(g[i])) ++ g[i];
        }
        

        for(period = 200;period<=300;++period) {
            // how to check if it is a period?
            // look at last period block and check with block before that
            bool good=true;
            for(int j=0;j<period;++j) {
                if(g[MX-j]!=g[MX-j-period]) good=false;
            }
            if(good) break;
        }
        debug(period);
    }
    int get(int n) {
        int times = max(0,(n-MX+period-1)/period);
        n-=times*period;
        return g[n];
    }
};
grundy g;
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    s = '?'+s+'?';
    n+=2;
    char xr = 'R'^'B';
    int bal=0;
    for(int i=1;i<n-1;++i) {
        if((s[i-1]^xr)!=s[i] and (s[i+1]^xr)!=s[i]) {
            if(s[i]=='R') bal++;
            else bal--;
            s[i]='?';
        }
    }
    int parity=0;
    for(int i=0;i<n;) {
        if(s[i]!='?') {
            int j=i+1;
            while(s[j]==(s[j-1]^xr)) ++j;
            if((j-i)%2==1) {
                if(s[i]=='R') bal++;
                else bal--;
            } 
            parity^=g.get(j-i);
            i=j;
        } else i++;
    }

    if(bal>0 or (bal==0 and parity)) cout << "Alice\n";
    else cout << "Bob\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}