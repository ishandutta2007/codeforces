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

const string YES = "Yes";
const string NO = "No";

#define MAX   500500
long long sqr[MAX];
vector<int> div[MAX];

#define SQR(x) (1LL * (x) * (x))
void prepare(void) {
    FOR(i, 1, MAX - 1) sqr[i] = SQR(i);
    for (int i = 1; 1LL * i * i < MAX; i++)
        for (int j = i * i; j < MAX; j += i) div[j].push_back(i);
}

bool isSquare(long long x) {
    return binary_search(sqr, sqr + MAX - 1, x);
}

vector<pair<int, int>> candidates[MAX];
int value[MAX], res[MAX];
int n;

void init(void) {
    scanf("%d", &n); n /= 2;
    FOR(i, 1, n) scanf("%d", &value[i]);
}

void process(void) {
    candidates[0].push_back(make_pair(0, 0));
    REP(i, n) {
        vector<pair<int, int>> &prev = candidates[i];
        vector<pair<int, int>> &next = candidates[i + 1];

        FORE(jt, div[value[i + 1]]) {
            int a = *jt;
            int b = value[i + 1] / *jt;
            if ((a + b) % 2 != 0) continue;

            int sum = (b + a) / 2;
            int mid = (b - a) / 2;
            if (mid < 1) continue;
            assert(SQR(mid) + value[i + 1] == SQR(sum));

            FORE(kt, prev) {
                long long total = SQR(sum) - SQR(kt->fi);
                long long toIns = total - value[i + 1];

                if (toIns >= 1 && SQR(kt->fi) + toIns == SQR(mid)) {
                    next.push_back(make_pair(sum, kt->fi));
                    break;
                }
            }
        }
    }

    if (candidates[n].empty()) {
        cout << NO << endl;
        return;
    }

    res[n] = candidates[n].front().fi;
    FORD(i, n, 1) {
        bool ok = false;
        FORE(jt, candidates[i]) if (jt->fi == res[i]) {
            res[i - 1] = jt->se;
            ok = true;
            break;
        }
        assert(ok);
    }
    res[0] = 0;

    cout << YES << endl;
    FOR(i, 1, n) {
        cout << SQR(res[i]) - SQR(res[i - 1]) - value[i] << " " << value[i] << " ";
    }
    cout << endl;
}

int main(void) {
    prepare();
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/