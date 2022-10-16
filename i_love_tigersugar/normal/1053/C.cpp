#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

const int MOD = (int)1e9 + 7;
struct Number {
    int value;

    Number(long long x = 0) {
        value = x % MOD;
        if (value < 0) value += MOD;
    }

    Number operator + (const Number &x) const {
        Number res;
        res.value = value + x.value;
        if (res.value >= MOD) res.value -= MOD;
        return res;
    }

    Number operator - (const Number &x) const {
        Number res;
        res.value = value - x.value;
        if (res.value < 0) res.value += MOD;
        return res;
    }

    Number operator * (const Number &x) const {
        return Number(1LL * value * x.value);
    }

    #define COMPARE(x) bool operator x (const Number &a) const { return value x a.value; }
    COMPARE(==) COMPARE(!=) COMPARE(<=) COMPARE(>=) COMPARE(<) COMPARE(>)

    void print(void) const {
        printf("%d\n", value);
    }
};

istream& operator >> (istream &is, Number &x) {
    long long value; is >> value;
    x = Number(value);
    return is;
}

ostream& operator << (ostream &os, const Number &x) {
    return os << x.value;
}

template<class Number> class FenwickTree {
private:
    vector<Number> v;
    int n;

public:
    FenwickTree(int n = 0) {
        this->n = n;
        if (n > 0) v.assign(n + 7, Number());
    }

    void update(int x, const Number &d) {
        for (; x <= n; x += x & -x) v[x] = v[x] + d;
    }

    Number get(int x) const {
        Number res = 0;
        for (; x >= 1; x &= x - 1) res = res + v[x];
        return res;
    }

    Number getSum(int l, int r) const {
        return l == 1 ? get(r) : get(r) - get(l - 1);
    }

    int findGreater(Number x) const {
//        printf("need %d, have %lld\n", x, get(n));
        int mask = 1;
        while (mask <= n) mask <<= 1;
        int res = n + 1, cur = 0;
        while (mask > 0) {
            if ((cur | mask) <= n) {
//                printf("now %d, cur %d, mask %d\n", x, cur, mask);
               if (v[cur | mask] >= x) res = cur | mask;
               else {
                cur |= mask;
                x = x - v[cur];
               }
            }
            mask >>= 1;
        }
        return res;
    }
};

#define MAX   200200
int pos[MAX], weight[MAX], n, q;
FenwickTree<long long> sumWeight;
FenwickTree<Number> sumElement;

void update(int id, int w, bool init = false) {
    int delta = init ? w : w - weight[id];
    sumWeight.update(id, delta);
    sumElement.update(id, 1LL * delta * pos[id]);
    weight[id] = w;
}

Number getSumElement(long long l, long long r) {
    if (l > 1) return getSumElement(1, r) - getSumElement(1, l - 1);
    int mid = sumWeight.findGreater(r);
    assert(mid <= n);
    Number remain = r - sumWeight.get(mid - 1);
    return sumElement.get(mid - 1) + remain * Number(pos[mid]);
}

Number query(int l, int r) {
    long long all = sumWeight.getSum(l, r);
    if (all < 1) return 0;
    long long half = all / 2;
    long long before = l == 1 ? 0 : sumWeight.getSum(1, l - 1);
//    cout << all << " " << before << endl;
    Number left = getSumElement(before + 1, before + half);
    Number right = getSumElement(before + half + 1 + all % 2, before + all);
//    cout << "LEFT: " << left << endl;
//    cout << "RIGHT: " << right << endl;
    return right - left;
}

void process(void) {
    scanf("%d%d", &n, &q);
    FOR(i, 1, n) scanf("%d", &pos[i]);
    FOR(i, 1, n) pos[i] -= i;
    FOR(i, 1, n) scanf("%d", &weight[i]);
    sumWeight = FenwickTree<long long>(n);
    sumElement = FenwickTree<Number>(n);
    FOR(i, 1, n) update(i, weight[i], true);

    REP(love, q) {
        int l, r; scanf("%d%d", &l, &r);
        if (l > 0) query(l, r).print();
        else update(-l, r);
    }
}

int main(void) {
#ifdef SKY
    freopen("tmp.txt", "r", stdin);
#endif // SKY

    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/