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

#define MAX   1000100

int a[MAX], n;
int leftMin[MAX], leftMax[MAX], rightMin[MAX], rightMax[MAX];

void init(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &a[i]);
}

void calcRange(int left[], int right[]) {
    stack<int> st;
    FOR(i, 1, n) {
        while (!st.empty() && a[st.top()] < a[i]) st.pop();
        left[i] = st.empty() ? 1 : st.top() + 1;
        while (!st.empty() && a[st.top()] <= a[i]) st.pop();
        st.push(i);
    }

    while (!st.empty()) st.pop();
    FORD(i, n, 1) {
        while (!st.empty() && a[st.top()] <= a[i]) st.pop();
        right[i] = st.empty() ? n : st.top() - 1;
        st.push(i);
    }
}

void process(void) {
    calcRange(leftMax, rightMax);
    FOR(i, 1, n) a[i] *= -1;
    calcRange(leftMin, rightMin);
    FOR(i, 1, n) a[i] *= -1;

    long long res = 0;
    FOR(i, 1, n) res += 1LL * a[i] * (rightMax[i] - i + 1) * (i - leftMax[i] + 1);
    FOR(i, 1, n) res -= 1LL * a[i] * (rightMin[i] - i + 1) * (i - leftMin[i] + 1);
    cout << res << endl;
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/