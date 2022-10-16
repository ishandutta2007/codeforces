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

class SegmentTree {
private:
    struct Node {
        int sum;
        Node *left, *right;

        Node() {
            left = right = NULL;
            sum = 0;
        }
        Node(Node *p) {
            sum = p->sum;
            left = p->left;
            right = p->right;
        }
    };

    int n;
    Node *root;

    void build(Node *&p, int l, int r) {
        if (l > r) return;
        p = new Node();
        if (l == r) return;
        int m = (l + r) >> 1;
        build(p->left, l, m);
        build(p->right, m + 1, r);
    }

public:
    SegmentTree(int n = 0) {
        this->n = n;
        root = NULL;
        if (n > 0) build(root, 1, n);
    }

    void update(int x, int d) {
        root = new Node(root);
        Node *p = root;
        int l = 1, r = n;

        while (true) {
            p->sum += d;
            if (l == r) return;

            int m = (l + r) >> 1;
            if (x > m) {
                p->right = new Node(p->right);
                p = p->right;
                l = m + 1;
            } else {
                p->left = new Node(p->left);
                p = p->left;
                r = m;
            }
        }
    }

//    int get(int x) const {
//        if (x == 0) return 0;
//        Node *p = root;
//        int res = 0;
//        int l = 1, r = n;
//
//        while (true) {
//            if (l == r) return res + p->sum;
//
//            int m = (l + r) >> 1;
//            if (x > m) {
//                res += p->left->sum;
//                p = p->right;
//                l = m + 1;
//            } else {
//                p = p->left;
//                r = m;
//            }
//        }
//    }

    int findPos(int pos, int lim) const {
        lim += pos - 1;

        if (root->sum <= lim) return n;

        Node *p = root;
        int l = 1, r = n;

        int res = 0;

        while (true) {
            if (l == r) return p->sum <= lim ? r : res;

            int m = (l + r) >> 1;
            if (p->left->sum <= lim) {
                maximize(res, m);
                lim -= p->left->sum;
                p = p->right;
                l = m + 1;
            } else {
                p = p->left;
                r = m;
            }
        }
    }
};

#define MAX   100100

int color[MAX], prev[MAX], n, oldN;
SegmentTree myit[MAX];

void init(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &color[i]);
}

void prepare(void) {
    oldN = n;

    vector<int> values;
    FOR(i, 1, n) if (values.empty() || values.back() != color[i]) values.push_back(color[i]);
    n = values.size();
    FOR(i, 1, n) color[i] = values[i - 1];

    map<int, int> pos;
    FOR(i, 1, n) {
        prev[i] = pos.find(color[i]) == pos.end() ? 0 : pos[color[i]];
        pos[color[i]] = i;
    }

    vector<pair<int, int> > v;
    FOR(i, 1, n) v.push_back(make_pair(prev[i], i));
    sort(ALL(v));

    int j = 0;
    FOR(i, 0, n) {
        myit[i] = i == 0 ? SegmentTree(n) : myit[i - 1];
        while (j < v.size() && v[j].fi <= i) myit[i].update(v[j++].se, 1);
    }
}

int findNext(int pos, int lim) {
    return myit[pos - 1].findPos(pos, lim);
}

int solve(int lim) {
    int res = 0;
    int pos = 0;

    while (pos < n) {
        res++;
        pos = findNext(pos + 1, lim);
    }

    return res;
}

void process(void) {
    FOR(i, 1, oldN) printf("%d ", solve(i)); printf("\n");
}

int main(void) {
    init();
    prepare();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/