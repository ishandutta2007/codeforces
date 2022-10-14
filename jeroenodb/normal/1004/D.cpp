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
void er() {
    cout << "-1\n";
    exit(0);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    vi cnt(t+2);
    int mx=0;
    for(int i=0;i<t;++i) {
        int a; cin >> a;
        cnt[a]++;
        mx = max(a,mx);
    }
    if(cnt[0]!=1) er();
    int mn=1;
    while(cnt[mn]>=4*mn) {
        if(cnt[mn]>4*mn) er();
        mn++;
    }
    mn--;
    for(int n=1;n<=t;++n) {
        if(t%n==0) {
            int m = t/n;
            int x = mn,y=mx+mn-n+1;
            vi cnt2(t+2);
            for(int i=0;i<n;++i) {
                for(int j=0;j<m;++j) {
                    int res = abs(i-x)+abs(j-y);
                    if(res<=t) cnt2[res]++;
                }
            }
            if(cnt==cnt2) {
                cout << n << ' ' << m << '\n';
                cout << x+1 << ' ' << y+1 << '\n';
                exit(0);
            }
        }
    } 
    er();
}