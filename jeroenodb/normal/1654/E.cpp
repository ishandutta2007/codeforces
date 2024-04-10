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

const int B = 370;
const int MX = 100000/B;
int cnt[mxN*(B+10)];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vi a(n);
    for(auto& i : a) cin >> i;

    int ans=1;
    for(int slope=-B;slope<=B;++slope) {
        int pref=max(0,slope*n);
        vi used;
        for(auto i : a) {
            ans=max(++cnt[i+pref],ans);
            if(cnt[i+pref]==1) used.push_back(i+pref);
            pref-=slope;
        }
        for(auto i : used) cnt[i]=0;
    }
    
    for(int i=0;i<n;++i) {
        int r = min(n-1,i+MX);
        vi used;
        for(int j=i+1;j<=r;++j) {
            array<int,2> slope = {a[j]-a[i],j-i};
            if(slope[0]%slope[1]==0) {
                slope[0]/=slope[1];
                if(abs(slope[0])<=B) continue;
                auto tmp = ++cnt[slope[0]+mxN];
                ans = max(ans,1+tmp);
                if(tmp==1) {
                    used.push_back(slope[0]+mxN);
                }
            }
        }
        for(auto i : used) cnt[i]=0;
        
    }
    cout << n-ans << '\n';
}