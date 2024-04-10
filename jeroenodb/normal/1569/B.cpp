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
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<string> ans(n, string(n,'X'));
    vi p(n); 
    for(int i=1;i<n;++i) p[i]=p[i-1]+(s[i]=='2');
    for(int i=0;i<n;++i) {

        for(int j=0;j<n;++j) if(i!=j) {
            if(s[i]=='1' or s[j]=='1') {
                ans[i][j]='=';
            } else {
                if(i>j) ans[i][j] = (ans[j][i]=='+'?'-':'+');
                else {
                    // want at least one plus
                    if((p[i]-p[j]+3*100)%3==1) {
                        ans[i][j]='+';
                    } else ans[i][j]='-';
                }
            }
        }

    }
    for(int i=0;i<n;++i) if(s[i]!='1') {
        bool good=false;
        for(int j=0;j<n;++j) if(ans[i][j]=='+') good=true;
        if(!good) {
            cout << "NO\n";
            return;
        }
    } 
    cout << "YES\n";
    for(auto& i : ans) {
        cout << i << '\n';
    }
}
int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}