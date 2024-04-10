#include <bits/stdc++.h>
#define maxn 150086

using namespace std;

typedef long long ll;


struct Line {
    mutable double k, m, p;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(double x) const { return p < x; }
};

struct LineContainer : std::multiset<Line, std::less<>> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    const double inf = 1/.0;
    double div(double a, double b) { return a / b; }
    bool isect(iterator x, iterator y) {
        if (y == end()) { x->p = inf; return false; }
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(double k, double m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ll query(ll x) {
        if(empty()) return 0;
        auto l = *lower_bound(x);
        return (ll)l.k * x + (ll)l.m;
    }
}l;

int n;
int x, y;
vector<int> v[maxn];
int a[maxn];
int siz[maxn];
int sum, mn, id;
bool del[maxn];
ll ans;


void dfs1(int i, int fa){
    siz[i] = 1;
    int val = 0;
    for(int j = 0;j < v[i].size();j++){
        int to = v[i][j];
        if(to == fa || del[to]) continue;
        dfs1(to, i);
        siz[i] += siz[to];
        val = max(val, siz[to]);
    }
    val = max(val, sum - siz[i]);
    if(val < mn) mn = val, id = i;
}

struct Node{
	int dep;
	ll u, d, val;
};

vector<vector<Node> > b;
int dep;
ll u, d, val;

void dfs2(int i, int fa){
    bool leaf = true;
    u += 1ll * (++dep) * a[i];
    val += a[i];
    d += val;
    //printf("%d %d %d %lld %lld--\n", i, fa, dep, u, d);
    for(int j = 0;j < v[i].size();j++){
        int to = v[i][j];
        if(to == fa) continue;
        leaf = false;
        if(del[to]) continue;
        dfs2(to, i);
    }
    
    if(leaf) b.back().push_back((Node){dep, u, d, val});
    u -= 1ll * (dep--) * a[i];
    d -= val;
    val -= a[i];
}

void dfs3(int i){
    dfs1(i, 0);
    int rt = id;
    //printf("%d %d--\n", rt, i);
    for(int j = 0;j < v[rt].size();j++){
        int to = v[rt][j];
        if(del[to]) continue;
        b.push_back(vector<Node>());
        dfs2(to, rt);
    }

    l.add(1, a[rt]);
    for(int j = 0;j < b.size();j++){
        for(int k = 0;k < b[j].size();k++){
            ans = max(ans, b[j][k].u + l.query(b[j][k].val));
        }
        for(int k = 0;k < b[j].size();k++){
            l.add(b[j][k].dep + 1, b[j][k].d + 1ll * a[rt] * (b[j][k].dep + 1));
        }
    }
    l.clear();

    for(int j = (int)b.size() - 1;~j;j--){
        for(int k = 0;k < b[j].size();k++){
            ans = max(ans, b[j][k].u + l.query(b[j][k].val));
        }
        for(int k = 0;k < b[j].size();k++){
            l.add(b[j][k].dep + 1, b[j][k].d + 1ll * a[rt] * (b[j][k].dep + 1));
        }
    }
    ans = max(ans, l.query(0));//debug:down p
    l.clear();


    b.clear();
    del[rt] = true;
    int s = sum;
    for(int j = 0;j < v[rt].size();j++){
        int to = v[rt][j];
        if(del[to]) continue;
        if(siz[to] < siz[rt]) sum = mn = siz[to];
        else sum = mn = s - siz[rt];
        dfs3(to);
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 1;i < n;i++){
        scanf("%d%d", &x, &y);
        v[x].push_back(y), v[y].push_back(x);
    }
    for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
    sum = mn = n, dfs3(1);
    printf("%lld", ans);
}