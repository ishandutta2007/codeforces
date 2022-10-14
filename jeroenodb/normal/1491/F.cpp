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
const int mxN = 3000+1, oo = 1e9;
int qleft;
int test(vi a, vi b) {
    qleft--;
    assert(qleft>=0);
    cout << "? " << a.size() << ' ' << b.size() << '\n';
    for(int& i: a) ++i;
    for(int& i: b) ++i;
    cout << a << '\n';
    cout << b << endl;
    int f; cin >> f;
    return f;
}
// checks if range contains more than 1 charged element
vi notans;
void findone(int l, int r, vi charged, bool definite=true) {
    int lll = l;
    r+=!definite;
    int rrr = r;
    while(l<r) {
        int mid = (l+r)/2;
        // alles van 0:mid
        vi tmp;
        for(int i=lll;i<=mid;++i) {
            tmp.push_back(i);
        }
        if(test(tmp,charged)) {
            r = mid;
        } else {
            l=mid+1;
        }
    }
    if(definite or (rrr!=l)) notans.push_back(l);
}

int main() {
    int t; cin >> t;
    while(t--) {

        int n; cin >> n;
        while((1<<(qleft+1))<=n) qleft++;
        qleft+=n;
        notans.clear();
        vi prefix = {0};
        int charged=-1;
        for(int i=1;i<n;++i) {
            if(test(prefix,{i})) {
                charged = i;
                notans.push_back(i);
                break;
            }
            prefix.push_back(i);
        }
        findone(0,charged-1,{charged});
        vi ans;
        set<int> magneten(all(notans));
        for(int i=0;i<=charged;++i) {
            if(!magneten.count(i)) ans.push_back(i+1);
        }
        for(int i=charged+1;i<n;++i) {
            if((ans.size()==0 and i==n-1) or !test({charged}, {i})) ans.push_back(i+1);
        }
        cout << "! " << ans.size() << ' ' << ans << endl; 

    }
}