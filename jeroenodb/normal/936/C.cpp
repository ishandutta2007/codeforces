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
    string s,t; cin >> s >> t;
    for(char c='a';c<='z';++c) {
        if(count(all(s),c)!=count(all(t),c)) {
            cout << "-1\n";
            exit(0);
        }
    }
    vi perm(n);
    for(int i=0;i<n;++i) {
        auto c = s[i];
        int j = t.find(c);
        perm[i]=j;
        t[j]='#';
    }
    vi ans;
    auto domove = [&](int x) {
        ans.push_back(n-x);
        reverse(perm.begin()+x,perm.end());
        rotate(perm.begin(), perm.begin()+x,perm.end());
    };
    for(int i=n-1;i>=0;--i) {
        auto k = find(all(perm),i)-perm.begin();
        domove(k+1);
        domove(n-1);
        domove(0);
    }
    domove(0);
    for(int i=0;i<n;++i) 
        assert(perm[i]==i);
    cout << ans.size() << '\n' << ans << '\n';
}