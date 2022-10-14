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
    vi gaps;
    {
        int g=0;
        for(int i=0;i<n;++i) {
            int a;
            cin >> a;
            gaps.push_back(a-g);
            g=a;
        }
    }
    ll m; cin >> m;
    ll lo=1,hi = 1e18;
    auto cost = [](int dif, int k) {
        ++k;
        k = min(k,dif);
        ll x = dif/k;
        ll num = dif%k;
        return num*(x+1)*(x+1) + x*x*(k-num);
    };
    auto g = [&cost](int dif, ll la) {
        int lo=0, hi = dif-1;
        while(lo<hi) {
            int mid = (lo+hi)/2;
            if(cost(dif,mid)-cost(dif,mid+1)>=la) {
                lo = mid+1;
            } else {
                hi = mid;
            }
        }
        int r=lo;
        lo=0,hi=dif-1;
        while(lo<hi) {
            int mid = (lo+hi)/2;
            if(cost(dif,mid)-cost(dif,mid+1)>la) {
                lo = mid+1;
            } else {
                hi = mid;
            }
        }
        return make_tuple(cost(dif,r),r,r-lo);
    };
    auto f = [&](ll mid) {
        int cnt=0,f=0;
        ll c=0;
        for(auto d : gaps) {
            auto [myc, mycnt,fr] = g(d,mid);
            c+=myc;
            cnt+=mycnt;
            f+=fr;
        }
        return make_tuple(c,cnt,f);
    };
    ll best = 1e18;
    while(lo<hi) {

        auto mid  = (lo+hi+1)/2;
        auto [c,cnt,fr] = f(mid);
        if(c<=m) {
            best = min(best,cnt - min((ll)fr,(m-c)/mid));
            lo = mid;
        } else {
            hi = mid-1;
        }
        
    }
    auto mid  = lo;
    auto [c,cnt,fr] = f(mid);
    if(c<=m) {
        best = min(best,cnt - min((ll)fr,(m-c)/mid));
        lo = mid;
    }
    cout << best << '\n';
}