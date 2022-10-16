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

#define MAX_PROBLEM   103
#define MAX_SCORE   11

const double WATCHING_TIME = 10;
const double RATE = 1 / 0.9;
const double EPS = 1E-9;

int numProblem;
double trainCoefficient, duration;
pair<int, int> problems[MAX_PROBLEM];

int totalScore[MAX_PROBLEM];
double RATE_PW[MAX_PROBLEM];
double bestTime[MAX_PROBLEM][MAX_PROBLEM][MAX_SCORE * MAX_PROBLEM];

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    return a.fi > b.fi;
}

void init(void) {
    scanf("%d%lf%lf", &numProblem, &trainCoefficient, &duration);
    FOR(i, 1, numProblem) scanf("%d%d", &problems[i].fi, &problems[i].se);
    sort(problems + 1, problems + numProblem + 1, compare);

    RATE_PW[0] = 1;
    FOR(i, 1, numProblem) RATE_PW[i] = RATE_PW[i - 1] * RATE;
    totalScore[0] = 0;
    FOR(i, 1, numProblem) totalScore[i] = totalScore[i - 1] + problems[i].se;
}

void calcBestTime(void) {
    REP(i, numProblem + 1) REP(j, i + 1) REP(k, totalScore[i] + 1)
        bestTime[i][j][k] = INFINITY;
    bestTime[0][0][0] = 0;
    REP(pos, numProblem + 1) REP(used, pos + 1) REP(score, totalScore[pos] + 1)
        if (!IS_INF(bestTime[pos][used][score])) {
//            printf("%d %d %d\n", pos, used, score);
            minimize(bestTime[pos + 1][used][score], bestTime[pos][used][score]);
            int newUsed = used + 1;
            int newScore = score + problems[pos + 1].se;
            double moreTime = problems[pos + 1].fi * RATE_PW[newUsed];
            minimize(bestTime[pos + 1][newUsed][newScore], bestTime[pos][used][score] + moreTime);
        }
}

bool ok(int used, int score) {
    double X = bestTime[numProblem][used][score];
    double A = duration - WATCHING_TIME * used;
    if (IS_INF(X)) return false;
    if (A <= 0) return false;
    if (X <= A) return true;
    double C = trainCoefficient;

    double a = C, b = 1 - A * C, c = X - A;
    double delta = b * b - 4 * a * c;
    if (delta < 0) return false;
    return c <= 0 || b <= 0;
}

void process(void) {
    FORD(score, totalScore[numProblem], 1) FOR(used, 1, numProblem)
        if (ok(used, score)) {
            cout << score << endl;
            return;
        }
    cout << 0 << endl;
}

int main(void) {
#ifdef SKY
    freopen("tmp.txt", "r", stdin);
#endif // SKY
    int t; scanf("%d", &t);
    REP(love, t) {
        init();
        calcBestTime();
        process();
    }
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/