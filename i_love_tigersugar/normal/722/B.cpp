#include<bits/stdc++.h>
#define MAX   100100
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
const string vowel = "aeiouy";
const string yes = "YES";
const string no = "NO";
int n, p[MAX];
void process(void) {
    cin >> n;
    REP(i, n) cin >> p[i];
    REP(i, n) {
        string tmp; getline(cin, tmp);
        if (i == 0) getline(cin, tmp);
        int cnt = 0;
        FORE(it, tmp) FORE(jt, vowel) if (*it == *jt) cnt++;
        if (cnt != p[i]) {
            cout << no <<endl;
            return;
        }
    }
    cout << yes << endl;
}
int main(void) {
    process();
    return 0;
}