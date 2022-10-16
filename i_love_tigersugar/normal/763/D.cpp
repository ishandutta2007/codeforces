#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

#define MAX   300300
const string UP = "U";
const string DOWN = "D";

#define NMOD   4
const int BASE = 256;
const int MOD[] = {(int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9 + 9277};

int pw[NMOD][MAX];
int pwInv[NMOD][MAX];

int inverse(int x, int MOD) {
    int res = 1;
    int mul = x;
    int k = MOD - 2;

    while (k > 0) {
        if (k & 1) res = 1LL * res * mul % MOD;
        mul = 1LL * mul * mul % MOD;
        k >>= 1;
    }

    assert(1LL * x * res % MOD == 1);
    return res;
}
void precalc(void) {
    REP(j, NMOD) {
        int BASE_INV = inverse(BASE, MOD[j]);
        pw[j][0] = pwInv[j][0] = 1;

        FOR(i, 1, MAX - 1) {
            pw[j][i] = 1LL * pw[j][i - 1] * BASE % MOD[j];
            pwInv[j][i] = 1LL * pwInv[j][i - 1] * BASE_INV % MOD[j];
        }
    }
}

struct Hash {
    int len, val[NMOD];

    Hash(const string &s = "") {
        len = s.size();
        memset(val, 0, sizeof val);
        REP(j, NMOD) REP(i, s.size()) val[j] = (val[j] + 1LL * s[i] * pw[j][i]) % MOD[j];
    }

    Hash operator + (const Hash &h) const {
        Hash res;
        res.len = len + h.len;
        REP(j, NMOD) res.val[j] = (val[j] + 1LL * h.val[j] * pw[j][len]) % MOD[j];
        return res;
    }

    Hash operator - (const Hash &h) const {
        assert(len >= h.len);
        Hash res;
        res.len = len - h.len;
        REP(j, NMOD) res.val[j] = 1LL * (val[j] - h.val[j] + MOD[j]) * pwInv[j][h.len] % MOD[j];
        return res;
    }

    bool operator < (const Hash &h) const {
        if (len != h.len) return len < h.len;
        REP(i, NMOD) if (val[i] != h.val[i]) return val[i] < h.val[i];
        return false;
    }
    bool operator == (const Hash &h) const {
        if (len != h.len) return false;
        REP(i, NMOD) if (val[i] != h.val[i]) return false;
        return true;
    }
};

class HashSet {
private:
    map<Hash, int> cnt;
    int numDistinct;

    void change(const Hash &h, int d) {
        int oldVal = cnt[h];
        cnt[h] += d;
        int newVal = cnt[h];

        if (oldVal > 0) numDistinct--;
        if (newVal > 0) numDistinct++;
    }

public:
    HashSet() {
        numDistinct = 0;
    }

    void insert(const Hash &h) {
        change(h, 1);
    }
    void erase(const Hash &h) {
        change(h, -1);
    }

    int getNumElement(void) const {
        return numDistinct;
    }
};

vector<int> adj[MAX];
int par[MAX], n;
Hash subTree[MAX], parTree[MAX];
vector<pair<Hash, int> > childHash[MAX];
vector<Hash> sumHash[MAX];
HashSet hs;

void loadTree(void) {
    scanf("%d", &n);
    REP(love, n - 1) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void calcSubTree(int u) {
    FORE(it, adj[u]) if (*it != par[u]) {
        int v = *it;
        par[v] = u;
        calcSubTree(v);
        childHash[u].push_back(make_pair(Hash(DOWN) + subTree[v] + UP, v));
    }

    if (childHash[u].empty()) return;

    sort(ALL(childHash[u]));
    sumHash[u].push_back(Hash());
    FORE(it, childHash[u]) sumHash[u].push_back(sumHash[u].back() + it->fi);
    subTree[u] = sumHash[u].back();
}

string operator - (const string &a, const string &b) {
    assert(b == a.substr(0, b.size()));
    return a.substr(b.size(), a.size() - b.size());
}

void calcParTree(int u) {
    if (childHash[u].empty()) return;

    Hash parHash = u == 1 ? Hash() : Hash(DOWN) + parTree[u] + UP;
    vector<Hash> &sum = sumHash[u];

    int newPos = lower_bound(ALL(childHash[u]), make_pair(parHash, -1)) - childHash[u].begin();

    REP(i, childHash[u].size()) {
        int child = childHash[u][i].se;

        if (i < newPos) {
            Hash left = sum[i];
            Hash mid = sum[newPos] - sum[i + 1];
            Hash right = sum.back() - sum[newPos];
            parTree[child] = left + mid + parHash + right;
        } else {
            Hash left = sum[newPos];
            Hash mid = sum[i] - sum[newPos];
            Hash right = sum.back() - sum[i + 1];
            parTree[child] = left + parHash + mid + right;
        }
    }

    FORE(it, childHash[u]) calcParTree(it->se);
}

pair<int, int> calcNumTree(int u) {
    pair<int, int> res = make_pair(hs.getNumElement() + 1, u);

    FORE(it, adj[u]) if (*it != par[u]) {
        int v = *it;
        hs.erase(subTree[v]);
        hs.insert(parTree[v]);
        maximize(res, calcNumTree(v));
        hs.insert(subTree[v]);
        hs.erase(parTree[v]);
    }

    return res;
}

void process(void) {
    calcSubTree(1);
    calcParTree(1);

//    FOR(i, 1, n) printf("Sub of %d is %s\n", i, subTree[i].c_str());
//    FOR(i, 1, n) printf("Par of %d is %s\n", i, parTree[i].c_str());

    FOR(i, 2, n) hs.insert(subTree[i]);
    pair<int, int> res = calcNumTree(1);
    cerr << res.fi << endl;
    cout << res.se << endl;
}

string randString(void) {
    int len = rand() % 51;
    string res;
    REP(love, len) res.push_back('A' + rand() % 26);
    return res;
}

int main(void) {
#ifdef SKY
    freopen("tmp.txt", "r", stdin);
#endif // SKY
    precalc();
    loadTree();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/