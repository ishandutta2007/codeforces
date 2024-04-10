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

#define MAX   1111
#define LOG   10
const int INF = (int)1e9 + 7;

int answer[MAX], minValue[MAX][LOG + 1][2];
int a[MAX][MAX];
int n;

void init(void) {
    cin >> n;
#ifndef ONLINE_JUDGE
    REP(i, n) REP(j, n) cin >> a[i][j];
#endif // ONLINE_JUDGE
}

vector<int> ask(const vector<int> &indeces) {
    if (indeces.empty()) return vector<int>();
#ifdef ONLINE_JUDGE
    cout << indeces.size() << "\n";
    FORE(it, indeces) cout << *it + 1 << " ";
    cout << endl;

    vector<int> res;
    REP(love, n) {
        int x; cin >> x;
        res.push_back(x);
    }
    return res;
#else
    vector<int> res;
    REP(i, n) {
        int tmp = INF;
        FORE(it, indeces) minimize(tmp, a[i][*it]);
        res.push_back(tmp);
    }
    return res;
#endif // ONLINE_JUDGE
}

void conclude(const vector<int> &res) {
    cout << -1 << "\n";
    FORE(it, res) cout << *it << " ";
    cout << endl;
}

void getInfo(int pos, int bit) {
    vector<int> indeces;
    REP(i, n) if (BIT(i, pos) == bit) indeces.push_back(i);
    if (indeces.empty()) {
        REP(i, n) minValue[i][pos][bit] = INF;
        return;
    }

    vector<int> res = ask(indeces);
    REP(i, n) minValue[i][pos][bit] = res[i];
}
void process(void) {
    REP(i, LOG) REP(j, 2) getInfo(i, j);
    memset(answer, 0x3f, sizeof answer);
    REP(i, n) REP(j, LOG) REP(k, 2) if (BIT(i, j) != k) minimize(answer[i], minValue[i][j][k]);
    conclude(vector<int>(answer, answer + n));
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/