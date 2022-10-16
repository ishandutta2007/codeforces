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

#define MAX   1000100

char dir[MAX];
int numLeft, left[MAX], numRight, right[MAX];
int cntLeft[MAX], cntRight[MAX];
long long sumLeft[MAX], sumRight[MAX];

long long calcDisLeft(int pos, int num) {
    if (num == 0) return 0;
    int R = cntRight[pos - 1];
    int L = R - num + 1;
    return 1LL * pos * num - (sumRight[R] - sumRight[L - 1]);
}
long long calcDisRight(int pos, int num) {
    if (num == 0) return 0;
    int L = cntLeft[pos] + 1;
    int R = L + num - 1;
    return sumLeft[R] - sumLeft[L - 1] - 1LL * pos * num;
}
void process(void) {
    int n; scanf("%d", &n);
    scanf("%s", dir + 1);
    FOR(i, 1, n) dir[i] = dir[i] == 'U' ? 'R' : 'L';

    FOR(i, 1, n) {
        cntLeft[i] = cntLeft[i - 1];
        cntRight[i] = cntRight[i - 1];
        if (dir[i] == 'L') cntLeft[i]++; else cntRight[i]++;
        if (dir[i] == 'L') left[++numLeft] = i;
        else right[++numRight] = i;
    }
    FOR(i, 1, numLeft) sumLeft[i] = sumLeft[i - 1] + left[i];
    FOR(i, 1, numRight) sumRight[i] = sumRight[i - 1] + right[i];

    FOR(i, 1, n) {
        int moveLeft, moveRight;
        moveLeft = moveRight = min(cntRight[i - 1], cntLeft[n] - cntLeft[i]);
        if (dir[i] == 'R' && moveRight < cntLeft[n] - cntLeft[i]) moveRight++;
        if (dir[i] == 'L' && moveLeft < cntRight[i - 1]) moveLeft++;
        bool endLeft = cntRight[i - 1] != cntLeft[n] - cntLeft[i] ? cntRight[i - 1] < cntLeft[n] - cntLeft[i] : dir[i] == 'L';
        cout << 2 * calcDisLeft(i, moveLeft) + 2 * calcDisRight(i, moveRight) + (endLeft ? i : n - i + 1) << " ";
    }
    cout << endl;
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/