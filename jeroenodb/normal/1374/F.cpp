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
void solve() {
    int n; cin >> n;
    vi a(n); for(auto& i : a) cin >> i;
    vi ans;
    auto doOp = [&](int i) {
        ans.push_back(i+1);
        rotate(a.begin()+i,a.begin()+i+2,a.begin()+i+3);
    };
    int inversions=0;
    for(int i=0;i<n;++i) {
        for(int j=i+1;j<n;++j) {
            if(a[i]>a[j]) inversions++;
        }
    }
    vi b = a; sort(all(b));
    map<int,vi> mp;
    for(int i=0;i<n;++i) mp[a[i]].push_back(i);
    if(inversions%2==1) {
        for(auto& [i,v] : mp) {
            if(v.size()>1) {
                swap(v[0],v[1]);
                break;
            }
        }
    }
    int rnk=0;
    for(auto& [i,v] : mp) {
        for(auto j : v) {
            a[j]=rnk++;
        }
    }
    
    for(int i=0;i<n;++i) {
        int j = find(a.begin()+i,a.end(),i)-a.begin();
        while(j-i>=2) {
            j-=2;
            doOp(j);
        }
        if(j-i==1 and i+2<n) 
            doOp(i),doOp(i);
    }
    if(!is_sorted(all(a)) or ans.size()>n*n) {
        cout << "-1\n";
    } else {
        cout << ans.size() << '\n';
        cout << ans << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}