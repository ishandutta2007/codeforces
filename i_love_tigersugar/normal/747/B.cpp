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
const string noAns = "===";
const char ch[] = "ACGT";

void noAnswer(void) {
    cout << noAns << endl;
    exit(0);
}

void process(void) {
    queue<int> q;
    int n; cin >> n;
    string s; cin >> s;
    int cnt[4]; memset(cnt, 0, sizeof cnt);

    REP(i, s.size()) {
        if (s[i] == '?') q.push(i);
        REP(j, 4) if (s[i] == ch[j]) cnt[j]++;
    }

    if (n % 4 != 0) noAnswer();
    REP(i, 4) if (cnt[i] > n / 4) noAnswer();

    REP(i, 4) while (cnt[i] < n / 4) {
        if (q.empty()) noAnswer();
        int pos = q.front(); q.pop();
        s[pos] = ch[i];
        cnt[i]++;
    }
    cout << s << endl;
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/