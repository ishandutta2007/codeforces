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

/* Author: Van Hanh Pham - skyvn97 */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

#define MAX   200200

int input[MAX], answer[MAX];
int n, m;

void init(void) {
    scanf("%d%d", &n, &m);
    FOR(i, 1, n) scanf("%d", &input[i]);
}

void noAnswer(void) {
    printf("-1\n");
    exit(0);
}

void process(void) {
    FOR(i, 1, n) answer[i] = input[i];
    set<int> values;
    FOR(i, 1, n) {
        if (values.find(answer[i]) != values.end()) answer[i] = -1;
        else values.insert(answer[i]);
    }

    int numOdd = 0, numEven = 0;
    FOR(i, 1, n) if (answer[i] > 0) {
        if (answer[i] % 2 == 0) numEven++; else numOdd++;
    }

    FOR(i, 1, n) if (answer[i] > 0) {
        if (answer[i] % 2 == 0 && numEven > n / 2) {
            values.erase(answer[i]);
            answer[i] = -1;
            numEven--;
        }
        if (answer[i] % 2 == 1 && numOdd > n / 2) {
            values.erase(answer[i]);
            answer[i] = -1;
            numOdd--;
        }
    }

    queue<int> pos;
    FOR(i, 1, n) if (answer[i] < 0) pos.push(i);

    int val = 1;
    REP(love, n / 2 - numOdd) {
        if (pos.empty()) noAnswer();
        int cur = pos.front(); pos.pop();
        while (val <= m && values.find(val) != values.end()) val += 2;
        if (val > m) noAnswer();
        answer[cur] = val;
        values.insert(val);
    }

    val = 2;
    REP(love, n / 2 - numEven) {
        if (pos.empty()) noAnswer();
        int cur = pos.front(); pos.pop();
        while (val <= m && values.find(val) != values.end()) val += 2;
        if (val > m) noAnswer();
        answer[cur] = val;
        values.insert(val);
    }

    int res = 0;
    FOR(i, 1, n) if (answer[i] != input[i]) res++;
    printf("%d\n", res);
    FOR(i, 1, n) printf("%d ", answer[i]); printf("\n");
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/