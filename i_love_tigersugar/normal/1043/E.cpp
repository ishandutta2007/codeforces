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

struct Person {
    int x, y, id;

    Person() {
        x = y = id = 0;
    }

    void input(int id) {
        this->id = id;
        scanf("%d%d", &x, &y);
    }

    bool operator < (const Person &p) const {
        return x - y < p.x - p.y;
    }
};

#define MAX   300300

Person people[MAX];
int numPerson, numPair;
pair<int, int> pairs[MAX];
long long sumX[MAX], sumY[MAX], res[MAX];
int pos[MAX];

void init(void) {
    scanf("%d%d", &numPerson, &numPair);
    FOR(i, 1, numPerson) people[i].input(i);
    FOR(i, 1, numPair) scanf("%d%d", &pairs[i].fi, &pairs[i].se);
}

long long match(int x, int y, int u, int v) {
    return min(x + v, y + u);
}

void process(void) {
    sort(people + 1, people + numPerson + 1);
    FOR(i, 1, numPerson) pos[people[i].id] = i;
//    FOR(i, 1, numPerson) printf("PER: x = %d, y = %d, id = %d\n", people[i].x, people[i].y, people[i].id);

    FOR(i, 1, numPerson) {
        sumX[i] = sumX[i - 1] + people[i].x;
        sumY[i] = sumY[i - 1] + people[i].y;
    }

    FOR(i, 1, numPerson) {
        res[people[i].id] = 1LL * (i - 1) * people[i].y + sumX[i - 1]
                    + 1LL * (numPerson - i) * people[i].x + sumY[numPerson] - sumY[i];
//        printf("Calc res %d = %lld\n", people[i].id, res[people[i].id]);
    }
//    FOR(i, 1, numPerson) cout << res[i] << " "; cout << endl;

    FOR(i, 1, numPair) {
        int a = pairs[i].fi;
        int b = pairs[i].se;
        int pa = pos[a];
        int pb = pos[b];
        long long tmp = match(people[pa].x, people[pa].y, people[pb].x, people[pb].y);
        res[a] -= tmp;
        res[b] -= tmp;
    }

    FOR(i, 1, numPerson) cout << res[i] << " "; cout << endl;
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/