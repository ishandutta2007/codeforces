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

string findPath(int n, long long node) {
    string res;

    while (true) {
        assert(1 <= node && node < MASK(n));
        if (node == MASK(n - 1)) break;
        if (node < MASK(n - 1)) res.push_back('L');
        else {
            res.push_back('R');
            node -= MASK(n - 1);
        }
        n--;
    }

    return res;
}

long long findNode(int n, const string &path) {
    long long res = 0;

    FORE(it, path) {
        if (*it == 'R') res += MASK(n - 1);
        else assert(*it == 'L');
        n--;
    }
    return res + MASK(n - 1);
}

long long answer(int n, long long node, const string &path) {
    string rootPath = findPath(n, node);

    FORE(it, path) {
        if (*it == 'U') {
            if (!rootPath.empty()) rootPath.pop_back();
        } else if (rootPath.size() + 1 < n) rootPath.push_back(*it);
    }

    return findNode(n, rootPath);
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);

    long long tmp;
    int n, q; cin >> tmp >> q;
    REP(i, 61) if (MASK(i) - 1 == tmp) n = i;

    REP(love, q) {
        long long x;
        string s; cin >> x >> s;
        cout << answer(n, x, s) << "\n";
    }
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/