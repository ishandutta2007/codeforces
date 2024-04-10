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

const int MOD = 998244353;

void add(int &x, const int &y) {
    x += y;
    if (x >= MOD) x -= MOD;
}
void sub(int &x, const int &y) {
    x -= y;
    if (x < 0) x += MOD;
}

#define SUM(a, b) ((a) + (b) >= MOD ? (a) + (b) - MOD : (a) + (b))
#define DIFF(a, b) ((a) >= (b) ? (a) - (b) : (a) - (b) + MOD)

#define LENGTH   100100
#define VALUE   111

int cnt[LENGTH][VALUE], sum[LENGTH][VALUE];
int cntAll[LENGTH], sumAll[LENGTH];
int n, limit, range, value[LENGTH];
vector<pair<int, int>> prev[LENGTH];

void init(void) {
    scanf("%d%d%d", &n, &limit, &range); range--;
    FOR(i, 1, n) scanf("%d", &value[i]);

    if (range == 0) {
        cout << 0 << endl;
        exit(EXIT_SUCCESS);
    }
}

void prepare(void) {
    map<int, int> lastPos;
    set<pair<int, int>, greater<pair<int, int>>> pos;
    FOR(i, 1, n) {
        if (value[i] > 0) {
            pos.erase(make_pair(lastPos[value[i]], value[i]));
            lastPos[value[i]] = i;
            pos.insert(make_pair(i, value[i]));
        }

        FORE(it, pos) {
            if (prev[i].size() >= 2) break;
            prev[i].push_back(*it);
        }
    }
}

int getBlock(int pos, int value) {
    FORE(it, prev[pos]) if (it->se != value) return it->fi;
    return 0;
}

void process(void) {
    FOR(j, 1, limit) {
        cnt[1][j] = value[1] == j || value[1] < 0 ? 1 : 0;
        sum[1][j] = cnt[1][j];
        add(cntAll[1], cnt[1][j]);
        add(sumAll[1], sum[1][j]);
    }

    FOR(i, 2, n) {
        FOR(j, 1, limit) {
            int block = getBlock(i, j);
            maximize(block, i - range);
            cnt[i][j] = DIFF(sumAll[i - 1], sum[i - 1][j]);
            if (block > 0) sub(cnt[i][j], DIFF(sumAll[block - 1], sum[block - 1][j]));
            else add(cnt[i][j], 1);

//            printf("count at %d, val %d is %d, block %d\n", i, j, cnt[i][j], block);

            sum[i][j] = SUM(sum[i - 1][j], cnt[i][j]);
        }
        FOR(j, 1, limit) add(cntAll[i], cnt[i][j]);
        sumAll[i] = SUM(sumAll[i - 1], cntAll[i]);
    }

    printf("%d\n", cntAll[n]);
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