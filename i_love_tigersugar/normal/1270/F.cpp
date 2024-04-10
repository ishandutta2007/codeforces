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

#ifdef SKY
const int THRESHOLD = 1;
#else
const int THRESHOLD = 800;
#endif // SKY

#define MAX   200200

int n;
char s[MAX];
int cntOne[MAX];
vector<int> ones;
long long res;

void init(void) {
    scanf("%s", s + 1);
    n = strlen(s + 1);

    FOR(i, 1, n) cntOne[i] = cntOne[i - 1] + (s[i] == '1');
    FOR(i, 1, n) if (s[i] == '1') ones.push_back(i);
}

int cntX[MAX];
void countSmall(int limX, int limY, int base, int mod) {
//    printf("Count small %d %d %d %d\n", limX, limY, base, mod);

    int x = 0;
    REP(love, limX + 1) {
        cntX[x]++;
        if (x == mod - 1) x = 0; else x++;
    }
    int y = 0;
    REP(love, limY + 1) {
        // x + y + base = 0 -> x = - base - y
        x = mod - base - y;
        while (x < 0) x += mod;
        while (x >= mod) x -= mod;
        res += cntX[x];
        if (y == mod - 1) y = 0; else y++;
    }

    x = 0;
    REP(love, limX + 1) {
        cntX[x] = 0;
        if (x == mod - 1) x = 0; else x++;
    }
}

void processSmall(void) {
    REP(i, ones.size()) FOR(j, i, (int)ones.size() - 1) {
        int numOne = j - i + 1;
        if (numOne > THRESHOLD) break;

        int length = (ones[j] - ones[i] + 1) % numOne;
        int left = i == 0 ? 0 : ones[i - 1];
        int right = j == (int)ones.size() - 1 ? n + 1 : ones[j + 1];
        countSmall(ones[i] - left - 1, right - ones[j] - 1, length, numOne);
    }
}

long long sum[MAX];
pair<long long, int> pp[MAX];

void countSegment(int l, int r) {
    int j = l;
    FOR(i, l, r) {
        while (pp[i].se - pp[j].se > THRESHOLD) j++;
        res += j - l;
    }
}

void countBig(int mul) {
    pp[0] = make_pair(0, 0);
    FOR(i, 1, n) {
        int value = s[i] == '1' ? mul - 1 : -1;
        sum[i] = sum[i - 1] + value;
        pp[i] = make_pair(sum[i], cntOne[i]);
    }

    sort(pp, pp + n + 1);

    vector<int> first, last;
    FOR(i, 0, n) {
        if (i == 0 || pp[i].fi > pp[i - 1].fi) first.push_back(i);
        if (i == n || pp[i].fi < pp[i + 1].fi) last.push_back(i);
    }

    assert(first.size() == last.size());
    REP(i, first.size()) countSegment(first[i], last[i]);
}

void processBig(void) {
    FOR(mul, 1, n / THRESHOLD) countBig(mul);
}

void process(void) {
    processSmall();
    processBig();
    cout << res << endl;
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/