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
        set<int> s;
        int a,b; cin >> a >> b;
        int n = a+b;
        for(int rep=0;rep<2;++rep) {
            for(int abr=0;abr<=min((n+1)/2,b);++abr) {
                int bh = b-abr;
                int bbreak = n/2-bh;
                int ah = a-bbreak;
                if(bbreak>=0 and ah>=0 and ah+bbreak == a) {
                    s.insert(bbreak+abr);
                }
            }
            swap(a,b);
        }
        cout << s.size() << '\n' << s << '\n';

    }
}