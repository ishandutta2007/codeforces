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
struct hero {
    int p,h,id;
};
int main() {
    int n,m; cin >> n >> m;
    vector<hero> hsv(m);
    {
    int id=0;
    for(auto& h : hsv) cin >> h.p >> h.h,h.p--, h.id = id++;
    }
    vi a(n); for(auto& i : a) cin >> i;


    vi l(m), r(m);
    { // precalculate how far heros can move left/right
        auto it = hsv.begin();
        for(int i=0;i<m;++i) {
            int curh = it->h;
            l[i]=r[i]=it->p;
            while(l[i]>0 and curh+a[l[i]-1]>=0) {
                l[i]--;
                curh+=a[l[i]];
            }
            curh = it->h;
            while(r[i]<n-1 and curh+a[r[i]+1]>=0 ) {
                r[i]++;
                curh+=a[r[i]];
            }
            ++it;
        }
    }
    for(int to=0;to<n;++to) {
        // rally position is to
        vi res;
        list<hero> hs(all(hsv));
        int lo = to+1, hi = to-1;
        while(!hs.empty()) {
            int prevs = hs.size();
            for(auto it = hs.begin();it!=hs.end();) {
                auto it2 = next(it);
                auto good = [&]() {
                    res.push_back(it->id+1);
                    hs.erase(it);
                };
                if(it->p <lo) {
                    if(r[it->id]>=lo-1) {
                        lo = it->p;
                        hi = max(hi,to);
                        good();
                    }
                } else if(it->p > hi) {
                    if(l[it->id]<=hi+1) {
                        hi = it->p;
                        lo = min(lo,to);
                        good();
                    }
                } else {
                    good();
                }
                it=it2;
            }
            if((int)hs.size()==prevs) 
                break;
        }
        if(hs.empty()) {
            cout << to+1 << '\n';
            cout << res << '\n';
            exit(0);
        }
    }
    cout << "-1\n";
}