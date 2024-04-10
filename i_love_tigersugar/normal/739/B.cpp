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

/* Author: Van Hanh Pham - skyvn97 */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

class FenwickTree {
    private:
    int n;
    vector<int> v;

    int get(int x) const {
        int res = 0;
        for (; x >= 1; x &= x - 1) res += v[x];
        return res;
    }

    public:
    FenwickTree(int n = 0) {
        this->n = n;
        v.assign(n + 7, 0);
    }

    void update(int x) {
        for (; x <= n; x += x & -x) v[x]++;
    }
    int get(int L, int R) const {
        if (L > R) return 0;
        return L == 1 ? get(R) : get(R) - get(L - 1);
    }
};

#define MAX   200200

vector<pair<int, int> > adj[MAX];
int n;
long long high[MAX];
int value[MAX];
int sta[MAX], fin[MAX], cnt;
int answer[MAX];

void loadTree(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &value[i]);
    FOR(i, 2, n) {
        int x, c; scanf("%d%d", &x, &c);
        adj[x].push_back(make_pair(i, c));
        adj[i].push_back(make_pair(x, c));
    }
}

void dfs(int u, int par) {
    sta[u] = ++cnt;
    FORE(it, adj[u]) if (it->fi != par) {
        int v = it->fi;
        high[v] = high[u] + it->se;
        dfs(v, u);
    }
    fin[u] = cnt;
}

bool compUpdate(const int &x, const int &y) {
    return high[x] - value[x] < high[y] - value[y];
}
bool compQuery(const int &x, const int &y) {
    return high[x] < high[y];
}
void process(void) {
    dfs(1, -1);

    vector<int> queries, updates;
    FOR(i, 1, n) {
        queries.push_back(i);
        updates.push_back(i);
    }

    sort(ALL(updates), compUpdate);
    sort(ALL(queries), compQuery);

    FenwickTree bit(n);
    int j = 0;
    FORE(it, queries) {
        while (j < updates.size()) {
            int tmp = updates[j];
            if (high[tmp] - value[tmp] > high[*it]) break;
            bit.update(sta[tmp]);
            j++;
        }
        answer[*it] = bit.get(sta[*it] + 1, fin[*it]);
    }

    FOR(i, 1, n) printf("%d ", answer[i]); printf("\n");
}

int main(void) {
    loadTree();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/