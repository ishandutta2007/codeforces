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

#define MAX   100100

const string yes = "YES";
const string no = "NO";
const string sizeName[] = {"S", "M", "L", "XL", "XXL", "XXXL"};
const int numSize = 6;

vector<int> singleReq[10], doubleReq[10];
string answer[MAX];
int have[10], n;

void noAnswer(void) {
    cout << "NO" << endl;
    exit(0);
}

void process(void) {
    REP(i, numSize) cin >> have[i]; cin >> n;
    FOR(i, 1, n) {
        string req; cin >> req;
        REP(j, numSize) if (req == sizeName[j]) singleReq[j].push_back(i);
        REP(j, numSize - 1) if (req == sizeName[j] + "," + sizeName[j + 1]) doubleReq[j].push_back(i);
    }

    REP(i, numSize) {
        if (have[i] < singleReq[i].size()) noAnswer();
        have[i] -= singleReq[i].size();
        FORE(it, singleReq[i]) answer[*it] = sizeName[i];
    }

    REP(i, numSize - 1) {
        if (have[i] + have[i + 1] < doubleReq[i].size()) noAnswer();
        FOR(j, i, i + 1) while (!doubleReq[i].empty() && have[j] > 0) {
            have[j]--;
            answer[doubleReq[i].back()] = sizeName[j];
            doubleReq[i].pop_back();
        }
    }

    cout << yes << "\n";
    FOR(i, 1, n) cout << answer[i] << "\n";
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/