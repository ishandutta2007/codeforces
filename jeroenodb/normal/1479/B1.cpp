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
    int n; cin >> n;
    vi a(n); for(int& i: a) cin >> i;
    a.push_back(0);
    int ans = 0;
    int last = a[0], cnt = 1;
    int b=-1,c=-1;
    for(int i=1;i<=n;++i) {
        if(a[i]==last) {
            cnt++;
        } else {
            if(cnt>1) {
                if(last!=b) {
                    ans++;
                    b=last;
                }
                if(last!=c) {
                    ans++;
                    c=last;
                }
            } else {
                if(c==a[i]) {
                    swap(b,c);
                }
                if(last!=b) {
                    ans++;
                    b=last;
                } else if(last!=c) {
                    ans++;
                    c = last;
                }
            }
            last = a[i];
            cnt=1;
        }
    }
    cout << ans << endl;
}