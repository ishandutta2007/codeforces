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
const int B=330;
struct query {
    int l,r,id;
    bool operator<(const query& o) const {
        if(l/B!=o.l/B) return l<o.l;
        if(l/B%2 == 0) return r<o.r;
        return r>o.r;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k; cin >> n >> k;
    vi cnt(n+2);
    vector<array<int,3>> crd(n+2);

    {
        // calculate coord compressed values for pref[i]-k, pref[i], and pref[i]+k, for each i
        vi ts(n); for(auto& i : ts) cin >> i;
        vector<ll> pref(n+1);
        for(int i=1;i<=n;++i) {
            int a; cin >> a;
            if(ts[i-1]==2) a=-a;
            pref[i]=pref[i-1]+a; 
        }
        vector<ll> prefsorted=pref;
        sort(all(prefsorted));
        // prefsorted.erase(unique(all(prefsorted)),prefsorted.end());
        auto get = [&](ll want) {
            int res = lower_bound(all(prefsorted),want)-prefsorted.begin();
            if(res==(int)prefsorted.size() or prefsorted[res]!=want) return n+1;
            return res;
        };
        for(int i=0;i<=n;++i) {
            crd[i] = {get(pref[i]-k),get(pref[i]),get(pref[i]+k)};
            for(auto j : crd[i]) assert(0<=j and j<=n+1);
        }
    }
    int Q; cin >> Q;
    vector<query> qs(Q);
    {
        int id=0;
        for(auto& q : qs) {
            cin >> q.l >> q.r;
            q.l--,q.r++; // [ ) intervals
            q.id=id++;
        }
    }
    sort(all(qs));
    int l=0,r =0; // [ ) intervals
    ll ans=0;
    auto add = [&](int i, int a) {
        ans+=cnt[crd[i][a]];
        cnt[crd[i][1]]++;        
    };
    auto remove = [&](int i, int a) {
        cnt[crd[i][1]]--;
        ans-=cnt[crd[i][a]];  
    };
    vector<ll> res(Q);
    for(auto& q : qs) {
        while(r<q.r) add(r++,0);
        while(l>q.l) add(--l,2);
        while(r>q.r) remove(--r,0);
        while(l<q.l) remove(l++,2);
        res[q.id]=ans;
    }
    for(auto i : res) {
        cout << i << '\n';
    }

}