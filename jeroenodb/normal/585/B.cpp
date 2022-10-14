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
bool solve() {
        int n,k; cin >> n >> k;
    string g[5];
    for(int i=1;i<=3;++i) cin >> g[i];
    bool good[5] = {};
    for(int j=1;j<=3;++j) if(g[j][0]=='s') good[j]=true;
    int shift=0;
    while(true) {
        shift++;
        if(shift>=n) break;
        for(int j=1;j<=3;++j) {
            if(g[j][shift]!='.') good[j]=false;
        }
        bool newgood[5] = {};
        for(int j=1;j<=3;++j) {
            if(g[j][shift]=='.' and (good[j+1] or good[j] or good[j-1]))  {
                newgood[j]=true;
            }
        }
        copy(newgood,newgood+5,good);
        shift++;
        if(shift>=n) break;
        for(int j=1;j<=3;++j) {
            if(g[j][shift]!='.') good[j]=false;
        }
        shift++;
        if(shift>=n) break;
        for(int j=1;j<=3;++j) {
            if(g[j][shift]!='.') good[j]=false;
        }
    }
    return good[1] or good[2] or good[3];
}
int main() {
    int t; cin >> t;
    while(t--) {
        cout << (solve()?"YES\n":"NO\n");
    }
}