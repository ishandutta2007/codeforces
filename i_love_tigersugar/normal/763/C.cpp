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

void answer(int start, int diff = -1) {
    if (diff < 0) printf("-1\n"); else printf("%d %d\n", start, diff);
    exit(0);
}

int inverse(int x, int mod) {
    int res = 1;
    int mul = x;
    int k = mod - 2;

    while (k > 0) {
        if (k & 1) res = 1LL * res * mul % mod;
        mul = 1LL * mul * mul % mod;
        k >>= 1;
    }

    assert(1LL * res * x % mod == 1);
    return res;
}

int findDiff(vector<int> seq, int mod) {
    int n = seq.size();

    if (n < 2) return 1;

    if (2 * n > mod) {
        set<int> s(ALL(seq));
        vector<int> v;
        REP(i, mod) if (s.find(i) == s.end()) v.push_back(i);
        return findDiff(v, mod);
    }

    REP(love, 2) {
        int tmp = love ? (seq[0] - seq[1] + mod) % mod : (seq[1] - seq[0] + mod) % mod;

        set<int> s(ALL(seq));
        int cntPair = 0;
        FORE(it, seq) if (s.find((*it + tmp) % mod) != s.end()) cntPair++;

        if (1 <= cntPair && cntPair < n) return 1LL * tmp * inverse(n - cntPair, mod) % mod;
    }

    return -1;

}

map<int, int> diffSeq;
void update(int key, int val) {
    //printf("UPDATE %d %d\n", key, val);

    diffSeq[key] += val;
    if (diffSeq[key] == 0) diffSeq.erase(key);
}

void solve(vector<int> seq, int mod) {
    int n = seq.size();
    if (n == mod) answer(seq[0], 1);
    if (n == 1) answer(seq[0], 1);

    int d = findDiff(seq, mod);
    if (d < 0) answer(-1);

    cerr << d << endl;

    FORE(it, seq) diffSeq[*it] = 1;

    REP(i, n) update((seq[0] + 1LL * i * d) % mod, -1);

    REP(i, n) {
        //printf("AT %d\n", i);

        if (diffSeq.empty()) answer((seq[0] - 1LL * i * d % mod + mod) % mod, d);
        update((seq[0] + 1LL * (n - i - 1) * d) % mod, 1);
        update((seq[0] - 1LL * (i + 1) * d % mod + mod) % mod, -1);
    }

    answer(-1);
}

void process(void) {
    int n, mod; scanf("%d%d", &mod, &n);
    vector<int> seq;
    REP(love, n) {
        int x; scanf("%d", &x);
        seq.push_back(x);
    }
    solve(seq, mod);
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/