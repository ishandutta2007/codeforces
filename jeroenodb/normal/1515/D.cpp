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
        int n,l,r; cin >> n >> l >> r;
        vi left(n), right(n);
        // first make l and r have equal numbers of socks
        for(int i=0;i<l;++i) {
            int a; cin >> a;
            left[a-1]++;
        } 
        for(int i=0;i<r;++i) {
            int a; cin >> a;
            right[a-1]++;
        } 
        for(int i=0;i<n;++i) {
            while(left[i] and right[i]) {
                left[i]--; right[i]--;
            }
        }
        if(l<r) {
            swap(l,r);
            swap(left,right);
        }
        int got = l-r;
        int ans = 0;
        for(int i=0;i<n and got;++i) {
            while(got and left[i]>=2) {
                left[i]-=2;
                got-=2;
                ans++;
            }
        }
        ans+=accumulate(all(left),0);
        cout << ans << '\n';
    }   
}