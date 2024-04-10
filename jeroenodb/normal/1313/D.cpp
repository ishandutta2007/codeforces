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
void cmax(int& a, int b) {a=max(a,b);}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k; cin >> n >> m >> k;
    vi xs;
    vector<pi> ivs(n);
    for(auto& [l,r] : ivs) {
        cin >> l >> r, ++r;
        xs.push_back(l);
        xs.push_back(r);
    }
    sort(all(xs));
    xs.erase(unique(all(xs)),xs.end());
    int d = xs.size();
    auto real = [&](int i) {
        return lower_bound(all(xs),i)-xs.begin();
    };
    vvi ids(d);
    {
        int id=0;
        for(auto& [l,r] : ivs) {
            l=real(l),r=real(r);
            for(int i=l;i<r;++i) {
                ids[i].push_back(id);
            }
            ++id;
        }
    }
    // dynamic programming?
    array<int,8> where,nwhere;
    vi dp(1,0);
    fill(all(where),-1);
    for(int i=0;i<d-1;++i) {
        int w = xs[i+1]-xs[i];
        int cover = ids[i].size();;
        int masks = 1<<cover;
        bool good[8] = {};
        fill(all(nwhere),-1);
        for(int j=0;j<cover;++j) {
            auto it = find(all(ids[i+1]),ids[i][j]);
            if(it!=ids[i+1].end()) {
                nwhere[it-ids[i+1].begin()]=j;
                good[j]=true;
            }
        }
        vi ndp(masks,-oo);
        for(int ma=0;ma<masks;++ma) {
            int prema=0,toma=0;
            bool flip=false;
            for(int j=0;j<cover;++j) {
                if(ma&(1<<j)) {
                    if(where[j]!=-1) prema^=1<<where[j];
                    if(good[j]) toma^=1<<j;
                    flip=!flip;
                }
            }
            cmax(ndp[toma],dp[prema]+flip*w);
        }
        where=nwhere;
        dp = move(ndp);
    }
    cout << *max_element(all(dp));

    
    

}