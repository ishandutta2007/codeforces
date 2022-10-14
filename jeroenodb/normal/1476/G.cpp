#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
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
const int N = 1e5+1, oo = 1e9;
// Mo's algorithm with updates
int B;
struct query {
    int l,r,k,t,id; 
    tuple<int,int,int> comp() const {
        return {l/B, r/B, t};
    }
    bool operator< (const query& o) {
        return comp() < o.comp();
    }
};
struct Change {
    int p,to,from;
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    vi a(n); for(int& i: a) cin >> i;
    vector<query> qs;
    vector<Change> changes;
    for(int i=0;i<m;++i) {
        int t; cin >> t;
        if(t==1) {
            query q;
            cin >> q.l >> q.r >> q.k;
            q.l--,q.r--;
            q.t = changes.size();
            q.id = qs.size();
            qs.push_back(q);
        } else {
            int p,x; cin >> p >> x; --p;
            changes.push_back({p,x,a[p]});
            a[p] = x;
        }
    }
    B = max(1.,(0.5+(double)2*changes.size()/m)*pow(((ll)2*n*n),1./3) );
    debug(B);
    sort(all(qs));
    int cnt[N]={}, cntcnt[N]={};
    cntcnt[0] = N;
    vi candidates; candidates.reserve(n);
    int l=qs[0].l, r = qs[0].l-1, t = changes.size();
    // Closed interval [l,r] [a,a-1] means empty interval
    bitset<N> present;
    auto add = [&](int b) {
        cntcnt[cnt[b]]--;
        int tmp = ++cnt[b];
        cntcnt[tmp]++;
        if(tmp and !present[tmp]) {
            candidates.push_back(tmp);
            present[tmp]= true;
        }
    };
    auto remove = [&](int b) {
        cntcnt[cnt[b]]--;
        int tmp = --cnt[b];
        cntcnt[tmp]++;
        if(tmp and !present[tmp]) {
            candidates.push_back(tmp);
            present[tmp] = true;
        }

    };
    auto in = [&](int b) {
        return l<=b and b<=r;
    };
    vi ans(qs.size(),-1);
    // debug(a);
    for(auto& q : qs) {
        while(t>q.t) {
            auto& c = changes[--t];
            if(in(c.p)) {
                remove(c.to);
                add(c.from);
            }
            a[c.p] = c.from;
            // debug(a);
        }
        while(t<q.t) {
            auto& c = changes[t++];
            if(in(c.p)) {
                remove(c.from);
                add(c.to);
            }
            a[c.p] = c.to;
        }
        while(r<q.r) {
            add(a[++r]);
        }
        while(l>q.l) {
            add(a[--l]);
        }
        while(r>q.r) {
            remove(a[r--]);
        }
        while(l<q.l) {
            remove(a[l++]);
        }
        // Answer query
        for(int j=0;j<(int)candidates.size();++j) {
            int i = candidates[j];
            assert(cntcnt[i]>=0);
            if(cntcnt[i]==0) {
                present[i] = false;
                candidates[j] = candidates.back();
                candidates.pop_back();
                --j;
            }

        }
        sort(all(candidates));
        int myans = oo;
        int k = candidates.size();
        int sm = 0;
        for(int i=0,j=0;i<k;++i) {
            while(j<k and sm<q.k) {
                sm+=cntcnt[candidates[j++]];
            }
            if(sm<q.k) break;
            myans = min(myans,candidates[j-1]-candidates[i]);
            sm-=cntcnt[candidates[i]];
        }
        ans[q.id] = (myans==oo?-1:myans);
    }
    for(int i: ans) {
        cout << i << '\n';
    }



}