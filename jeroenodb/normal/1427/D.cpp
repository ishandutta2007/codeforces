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
    vi c(n); for(auto& i : c) cin >> i,--i;
    // find a pair to join
    vvi res;
    while(!is_sorted(all(c))) {
        vi groups;
        map<int,int> seen;
        int a=-1,b=-1,d=-1;
        for(int i=0;i<n;++i) {
            if(seen.count(c[i]+1)) {
                a = seen[c[i]+1];
                b=a+1;
                while(c[b]-c[b-1]==1) b++;
                d = i;
                break;
            }
            seen[c[i]]=i;
        }
        assert(a!=-1);
        if(a!=0) {
            groups.push_back(a);
        }
        groups.push_back(b-a);
        groups.push_back(d-b+1);
        if(d!=n-1) groups.push_back(n-1-d);
        res.push_back(groups);
        // now swap all
        vi g;
        vi cur;
        for(int i=n-1;i>=0;--i) {
            cur.push_back(c[i]);
            if(cur.size()==groups.back()) {
                reverse(all(cur));
                g.insert(g.end(),all(cur));
                groups.pop_back();
                cur = {};
            }
        }
        c = g;
    }
    cout << res.size() << '\n';
    for(auto i : res) {
        cout << i.size() << ' ' << i << '\n';
    }
}