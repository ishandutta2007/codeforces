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

#define NUM_CHAR   62
int getCode(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    if ('A' <= c && c <= 'Z') return c - 'A' + 10;
    if ('a' <= c && c <= 'z') return c - 'a' + 36;
    assert(false);
}

class SegmentTree {
private:
    static const int INF = (int)1e9 + 7;

    struct Node {
        int minValue[NUM_CHAR], lazy;
        Node *left, *right;

        Node() {
            memset(minValue, 0x3f, sizeof minValue);
            lazy = 0;
            left = right = NULL;
        }

        void calculate(void) {
            if (left == NULL || right == NULL) return;
            REP(i, NUM_CHAR) minValue[i] = min(left->minValue[i], right->minValue[i]);
        }

        void pushDown(void) {
            if (left == NULL || right == NULL || lazy == 0) return;
            REP(i, NUM_CHAR) {
                left->minValue[i] += lazy;
                right->minValue[i] += lazy;
            }
            left->lazy += lazy;
            right->lazy += lazy;
            lazy = 0;
        }

        void add(int x) {
            REP(i, NUM_CHAR) minValue[i] += x;
            lazy += x;
        }
    };

    Node *root;
    char *input;
    int n;

    void init(Node *&root, int l, int r) {
        if (l > r) return;
        root = new Node();
        if (l == r) {
            root->minValue[getCode(input[r])] = r;
            return;
        }
        int m = (l + r) >> 1;
        init(root->left, l, m);
        init(root->right, m + 1, r);
        root->calculate();
    }

    void update(Node *p, int l, int r, int u, int v, int c) {
        if (l > v || r < u || l > r || v < u) return;
        if (u <= l && r <= v) return p->add(c);
        p->pushDown();
        int m = (l + r) >> 1;
        update(p->left, l, m, u, v, c);
        update(p->right, m + 1, r, u, v, c);
        p->calculate();
    }

    pair<int, int> findLess(int value, int charCode) {
        if (root->minValue[charCode] > value) return make_pair(-1, -1);
        Node *p = root;
        int l = 1, r = n;
        while (true) {
            if (l == r) return make_pair(r, p->minValue[charCode]);
            p->pushDown();
            int m = (l + r) >> 1;
            if (p->right->minValue[charCode] <= value) {
                p = p->right;
                l = m + 1;
            } else {
                p = p->left;
                r = m;
            }
        }
    }

    int getValue(int pos) {
        Node *p = root;
        int l = 1, r = n;
        while (true) {
            if (l == r) return p->minValue[getCode(input[pos])];
            p->pushDown();
            int m = (l + r) >> 1;
            if (pos > m) {
                p = p->right;
                l = m + 1;
            } else {
                p = p->left;
                r = m;
            }
        }
    }

public:
    SegmentTree(int n = 0, char *input = NULL) {
        this->n = n;
        this->input = input;
        root = NULL;
        if (n == 0) return;
        init(root, 1, n);
    }

    void erase(int l, int r, char c) {
        while (true) {
            pair<int, int> pos = findLess(r, getCode(c));
            if (pos.se < l) return;
            update(root, 1, n, pos.fi, pos.fi, INF);
            update(root, 1, n, pos.fi + 1, n, -1);
            r = pos.se - 1;
        }
    }

//    void debug(void) {
//        FOR(i, 1, n) {
//            int tmp = getValue(i);
//            if (tmp > i) tmp = -1;
//            printf("%d ", tmp);
//        }
//        printf("\n");
//    }

    string printString(void) {
        string res;
        FOR(i, 1, n) if (getValue(i) <= i) res.push_back(input[i]);
        return res;
    }
};

#define MAX   200200
char input[MAX];
int n, q;

void process(void) {
    scanf("%d%d", &n, &q);
    scanf("%s", input + 1);
    SegmentTree myit(n, input);
    REP(love, q) {
        int l, r; scanf("%d%d", &l, &r);
        char s[6]; memset(s, 0, sizeof s);
        scanf("%s", s);
        myit.erase(l, r, s[0]);
    }
    cout << myit.printString() << endl;
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/