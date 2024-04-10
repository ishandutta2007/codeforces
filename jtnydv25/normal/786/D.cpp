#include <bits/stdc++.h>
using namespace std;
#define int int
#define sd(x) scanf("%d", &(x))
#define vi vector<int>
#define pb push_back
#define F first
#define S second
int mod;
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline int powr(int a, int b){
    int x = 1 % mod;
    while(b){
        if(b & 1) x = mul(x, a);
        a = mul(a, a);
        b >>= 1;
    }
    return x;
}
inline int inv(int a){ return powr(a, mod - 2);}
int const logN = 20, N = 2e4 + 10;

int POW1[N], INVPOW1[N];

struct Hash {
    int h;
    int len;
};

bool operator == (Hash const & a, Hash const & b) {
    return a.len == b.len && a.h == b.h;
}

int add1(int h1, int h2, int len2) {
    return add(h2, mul(h1, POW1[len2]));
}

Hash operator+ (Hash const & a, Hash const & b) {
    return {add1(a.h, b.h, b.len), a.len + b.len};
}

std::mt19937 rnd(std::chrono::system_clock::now().time_since_epoch().count());
  
int const HALFBILLION = 500000000;

bool prime(int x){
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

void gen(int & M) {
  M = 900000000 + rnd() % 100000000;//rnd() % HALFBILLION + HALFBILLION;
  while (!prime(M)){
      ++M;
  }
}
const int SHIFT = 7;
const int SQN = (1 << SHIFT);
const int mask = SQN - 1;
const int SQN2 = 2 + N / SQN;
int par[logN][N], depth[N], par2[SQN2][N], parent[N], parent2[N], depth2[N], st[N];
Hash up1[SQN][N], up2[SQN2][N], down1[SQN][N], down2[SQN2][N], up[N], down[N], UP[logN][N], DOWN[logN][N];
vector<pair<int, int> > con[N];
void dfs_original(int s, int p, int d){
    par[0][s] = p;
    depth[s] = d;
    for(auto v : con[s]){
        int node = v.F;
        if(node != p){
            Hash H = {v.S, 1};
            down[node] = down[s] + H;
            up[node] = H + up[s];
            DOWN[0][node] = UP[0][node] = H;
            dfs_original(node, s, d + 1);
        }
    }
}
inline int kthancestor(int m, int k){
    for(int i = logN - 1; i >= 0; i--) if(k & (1 << i)) m = par[i][m];
    return m;    
}
inline Hash hash_to_ancestor(int s, int k){
    Hash ret = {0, 0};
    for(int i = logN - 1; i >= 0; i--) if(k & (1 << i)){ ret = ret + UP[i][s], s = par[i][s];}
    return ret;
}
inline Hash hash_from_ancestor(int s, int k){
    Hash ret = {0, 0};
    for(int i = logN - 1; i >= 0; i--) if(k & (1 << i)){ ret = DOWN[i][s] + ret, s = par[i][s];}
    return ret;
}
inline void pre_original(int n){
    for(int j = 1;j<logN;j++)
        for(int i = 1;i<=n;i++){
            par[j][i] = par[j-1][par[j-1][i]];
            UP[j][i] = UP[j - 1][i] + UP[j - 1][par[j - 1][i]];
            DOWN[j][i] = DOWN[j - 1][par[j - 1][i]] + DOWN[j - 1][i];
        }
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        int s = i;
        up1[0][i] = down1[0][i] = {0, 0};
        while(s && cnt + 1 < SQN){
            up1[cnt + 1][i] = up1[cnt][i] + UP[0][s];
            down1[cnt + 1][i] = DOWN[0][s] + down1[cnt][i];
            s = par[0][s]; cnt++;
        }
        up2[0][i] = down2[0][i] = {0, 0}; par2[0][i] = i;
    }    
    for(int i = 1; i <= n; i++) if(depth[i] >= SQN){
        int j = 1;
        up2[j][i] = hash_to_ancestor(i, j * SQN);
        down2[j][i] = hash_from_ancestor(i, j * SQN);
        par2[j][i] = kthancestor(i, j * SQN);
    }
    for(int j = 2; j * SQN < n; j++){
        for(int i = 1; i <= n; i++){
            if(depth[i] < j * SQN) continue;
            int p = par2[j - 1][i];
            up2[j][i] = up2[j - 1][i] + up2[1][p];
            down2[j][i] = down2[1][p] + down2[j - 1][i];
            par2[j][i] = par2[1][p];
        }
    }
}
inline int lca(int a, int b){
    if(depth[a]<depth[b])
        swap(a,b);
    int l = depth[a]-depth[b];
    for(int i = 0;i<logN;i++) if(l&(1<<i)) a = par[i][a];    
    if(a==b) return a;
    for(int i = logN-1;i>=0;i--)
        if(par[i][a]!=par[i][b])
            a = par[i][a],b = par[i][b];
    return par[0][a];
}

inline Hash hash_up(int s, int k){
    int d = k >> SHIFT;
    return up2[d][s] + up1[k & mask][par2[d][s]];
}
inline Hash hash_down(int s, int k){
    int d = k >> SHIFT;
    return down1[k & mask][par2[d][s]] + down2[d][s];   
}
struct str{
    int A, B, L, length;
    Hash HU, HD, H;
    str(int a, int b){
        A = a; B = b; L = lca(a, b);
        int l1 = depth[A] - depth[L], l2 = depth[B] - depth[L];
        length = l1 + l2;
        HU = hash_up(A, l1); HD = hash_down(B, l2);
        H = HU + HD;
    }
};
// get hash of prefix of length len of S
// O(1)
inline Hash get_hash(int len, const str & S){
    int a = S.A, b = S.B, l = S.L;
    int l1 = depth[a] - depth[l], l2 = depth[b] - depth[l];
    if(l1 >= len) return hash_up(a, len);
    len -= l1;
    Hash ret = S.HU;
    Hash X = S.HD, Y = hash_down(b, l2 - len);
    int x = mul(sub(X.h, Y.h), INVPOW1[l2 - len]);
    X = {x, len};
    return ret + X;
}
// Get LCP of two strings on the tree in O(log n)
inline int lcp(const str & X, const str & Y){
    int lo = 0, hi = min(X.length, Y.length);
    while(lo < hi){
        int mid = (lo + hi + 1) >> 1;
        if(get_hash(mid, X) == get_hash(mid, Y)) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}
bool operator < (const str & X, const str & Y){
    // find lcp.
    int LCP = lcp(X, Y);
    if(LCP == Y.length) return 0;
    if(LCP == X.length) return 1;
    Hash h1 = get_hash(LCP + 1, X), h2 = get_hash(LCP, X);
    int x = sub(h1.h, mul(POW1[1], h2.h));
    h1 = get_hash(LCP + 1, Y), h2 = get_hash(LCP, Y);
    int y = sub(h1.h, mul(POW1[1], h2.h));
    assert(x != y);
    return x < y;
}
int const X = 33533;


int tree[N], vis[N], parcen[N];
vector<int> concen[N], con2[N];
vector<str> S1[N], S2[N];
int getSizes(int s, int p){
    tree[s] = 1;
    for(int v : con2[s]) if(v != p && !vis[v]) tree[s] += getSizes(v, s);
    return tree[s];
}

int getcentroid(int s, int p, int n){
    for(int v : con2[s]){
        if(v != p && !vis[v]){
            if(2 * tree[v] > n) return getcentroid(v, s, n);
        }
    }
    return s;
}

int decompose(int s, int p){
    int root = getcentroid(s, p, getSizes(s, p));
    parcen[root] = p;
    if(p > 0) concen[p].pb(root), concen[root].pb(p);
    vis[root] = 1;
    for(int v : con2[root]){
        if(!vis[v]) decompose(v, root);
    }
    return root;
}
// get kth node on path from a to b
int get_node(int a, int b, int k){
    int l = lca(a, b);
    int d1 = depth[a] - depth[l], d2 = depth[b] - depth[l];
    if(d1 >= k) return kthancestor(a, k);
    else return kthancestor(b, d2 - (k - d1));
}
int main() {
    gen(mod);
    POW1[0] = INVPOW1[0] = 1;
    for (int i = 1; i < N; i++) {
        POW1[i] = mul(POW1[i - 1], X);
        INVPOW1[i] = inv(POW1[i]);
    }
    int n, q, u, v; char c;
    n = 20000; q = 0;
    sd(n), sd(q);
    for(int i = 1; i < n; i++){
        u = i; v = i + 1; c = 'a';
        sd(u), sd(v); cin >> c;
        int w = c - 'a' + 1;
        con[u].push_back({v, w});
        con[v].push_back({u, w});
        con2[u].pb(v); con2[v].pb(u);
    }
    up[1] = down[1] = {0, 0}; 
    dfs_original(1, 0, 0);
    pre_original(n);
    int root = decompose(1, 0);
    for(int i = 1; i <= n; i++){
        int node = i;
        while(node){
            S1[node].pb(str(node, i));
            if(parcen[node]) S2[node].pb(str(parcen[node], i));
            node = parcen[node];
        }
    }
    for(int i = 1; i <= n; i++){
        sort(S1[i].begin(), S1[i].end());
        sort(S2[i].begin(), S2[i].end());
    }
    while(q--){
        int x, y;
        sd(x), sd(y);
        str s = str(x, y);
        int ans = 0 ;
        int c = x;
        int prevc = 0;
        while(c > 0){
            str xc = str(x, c);
            if(lcp(xc, s) == xc.length){
                int w = get_node(x, y, xc.length);
                str newstr = str(w, y);
                int cnt1 = lower_bound(S1[c].begin(), S1[c].end(), newstr) - S1[c].begin();
                int cnt2 = lower_bound(S2[prevc].begin(), S2[prevc].end(), newstr) - S2[prevc].begin();
                ans += cnt1 - cnt2;
            }
            else if(xc < s) ans += S1[c].size() - S1[prevc].size();
            prevc = c;
            c = parcen[c];
        }
        printf("%d\n", ans - 1);
    }
}