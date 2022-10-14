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
    while(t--) {
        int n,k; cin >> n >> k;
        vi h(n); for(int& i:h) {
            cin >> i;
        }
        // Test if impossible
        int mxh = h.back();
        int total = 0;
        for(int i=n-2;i>=0;--i) {
            if(h[i]>mxh) {
                mxh = h[i];
            } else {
                total+=mxh-h[i];
            }
        }
        if(total<k) {
            cout << "-1\n";
        } else {
            // Simulate process
            int j;
            for(int i=0;i<k;++i) {
                j=0;
                while(h[j]>=h[j+1]) {
                    j++;
                }
                h[j]++;
            }
            cout << j+1 << endl;
        }
    }
}