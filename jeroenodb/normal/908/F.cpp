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
const string rgb = "RGB";
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<pair<int,char>> a(n);
    bool gotgreen=false;
    for(auto& [p,c]:a) {
        cin >> p >> c;
        c= rgb.find(c);
        gotgreen|=c==1;
    }
    // calculate span of colors
    int mn[3] = {oo,oo,oo},mx[3] = {-oo,-oo,-oo};
    for(auto& [p,c]:a) {
        mn[c]=min(mn[c],p);
        mx[c]=max(mx[c],p);
    }
    if(!gotgreen) {
        cout << max(0,mx[0]-mn[0])+max(0,mx[2]-mn[2]) << '\n';
        exit(0);
    }
    int prv[3] = {-1,-1,-1};
    int mxl[3] = {0,0,0};
    ll ans = 0;
    for(int i=0;i<n;++i) {
        auto [p,c] = a[i];
        if(c==1) {
            // Green
            mxl[0] = max(mxl[0],p-prv[0]);
            mxl[2] = max(mxl[2],p-prv[2]);
            if(prv[1]==-1) {
                ans+=max(0,p-mn[0])+max(0,p-mn[2]);
            } else {
                ll l =(p-prv[1]);
                ans+=min(2*l,3*l-mxl[0]-mxl[2]);;
            }
            prv[0]=prv[1]=prv[2]=p;
            mxl[0]=mxl[1]=mxl[2]= 0;
        } else {
            mxl[c] = max(mxl[c],p-prv[c]);
            prv[c]=p;
        }
    }
    if(a[n-1].second!=1) {
        ans+=max(0,mx[0]-prv[1])+max(0,mx[2]-prv[1]);
    }
    cout << ans << '\n';
    
}