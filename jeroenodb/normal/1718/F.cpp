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
const int store=1e5 + 1;
bitset<store> sieve={};
int factor[store] = {};
int pcnt[store] = {};
int cnt[store] = {};
int total=0;
void makesieve() {
    for(int i = 2; i < store;++i) {
        if(!sieve[i]) {
            for(int j = i;j<store;j+=i) {
                if(!sieve[j]) {
                    factor[j] = i;
                    sieve[j] = true;
                }
            }
        }
    }
}
const int B = 70;
int main() {
    int n,m,c,q; cin >> n >> m >> c >> q;
    struct Query {
        int l,r,id;
        bool operator<(const Query& o) const {
            if(l/B!=o.l/B) return l/B<o.l/B;
            return r<o.r;
        }
    };
    makesieve();
    vvi myp(n);
    for(int i=0;i<n;++i) {
        int a; cin >> a;
        while(a>1) {
            int f = factor[a];
            while(a%f==0) a/=f;
            myp[i].push_back(f);

        }
    }
    vector<Query> qs(q);
    for(int i=0;i<q;++i) {
        auto& Q = qs[i];
        cin >> Q.l >> Q.r;
        Q.id = i;
        Q.l--,Q.r--;
    }
    sort(all(qs));
    auto change = [&](int p, int sgn) {
        pcnt[p]+=sgn;
        if(pcnt[p]==1 and sgn==1) {
            for(int j=p;j<=c;j+=p) {
                total+=!cnt[j];
                cnt[j]++;
            }
        } else if(pcnt[p]==0) {
            for(int j=p;j<=c;j+=p) {
                total-=cnt[j]==1;
                cnt[j]--;
            }
        }
    };
    auto add = [&](int i, int sgn=1) {
        for(auto p : myp[i]) {
            change(p,sgn);
        }
    };
    int l=0,r=-1;
    vi ans(q);
    for(auto Q : qs) {
        while(r<Q.r) add(++r);
        while(l>Q.l) add(--l);
        while(l<Q.l) add(l++,-1);
        while(r>Q.r) add(r--,-1);
        ans[Q.id] = c-total;
    }
    for(auto i : ans) cout << i << '\n';
}