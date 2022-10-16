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
    vector<long long> sum;
    vector<int> lazy, minValue;
    int n;

    void pushDown(int i, int l, int r) {
        if (lazy[i] >= 0) {
            int m = (l + r) >> 1;
            FOR(j, 2 * i, 2 * i + 1) {
                sum[j] = 1LL * (j == 2 * i ? m - l + 1 : r - m) * lazy[i];
                minValue[j] = lazy[i];
                lazy[j] = lazy[i];
            }
            lazy[i] = -1;
        }
    }

    void assign(int i, int l, int r, int u, int v, int c) {
        if (l > v || r < u || l > r || v < u) return;
        if (u <= l && r <= v) {
            sum[i] = 1LL * (r - l + 1) * c;
            minValue[i] = c;
            lazy[i] = c;
            return;
        }

        pushDown(i, l, r);
        int m = (l + r) >> 1;
        assign(2 * i, l, m, u, v, c);
        assign(2 * i + 1, m + 1, r, u, v, c);
        sum[i] = sum[2 * i] + sum[2 * i + 1];
        minValue[i] = min(minValue[2 * i], minValue[2 * i + 1]);
    }

    long long getSum(int i, int l, int r, int u, int v) {
        if (l > v || r < u || l > r || v < u) return 0;
        if (u <= l && r <= v) return sum[i];

        pushDown(i, l, r);
        int m = (l + r) >> 1;
        long long L = getSum(2 * i, l, m, u, v);
        long long R = getSum(2 * i + 1, m + 1, r, u, v);
        return L + R;
    }

    int findFirstLess(int x) {
        if (minValue[1] >= x) return n + 1;
        int i = 1, l = 1, r = n;

        while (true) {
            if (l == r) return r;
            pushDown(i, l, r);
            int m = (l + r) >> 1;
            if (minValue[2 * i] < x) {
                i = 2 * i; r = m;
            } else {
                i = 2 * i + 1; l = m + 1;
            }
        }
    }

public:
    SegmentTree(int n = 0) {
        this->n = n;
        sum.assign(4 * n + 7, 0);
        lazy.assign(4 * n + 7, 0);
        minValue.assign(4 * n + 7, 0);
    }

    void update(int y, int z) {
        int pos = findFirstLess(z);
        assign(1, 1, n, pos, y, z);
    }

    long long getArea(int needY, int needZ, int limZ) {
        int pos = findFirstLess(needZ);
        //printf("CALC %d %d lim %d, pos = %d\n", needY, needZ, limZ, pos);
        long long res = 0;
        if (pos > needY) res += 1LL * (pos - needY) * limZ - getSum(1, 1, n, needY, pos - 1);
        if (pos <= n) res += 1LL * (n - max(pos, needY) + 1) * (limZ - needZ + 1);
        return res;
    }

    void debug(void) {
        printf("TREE: ");
        FOR(i, 1, n) printf("%lld ", getSum(1, 1, n, i, i)); printf("\n");
    }
};

struct Card {
    int x, y, z;

    Card(int _x = 0, int _y = 0, int _z = 0) {
        x = _x; y = _y; z = _z;
    }

    void input(void) {
        scanf("%d%d%d", &x, &y, &z);
    }

    bool operator < (const Card &c) const {
        return x < c.x;
    }
};

#define MAX   500500

int n, limX, limY, limZ;
Card cards[MAX];
int maxY[MAX], maxZ[MAX];

void init(void) {
    scanf("%d%d%d%d", &n, &limX, &limY, &limZ);
    FOR(i, 1, n) cards[i].input();

    sort(cards + 1, cards + n + 1);
    maxY[n] = cards[n].y;
    maxZ[n] = cards[n].z;

    FORD(i, n - 1, 1) {
        maxY[i] = max(maxY[i + 1], cards[i].y);
        maxZ[i] = max(maxZ[i + 1], cards[i].z);
    }
}

void process(void) {
    SegmentTree myit(limY);

    long long res = 0;
    int j = 1;
    FOR(i, 1, limX) {
        while (j <= n && cards[j].x < i) {
            myit.update(cards[j].y, cards[j].z);
            j++;
        }
        int needY = j > n ? 1 : maxY[j] + 1;
        int needZ = j > n ? 1 : maxZ[j] + 1;

//        printf("With x = %d, lim is %d and %d, area is %lld\n", i, needY, needZ,
//                myit.getArea(needY, needZ, limZ));
        res += myit.getArea(needY, needZ, limZ);

        //myit.debug();
    }

    cout << res << endl;
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