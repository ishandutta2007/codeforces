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

/** END OF TEMPLATE. DRINK A CUP OF TIGERSUGAR BEFORE READING MY CODE. **/

#define MAX_POINT   10101
#define MAX_TIME   2207
const int INF = (int)1e9 + 7;

int length, numPoint, green, red;
int points[MAX_POINT];
int dist[MAX_POINT][MAX_TIME];

void init(void) {
    scanf("%d%d", &length, &numPoint);
    FOR(i, 1, numPoint) scanf("%d", &points[i]);
    sort(points + 1, points + numPoint + 1);
    scanf("%d%d", &green, &red);
}

void process(void) {
    deque<pair<int, int>> dq;
    memset(dist, 0x3f, sizeof dist);

    dist[1][0] = 0;
    dq.push_back({1, 0});

    while (!dq.empty()) {
        int pos = dq.front().fi;
        int time = dq.front().se;
        dq.pop_front();

        if (time == green && minimize(dist[pos][0], dist[pos][time] + 1)) dq.push_back({pos, 0});
        if (pos > 1 && time + points[pos] - points[pos - 1] <= green) {
            int newTime = time + points[pos] - points[pos - 1];
            if (minimize(dist[pos - 1][newTime], dist[pos][time])) dq.push_front(make_pair(pos - 1, newTime));
        }
        if (pos < numPoint && time + points[pos + 1] - points[pos] <= green) {
            int newTime = time + points[pos + 1] - points[pos];
            if (minimize(dist[pos + 1][newTime], dist[pos][time])) dq.push_front(make_pair(pos + 1, newTime));
        }
    }

    int res = INF;
    FOR(i, 0, green) if (dist[numPoint][i] < INF)
        minimize(res, dist[numPoint][i] * (green + red) + i);
    cout << (res < INF ? res : -1) << endl;
}

int main(void) {
    init();
    process();
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/