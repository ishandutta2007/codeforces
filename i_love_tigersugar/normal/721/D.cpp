#include<bits/stdc++.h>
#define MAX   200200
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
int n, delta, allow;
long long a[MAX];
int getSign(long long x) {
    if (x < 0) return -1;
    if (x == 0) return 0;
    return 1;
}
void init(void) {
    cin >> n >> allow >> delta;
    FOR(i, 1, n) cin >> a[i];
}
bool canNegative(void) {
    int sign = 1;
    FOR(i, 1, n) sign *= getSign(a[i]);
    if (sign < 0) return true;
    int cntZero = 0;
    FOR(i, 1, n) if (a[i] == 0) cntZero++;
    if (cntZero > allow) return false;
    if (cntZero > 0) return true;
    FOR(i, 1, n) if (Abs(a[i]) < 1LL * delta * allow) return true;
    return false;
}
bool canZero(void) {
    FOR(i, 1, n) if (Abs(a[i]) % delta == 0  && Abs(a[i]) <= 1LL * delta * allow) return true;
    return false;
}
void negativeCase(void) {
    int preSign = 1;
    FOR(i, 1, n) preSign *= getSign(a[i]);
    if (preSign == 0) {
        int zeroID = -1;
        FOR(i, 1, n) if (a[i] == 0) {
            zeroID = i;
            a[i] = delta;
            allow--;
        }
        int tmpSign = 1;
        FOR(i, 1, n) tmpSign *= getSign(a[i]);
        assert(tmpSign != 0);
        if (tmpSign > 0) a[zeroID] *= -1;
    } else if (preSign > 0) {
        int minABS = 1;
        FOR(i, 2, n) if (Abs(a[i]) < Abs(a[minABS])) minABS = i;
        int oldSign = getSign(a[minABS]);
        while (getSign(a[minABS]) != -oldSign) {
            allow--;
            a[minABS] -= oldSign * delta;
        }
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > q;
    FOR(i, 1, n) q.push(make_pair(Abs(a[i]), i));
    REP(love, allow) {
        pair<long long, int> tmp = q.top(); q.pop();
        tmp.fi += delta;
        if (getSign(a[tmp.se]) == getSign(tmp.fi)) a[tmp.se] += delta;
        else a[tmp.se] -= delta;
        q.push(tmp);
    }
}
void zeroCase(void) {
    FOR(i, 1, n) if (Abs(a[i]) % delta == 0 && Abs(a[i]) <= 1LL * delta * allow) {
        a[i] = 0;
        return;
    }
    assert(false);
}
void positiveCase(void) {
    priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > q;
    FOR(i, 1, n) q.push(make_pair(Abs(a[i]), i));
    REP(love, allow) {
        pair<long long, int> tmp = q.top(); q.pop();
        tmp.fi -= delta;
        if (getSign(a[tmp.se]) == getSign(tmp.fi)) a[tmp.se] -= delta;
        else a[tmp.se] += delta;
        q.push(tmp);
    }
}
void process(void) {
    if (canNegative()) negativeCase();
    else if (canZero()) zeroCase();
    else positiveCase();
    FOR(i, 1, n) cout << a[i] << " "; cout << endl;
}
int main(void) {
    init();
    process();
    return 0;
}