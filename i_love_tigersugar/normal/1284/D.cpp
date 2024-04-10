#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define IS_INF(x)   (std::isinf(x))
#define IS_NAN(x)   (std::isnan(x))
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

class SegmentTree {
private:
    vector<long long> tree, lazy;
    int n;

    void pushDown(int i, int l, int r) {
        int m = (l + r) >> 1;
        tree[2 * i] += lazy[i] * (m - l + 1);
        tree[2 * i + 1] += lazy[i] * (r - m);
        FOR(j, 2 * i, 2 * i + 1) lazy[j] += lazy[i];
        lazy[i] = 0;
    }

    void update(int i, int l, int r, int u, int v, int c) {
        if (l > v || r < u || l > r || v < u) return;
        if (u <= l && r <= v) {
            tree[i] += 1LL * c * (r - l + 1);
            lazy[i] += c;
            return;
        }

        int m = (l + r) >> 1;
        pushDown(i, l, r);

        update(2 * i, l, m, u, v, c);
        update(2 * i + 1, m + 1, r, u, v, c);
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }

    long long getSum(int i, int l, int r, int u, int v) {
        if (l > v || r < u || l > r || v < u) return 0;
        if (u <= l && r <= v) return tree[i];

        int m = (l + r) >> 1;
        pushDown(i, l, r);
        long long L = getSum(2 * i, l, m, u, v);
        long long R = getSum(2 * i + 1, m + 1, r, u, v);
        return L + R;
    }
public:
    SegmentTree(int n = 0) {
        this->n = n;
        if (n > 0) {
            tree.assign(4 * n + 7, 0);
            lazy.assign(4 * n + 7, 0);
        }
    }

    void update(int l, int r, int c) {
        update(1, 1, n, l, r, c);
    }
    long long getSum(int l, int r) {
        assert(1 <= l && r <= n);
        return getSum(1, 1, n, l, r);
    }
};

struct Item {
    int l, r, u, v;

    Item() {
        l = r = u = v = 0;
    }

    void input(void) {
        scanf("%d%d%d%d", &l, &r, &u, &v);
    }

    void print(void) const {
        printf("Segment [%d, %d] and [%d, %d]\n", l, r, u, v);
    }
};

const string YES = "YES";
const string NO = "NO";

#define MAX   500500
Item items[MAX];
int numItem;
vector<int> values;

void init(void) {
    scanf("%d", &numItem);
    FOR(i, 1, numItem) {
        items[i].input();
        values.push_back(items[i].l);
        values.push_back(items[i].r);
        values.push_back(items[i].u);
        values.push_back(items[i].v);
    }

    sort(ALL(values));
    values.resize(unique(ALL(values)) - values.begin());

    FOR(i, 1, numItem) {
        items[i].l = lower_bound(ALL(values), items[i].l) - values.begin() + 1;
        items[i].r = lower_bound(ALL(values), items[i].r) - values.begin() + 1;
        items[i].u = lower_bound(ALL(values), items[i].u) - values.begin() + 1;
        items[i].v = lower_bound(ALL(values), items[i].v) - values.begin() + 1;
    }
}

bool CompareLeft(const int &x, const int &y) {
    return items[x].l < items[y].l;
}
bool CompareRight(const int &x, const int &y) {
    return items[x].r < items[y].r;
}

void check(void) {
    vector<int> sortLeft, sortRight;
    FOR(i, 1, numItem) {
        sortLeft.push_back(i);
        sortRight.push_back(i);
    }
    sort(ALL(sortLeft), CompareLeft);
    sort(ALL(sortRight), CompareRight);

    SegmentTree myit(values.size());

    int j = 0;
    FORE(it, sortLeft) {
//        printf("Considering: "); items[*it].print();

        Item &item = items[*it];
        while (j < sortRight.size() && items[sortRight[j]].r < item.l) {
            Item &tmp = items[sortRight[j]];
//            printf("\tUpdating: "); tmp.print();

            myit.update(tmp.u, tmp.v, 1);
            j++;
        }
        if (myit.getSum(item.u, item.v) > 0) {
            cout << NO << endl;
            exit(EXIT_SUCCESS);
        }
    }
}

void process(void) {
    check();
    FOR(i, 1, numItem) {
        swap(items[i].l, items[i].u);
        swap(items[i].r, items[i].v);
    }
    check();
    cout << YES << endl;
}

int main(void) {
#ifdef SKY
    freopen("tmp.txt", "r", stdin);
#endif // SKY

    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/