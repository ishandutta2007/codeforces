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
    int t; cin >> t;
    int a[100][100];
    while(t--) {
        int n,m; cin >> n >> m;
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                cin >> a[i][j];
                if(a[i][j]%2==(i+j)%2) {
                    a[i][j]++;
                }
            }
        }
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                cout << a[i][j] << ' ';
            } cout << '\n';
        }
    }
}