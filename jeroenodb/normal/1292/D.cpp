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
const int mxN = 1e5+1;
const ll oo = 1e18;
const int store=5000 + 1;
bitset<store> sieve={};
int fact[store] = {};
int id[store] = {};
template<typename T> struct fenwick {
    int n;
    vector<T> fen;
    fenwick(){}
    fenwick(int nn) {
        fen.resize(nn+1);
        n = nn;
    }
    auto sum(int i) {
        T ans = 0;
        while(i) {
            ans+=fen[i];
            i&=i-1;
        }
        return ans;
    }
    auto query(int l, int r) {
        return sum(r+1)-sum(l);
    }
    void update(int i, T val) {
        ++i;
        while(i<=n) {
            fen[i]+=val;
            i+= i&(-i);
        }
    }
};
int makesieve() {
    int cnt=0;
    for(int i = 2; i < store;++i) if(!sieve[i]) {
        id[i]=cnt++;
        for(int j = i;j<store;j+=i) {
            if(!sieve[j]) {
                fact[j]=i;
                sieve[j]=true;
            }
        }
    }
    return cnt;
}

struct DP {
    int sz=0;
    ll dist=0;
    friend DP up(DP dp, int dif) {
        dp.dist+=(ll)dif*dp.sz;
        return dp;
    }
    friend DP merge(DP a, const DP& b) {
        a.sz+=b.sz;
        a.dist+=b.dist;
        return a;
    }
};
ll ans = oo;
struct node {
    int d=0;
    vector<node*> to;
    node* par= NULL;
    DP dp = {};
    DP dfs() {
        for(auto t : to) if(t->par==this) {
            dp = merge(dp,t->dfs());
        }
        if(par) dp = up(dp,d-par->d);
        return dp;
    }
    void dfs2() {
        if(par) {
            DP cur = par->dp;
            cur.sz-=dp.sz;
            cur.dist-=dp.dist;
            cur = up(cur,d-par->d);
            dp = merge(up(dp, par->d-d),cur);
        }
        ans = min(ans,dp.dist);
        for(auto t : to) if(t->par==this) {
            t->dfs2();
        }
    }
};
node mem[2*store+100];
int pp=0;
node* newnode(const node& nd) {
    return &(mem[pp++]=nd);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fenwick<int> fen(makesieve()+3);
    node *rt = newnode(node{});
    vector<node*> facts = {rt, rt};
    for(int i=2;i<store;++i) {
        vector<pi> primes;
        for(int j=i;j>1;) {
            int f = fact[j],tmp=0;
            do {
                tmp++;
                j/=f;
            } while(fact[j]==f);
            primes.push_back({id[f], tmp});
        }
        int d = fen.query(primes.back().first, fen.n-1); // depth of LCA
        for(auto [j,cnt]:primes) fen.update(j,cnt);
        node* at = facts.back(), *prv=NULL;
        while(at->d>d) {
            prv = at;
            at = at->par;
        } // amortized O(1)
        if(at->d<d) {
            auto split = newnode(node{d});
            prv->par=split;
            split->to.push_back(prv);
            at->to.push_back(split);
            split->par = at;
            at = split;
        }
        auto nw = newnode(node{fen.query(0,fen.n-1)});
        nw->par=at;
        at->to.push_back(nw);
        facts.push_back(nw);
    }
    int n; cin >> n;
    for(int i=0;i<n;++i) {
        int k; cin >> k;
        facts[k]->dp.sz++;
    }
    // find place with minimal sum to others
    // Solve for all roots Tree DP.
    rt->dfs();
    rt->dfs2();
    cout << ans << '\n';
}