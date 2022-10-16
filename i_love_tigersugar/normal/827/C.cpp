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

class FenwickTree {
private:
    vector<int> v;
    int n;

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

    void update(int x, int d) {
        for (; x <= n; x += x & -x) v[x] += d;
    }

    int getSum(int l, int r) const {
        return l == 1 ? get(r) : get(r) - get(l - 1);
    }
};

#define MAX   100100
#define LEN   10

const char ch[] = "ATGC";
int getCode(char c) {
    REP(i, 4) if (ch[i] == c) return i;
    assert(false);
}

FenwickTree bit[LEN + 3][LEN + 3][5];
char s[MAX];
int n, q;

void init(void) {
    scanf("%s", s + 1);
    scanf("%d", &q);
    n = strlen(s + 1);
}

void prepare(void) {
    FOR(i, 1, LEN) REP(j, i) REP(k, 4)
        bit[i][j][k] = FenwickTree(n);
    FOR(i, 1, n) FOR(j, 1, LEN) bit[j][i % j][getCode(s[i])].update(i, 1);
}

void change(int pos, char c) {
    FOR(i, 1, LEN) bit[i][pos % i][getCode(s[pos])].update(pos, -1);
    s[pos] = c;
    FOR(i, 1, LEN) bit[i][pos % i][getCode(s[pos])].update(pos, 1);
}

char input[LEN + 10];
int answer(int l, int r) {
    int res = 0;
    int len = strlen(input);
    REP(i, len) res += bit[len][(l + i) % len][getCode(input[i])].getSum(l, r);
    return res;
}

void process(void) {
    REP(pmp, q) {
        int type; scanf("%d", &type);
        if (type == 1) {
            int pos; scanf("%d", &pos);
            scanf("%s", input);
            change(pos, input[0]);
        } else {
            int l, r; scanf("%d%d", &l, &r);
            scanf("%s", input);
            printf("%d\n", answer(l, r));
        }
    }
}

int main(void) {
#ifdef SKY
    freopen("tmp.txt", "r", stdin);
#endif // SKY
    init();
    prepare();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/