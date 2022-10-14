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
const int mxN = 1000+1, oo = 1e9;
double p[mxN][mxN];
int main() {
    int n,m; cin >> n >> m;
    vi perm(n); for(auto& i : perm) cin >> i;
    for(int i=0;i<n;++i) for(int j=i+1;j<n;++j) {
        p[i][j]=perm[i]>perm[j];
    }
    while(m--) {
        int a,b; cin >> a >> b;
        --a,--b;
        if(a>b) swap(a,b);
        for(int i=0;i<a;++i) {
            p[i][a]=p[i][b]=0.5*(p[i][a]+p[i][b]);
        }
        for(int i=b+1;i<n;++i) {
            p[a][i]=p[b][i] = 0.5*(p[a][i]+p[b][i]);
        }
        for(int i=a+1;i<b;++i) {
            auto tmp = 0.5*(p[a][i]+(1-p[i][b]));
            p[i][b] = 0.5*((1-p[a][i])+p[i][b]);
            p[a][i]=tmp;

        }
        p[a][b]=0.5;
    }
    double ans=0;
    for(int i=0;i<n;++i) for(int j=i+1;j<n;++j) {
        ans+=p[i][j];
    }
    cout << setprecision(15) << ans << '\n';
}