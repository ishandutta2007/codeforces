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

set<string> names;

string randName(void) {
    string res(1, 'A' + rand() % 26);
    REP(love, 5) res.push_back('a' + rand() % 26);
    return res;
}

string newName(void) {
    while (true) {
        string s = randName();
        if (names.insert(s).se) return s;
    }
}

#define MAX   555

string input[MAX];
string res[MAX];
int n, k;
void process(void) {
    cin >> n >> k;

    FOR(i, 1, n - k + 1) cin >> input[i];

    FOR(i, 1, k - 1) res[i] = newName();
    FOR(i, k, n) res[i] = input[i - k + 1] == "YES" ? newName() : res[i - k + 1];
    FOR(i, 1, n) cout << res[i] << " "; cout << endl;
}

int main(void) {
    srand(220797);
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/