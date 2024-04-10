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

const char YES[] = "YES";
const char NO[] = "NO";

const int SAME_SET = 1;
const int DIFF_SET = 2;
const int NO_RELATION = 3;

class DisjointSet {
private:
    vector<int> lab, high;

    int find(int x) {
        if (lab[x] < 0) return x;
        int p = find(lab[x]);
        high[x] += high[lab[x]];
        return lab[x] = p;
    }

    int getHigh(int x) {
        find(x);
        return high[x] % 2;
    }

public:
    DisjointSet(int n = 0) {
        lab.assign(n + 7, -1);
        high.assign(n + 7, 0);
    }

    bool sameSet(int a, int b) {
        return find(a) == find(b);
    }

    int query(int a, int b) {
        if (!sameSet(a, b)) return NO_RELATION;
        if (getHigh(a) == getHigh(b)) return SAME_SET; else return DIFF_SET;
    }

    bool join(int a, int b, int diffSet) {
        int x = find(a);
        int y = find(b);
        if (x == y) return (getHigh(a) ^ getHigh(b)) == diffSet;

        if (lab[x] > lab[y]) {
            swap(x, y);
            swap(a, b);
        }

        int highY = getHigh(y) == getHigh(b) ? getHigh(a) ^ diffSet : getHigh(a) ^ diffSet ^ 1;
        lab[x] += lab[y];
        lab[y] = x;
        high[y] = highY;
        return true;
    }
};

map<string, int> wordID;
int n, m, q;

#define MAX_LEN   222
char input[MAX_LEN];
string nextString(void) {
    scanf("%s", input);
    return input;
}

void init(void) {
    scanf("%d%d%d", &n, &m, &q);
    FOR(i, 1, n) wordID[nextString()] = i;
}

void process(void) {
    DisjointSet dsu(n);
    REP(love, m) {
        int type; scanf("%d", &type);
        string s = nextString();
        string t = nextString();
        printf("%s\n", dsu.join(wordID[s], wordID[t], type == 2) ? YES : NO);
    }
    REP(love, q) {
        string s = nextString();
        string t = nextString();
        printf("%d\n", dsu.query(wordID[s], wordID[t]));
    }
}

int main(void) {
#ifdef SKY
    freopen("tmp.txt", "r", stdin);
#endif // SKY
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/