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

    int n,q; cin >>n >> q;
    int zeros = 0;
    vi a(n); for(int& i: a) {
        cin >> i;
        if(i==0) zeros++;
    }
    while(q--) {
        int t; cin >> t;
        int k; cin >> k; --k;
        if(t==1) {

            if(a[k]==0) {
                a[k]=1;
                zeros--;
            } else {
                a[k]=0;
                zeros++;
            }
        } else {
            cout << (k+1>n-zeros?0:1) << '\n';
        }
    }
}