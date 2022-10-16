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

struct Person {
    int need, valueA, valueB;

    Person() {
        need = valueA = valueB = 0;
    }

    void input(void) {
        scanf("%d%d%d", &need, &valueA, &valueB);
    }
};

const int DELTA = 100;

#define MAX   200200
Person people[MAX];
int n, capa;
vector<int> likeA, likeB, same;

bool compDiff(const int &x, const int &y) {
    return Abs(people[x].valueA - people[x].valueB) > Abs(people[y].valueA - people[y].valueB);
}
void init(void) {
    scanf("%d%d", &n, &capa);
    FOR(i, 1, n) people[i].input();
    FOR(i, 1, n) {
        if (people[i].valueA > people[i].valueB) likeA.push_back(i);
        else if (people[i].valueB > people[i].valueA) likeB.push_back(i);
        else same.push_back(i);
    }

    sort(ALL(likeA), compDiff);
    sort(ALL(likeB), compDiff);
}

long long calcProfit(long long numA, long long numB) {
    long long sum = 0;
    queue<int> qa, qb;
    FORE(it, likeA) qa.push(*it);
    FORE(it, likeB) qb.push(*it);

    while (!qa.empty()) {
        Person &cur = people[qa.front()]; qa.pop();
        int use = min(numA, 1LL * cur.need);
        numA -= use;
        sum += 1LL * use * cur.valueA + 1LL * (cur.need - use) * cur.valueB;
    }

    while (!qb.empty()) {
        Person &cur = people[qb.front()]; qb.pop();
        int use = min(numB, 1LL * cur.need);
        numB -= use;
        sum += 1LL * use * cur.valueB + 1LL * (cur.need - use) * cur.valueA;
    }

    FORE(it, same) sum += 1LL * people[*it].need * people[*it].valueA;
    return sum;
}

void process(void) {
    long long sumNeed = 0;
    FOR(i, 1, n) sumNeed += people[i].need;
    long long numCake = sumNeed / capa + (sumNeed % capa > 0);

    long long sumA = 0, sumB = 0;
    FORE(it, likeA) sumA += people[*it].need;
    FORE(it, likeB) sumB += people[*it].need;

    long long expA = sumA / capa, expB = sumB / capa;
    long long best = 0;
    FOR(i, -DELTA, DELTA) {
        long long na = expA + i;
        long long nb = numCake - na;
        if (na < 0 || nb < 0) continue;
        maximize(best, calcProfit(1LL * na * capa, 1LL * nb * capa));
    }

    FOR(i, -DELTA, DELTA) {
        long long nb = expB + i;
        long long na = numCake - nb;
        if (na < 0 || nb < 0) continue;
        maximize(best, calcProfit(1LL * na * capa, 1LL * nb * capa));
    }

    cout << best << endl;
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/