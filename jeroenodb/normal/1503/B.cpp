#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << p.first << " " << p.second; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1, oo = 1e9;
int main() {
    int n; cin >> n;
    vector<pi> a[2];
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;++j) {
            a[(i+j)%2].push_back({i,j});
        }
    }
    for(int i=0;i<n*n;++i) {
        int c; cin >> c;
        if(c!=3) {
            if(!a[0].empty()) {
                cout << 3 << ' ' << a[0].back() << endl;
                a[0].pop_back();
            } else {
                int o = 2;
                if(o==c) o=1;
                cout << o << ' ' << a[1].back() << endl;
                a[1].pop_back();
            }
        } else {
            if(!a[1].empty()) {
                cout << 1 << ' ' << a[1].back() << endl;
                a[1].pop_back();
            } else {
                cout << 2 << ' ' << a[0].back() << endl;
                a[0].pop_back();
            }
        }
    }
}