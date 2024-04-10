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

#define MAX_PREPARE   5050

int preparedGCD[MAX_PREPARE + 3][MAX_PREPARE + 3];
void prepareGCD(void) {
    FOR(i, 1, MAX_PREPARE) preparedGCD[i][i] = i;
    FOR(i, 1, MAX_PREPARE) FOR(j, i + 1, MAX_PREPARE)
        preparedGCD[i][j] = __gcd(i, j);
    FOR(i, 1, MAX_PREPARE) FOR(j, 1, i - 1)
        preparedGCD[i][j] = preparedGCD[j][i];
}

int gcd(int a, int b) {
    while (true) {
        if (a == 0) return b;
        if (b == 0) return a;
        if (a <= MAX_PREPARE && b <= MAX_PREPARE) return preparedGCD[a][b];
        if (a > b) a %= b; else b %= a;
    }
}

class SegmentTree {
private:
    struct Node {
        int id, l, r;
        Node(int _id = 0, int _l = 0, int _r = 0) {
            id = _id; l = _l; r = _r;
        }
    };
    const Node NA = Node(-1, -1, -1);

    #define IS_NA(node) (node.id < 0)

    vector<int> tree;
    int n;

    Node findNode(int i, int l, int r, int u, int v, int value) const {
        if (l > v || r < u || l > r || v < u) return NA;
        if (u <= l && r <= v) return tree[i] % value == 0 ? NA : Node(i, l, r);
        int m = (l + r) >> 1;
        Node tmp = findNode(2 * i, l, m, u, v, value);
        return !IS_NA(tmp) ? tmp : findNode(2 * i + 1, m + 1, r, u, v, value);
    }

    int findPos(int l, int r, int value) const {
        Node node = findNode(1, 1, n, l, r, value);
        if (IS_NA(node)) return -1;
        int i = node.id;
        l = node.l; r = node.r;
        while (true) {
            if (l == r) return r;
            int m = (l + r) >> 1;
            if (tree[2 * i] % value == 0) {
                i = 2 * i + 1; l = m + 1;
            } else {
                i = 2 * i; r = m;
            }
        }
    }

    void update(int i, int l, int r, int pos, int value) {
        if (l == r) {
            tree[i] = value;
            return;
        }
        int m = (l + r) >> 1;
        if (pos > m) update(2 * i + 1, m + 1, r, pos, value);
        else update(2 * i, l, m, pos, value);
        tree[i] = gcd(tree[2 * i], tree[2 * i + 1]);
    }

    int get(int i, int l, int r, int u, int v) const {
        if (l > v || r < u || l > r || v < u) return 0;
        if (u <= l && r <= v) return tree[i];
        int m = (l + r) >> 1;
        int L = get(2 * i, l, m, u, v);
        int R = get(2 * i + 1, m + 1, r, u, v);
        return gcd(L, R);
    }

    void init(int i, int l, int r, int arr[]) {
        if (l > r) return;
        if (l == r) {
            tree[i] = arr[r];
            return;
        }
        int m = (l + r) >> 1;
        init(2 * i, l, m, arr);
        init(2 * i + 1, m + 1, r, arr);
        tree[i] = gcd(tree[2 * i], tree[2 * i + 1]);
    }

public:
    SegmentTree(int n = 0, int arr[] = NULL) {
        this->n = n;
        if (n == 0) return;
        tree.assign(4 * n + 7, 0);
        init(1, 1, n, arr);
    }

    void update(int pos, int value) {
        update(1, 1, n, pos, value);
    }

    bool query(int l, int r, int value) {
        if (get(1, 1, n, l, r) % value == 0) return true;
        int pos = findPos(l, r, value);
        return pos == r || get(1, 1, n, pos + 1, r) % value == 0;
    }
};

#define MAX   500500
const char YES[] = "YES";
const char NO[] = "NO";

int a[MAX], n, q;

void process(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &a[i]);
    SegmentTree myit(n, a);
    scanf("%d", &q);
    REP(love, q) {
        int type; scanf("%d", &type);
        if (type == 1) {
            int l, r, v; scanf("%d%d%d", &l, &r, &v);
            printf("%s\n", myit.query(l, r, v) ? YES : NO);
        } else {
            int pos, value; scanf("%d%d", &pos, &value);
            myit.update(pos, value);
        }
    }
}

int main(void) {
    prepareGCD();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/