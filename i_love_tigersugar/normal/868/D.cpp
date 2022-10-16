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

#define MAX_SIZE   333
#define MAX_LEN   50
#define MAX_BIT   25

string prefix[MAX_SIZE], suffix[MAX_SIZE];
set<int> covers[MAX_SIZE][MAX_BIT + 3];
int n, q;

void addMask(const string &s, set<int> covers[]) {
    REP(i, s.size()) {
        int mask = 0;
        REP(j, MAX_BIT) {
            if (i + j >= s.size()) break;
            mask = mask * 2 + s[i + j] - '0';
            covers[j + 1].insert(mask);
        }
    }
}

void init(void) {
    cin >> n;
    FOR(i, 1, n) {
        string s; cin >> s;
        prefix[i] = suffix[i] = s;
        addMask(s, covers[i]);
    }
}

string getSuffix(const string &s, int length) {
    return s.size() < length ? s : s.substr(s.size() - length);
}

int query(int id, int a, int b) {
    prefix[id] = prefix[a].size() < MAX_LEN ? (prefix[a] + prefix[b]).substr(0, MAX_LEN) : prefix[a];
    suffix[id] = suffix[b].size() < MAX_LEN ? getSuffix(suffix[a] + suffix[b], MAX_LEN) : suffix[b];

    FOR(j, 1, MAX_BIT) {
        FORE(it, covers[a][j]) covers[id][j].insert(*it);
        FORE(it, covers[b][j]) covers[id][j].insert(*it);
    }

    addMask(suffix[a] + prefix[b], covers[id]);
    FOR(j, 1, MAX_BIT) if (covers[id][j].size() < MASK(j)) return j - 1;
    assert(false);
}

void process(void) {
    cin >> q;
    FOR(i, n + 1, n + q) {
        int a, b; cin >> a >> b;
        cout << query(i, a, b) << "\n";
    }
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/