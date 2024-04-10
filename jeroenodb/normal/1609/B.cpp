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
    string s; cin >> s;
    vector<bool> bad(n);
    int ans=0;
    auto check = [&](int i) {
        if(i+2>=n or i<0) return;
        auto tmp = s.substr(i,3)=="abc";
        ans+=tmp-bad[i];
        bad[i]=tmp;
    };
    for(int i=0;i<n-2;++i) check(i);
    while(q--) {
        int i; char c; cin >> i >> c,--i;
        s[i]=c;
        check(i-2), check(i-1), check(i);
        cout << ans << '\n';
    }
}