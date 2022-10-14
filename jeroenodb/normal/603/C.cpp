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
map<int,int> mp;
int k;
int solve(int a) {
    if(mp.count(a)) return mp[a];
    vi have;
    if(a%2==0 and a>0) {
        if(k%2==0) {
            have.push_back(0);
        } else have.push_back(solve(a/2));
    }
    if(a>0) have.push_back(solve(a-1));
    for(int i=0;;++i) {
        if(count(all(have),i)==0) {
            return mp[a]=i;
        }
    }
}
int main() {
    int n; cin >> n >> k;
    vi a(n); for(auto& i : a) cin >> i;
    int ans = 0;
    // solve(100);
    // for(auto [i,j] : mp) {
    //     cout << j << ' ';
    // }
    for(int i=0;i<n;++i) {
        int cur = 0, b = a[i];
        if(b<100) cur=solve(b);
        else if(k%2==0) {
            if(b<=2) cur=b;
            else cur=!(b%2);
        } else {
            if(b==0 or b==2 or (b>=5 and b%2==1)) {
                cur=0;
            } else {
                int times=0;
                while(b%2==0) {
                    b/=2;
                    times++;
                }
                if((b==3 and times%2==0) or (b!=1 and times%2==1)) {
                    cur=1;
                } else {

                    cur=2;
                }
            }
        }
        ans^=cur;
    }
    cout << (ans==0?"Nicky\n":"Kevin\n");
}