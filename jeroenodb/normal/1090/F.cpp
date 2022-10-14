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
    // find minimum
    // (1,2,3), ... (1,2,n) minimum from this? max(c,a_i)+min(c,a_i), this is monotonic
    // Have 3 candidates. Pick 2 others. Then pick minimum out of those
    // find second minimum, in same way  ~2n queries now
    // But now maybe have 1 left! What about querying pairs + 1 other? Then two maxima maxima are wrong!
    // now can find values of all in the form  min(a_i) + a_i. Vraag er dan 3, dan krijg je 2*x + a_i + a_(i+2).
    // Then find the last two values
    vi p(n); iota(all(p),1);
    map<vi,ll> mp;
    auto query = [&](int i, int j, int k) {
        vi res = {p[i],p[j],p[k]};
        sort(all(res));
        if(mp.count(res)) return mp[res];
        cout << "? " <<  res << endl;
        ll a;
        cin >> a;
        return mp[res] = a;
    };
    if(true) {
        // a_1 + a_3 + a_2 + a_4 + a_1 + a_4 + a_1 + a_4
        // (a_1 + a_3)  2*(a_1 + a_4)   (a_2  + a_4)
        vector<ll> a(n);
        for(int j=0;j<n;j+=5) {
            j = min(j,n-5);
            ll total=0;
            int pp[5];
            iota(pp,pp+5,j);
            auto get4 = [&](int no) {
                int got[4] = {};
                ll mn = 1e18, mx = -1e18;
                for(int i=0;i<4;++i) got[i]=pp[(no+i+1)%5];
                for(int i=0;i<4;++i) {
                    auto tmp = query(got[i],got[(i+1)%4],got[(i+2)%4]);
                    mx = max(mx,tmp);
                    mn = min(mn,tmp);
                }
                return mn+mx;
            };
            for(int i=0;i<5;++i) a[j+i]=get4(i), total+=a[j+i];
            total/=4;
            for(auto i : pp) a[i]=total-a[i];
        }
        cout << "! " << a << endl;
        exit(0);
    }
    auto findmin = [&]() {
        cerr << p << endl;
        int m = p.size();
        pair<ll,ll> best = {1e18,1e18};
        for(int i=2;i<m;++i) {
            best = min(best,{query(0,1,i),i});
        }
        // three candidates
        ll a[3] = {};
        swap(p[best.second],p[2]);
        for(int i=0;i<3;++i) a[i] = query(i,3,4);
        swap(p[min_element(a,a+3)-a],p[0]);
    };
    findmin();
    int mn = p[0];
    p.erase(p.begin());
    findmin();
    p.insert(p.begin(),mn);
    vector<ll> res(n);
    for(int i=2;i<n;++i) {
        res[i] = query(0,1,i);
    }
    // max(a_2,a_3,a_4) + min(a_2,a_3,a_4) + 2*mn
    ll sm = *max_element(res.begin()+2,res.begin()+5) + *min_element(res.begin()+2,res.begin()+5) - query(2,3,4);
    sm/=2;
    res[0] = sm;
    for(int i=2;i<n;++i) res[i]-=sm;
    res[1] = query(1,2,3)-max(res[2],res[3]);
    vector<ll> ans(n);
    for(int i=0;i<n;++i) ans[p[i]-1]=res[i];
    cout << "! " << ans << endl;

}