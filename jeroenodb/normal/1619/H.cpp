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
    int n,q; cin >> n >> q;
    vi p(n); for(auto& i : p) cin >> i,--i;
    int B = max(1.0,sqrt(n/2));
    vi ip(n),jmp(n);
    for(int i=0;i<n;++i) ip[p[i]]=i;
    for(int i=0;i<n;++i) {
        jmp[i]=i;
        for(int rep=0;rep<B;++rep) jmp[i]=p[jmp[i]];
    }
    while(q--) {
        int t; cin >> t;
        if(t==2) {
            int i,k; cin >> i >> k,--i;
            while(k>B) {
                i=jmp[i], k-=B;
            }
            while(k) i=p[i],--k;
            cout << i+1 << '\n';
        } else {
            int x,y; cin >> x >> y,--x,--y;
            swap(p[x],p[y]);
            swap(ip[p[x]],ip[p[y]]);
            // link from x -> p[x] changed.
            // link from y -> p[y] changed.
            auto recalc = [&](int a) {
                jmp[a]=a;
                for(int rep=0;rep<B;++rep) jmp[a] = p[jmp[a]];
                for(int i=0;i<B-1;++i) {
                    a=ip[a];
                    jmp[a] = ip[jmp[p[a]]];
                }
            };
            recalc(x);
            recalc(y);
        }
    }

}