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
        string s; cin >> s;
        s.push_back('#');
        int n = s.size();
        int lo=0,hi=n;
        vi p(n+1);
        for(int i=1;i<=n;++i) p[i]=p[i-1]+(s[i-1]=='1');
        auto good = [&](int b) {
            int cnt=0;
            for(int i=0,j=0;i<=n;++i) {
                while(j<=n and cnt<=b) {
                    cnt+=s[j++]=='0';
                }
                if(p[i]+p[n]-p[j-1]<=b) return true;
                cnt-=s[i]=='0';
            }
            return false;
        };
        while(lo<hi) {
            int mid = (lo+hi)/2;
            if(good(mid)) {
                hi = mid;
            } else lo = mid+1;
        }
        cout << lo << '\n';
    }
}