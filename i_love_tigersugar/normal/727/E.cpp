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

#define MAX   1212121
#define NMOD   2

const int mod[] = {(int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9+ 9277};
int pw[NMOD][MAX], base, inv[NMOD];

int inverse(int x, int mod) {
    int res = 1;
    int mul = x;
    int k = mod - 2;
    while (k > 0) {
        if (k & 1) res = 1LL * res * mul % mod;
        mul = 1LL * mul * mul % mod;
        k >>= 1;
    }
    return res;
}
void precalc(void) {
    srand(time(NULL));
    base = 300 + rand() % 300;

    REP(j, NMOD) {
        pw[j][0] = 1;
        FOR(i, 1, MAX - 1) pw[j][i] = 1LL * pw[j][i - 1] * base % mod[j];
    }
    REP(j, NMOD) inv[j] = inverse(base, mod[j]);
}

struct Hash {
    int val[NMOD];

    Hash() {
        memset(val, 0, sizeof val);
    }
    Hash(const string &s) {
        memset(val, 0, sizeof val);
        REP(j, NMOD) REP(i, s.size()) val[j] = (val[j] + 1LL * s[i] * pw[j][i]) % mod[j];
    }

    void add(char c, int pos) {
        REP(i, NMOD) val[i] = (val[i] + 1LL * c * pw[i][pos]) % mod[i];
    }
    void removeFirst(char c) {
        REP(i, NMOD) val[i] = 1LL * (val[i] - c + mod[i]) * inv[i] % mod[i];
    }
    bool operator < (const Hash &x) const {
        REP(i, NMOD) if (val[i] != x.val[i]) return val[i] < x.val[i];
        return false;
    }
};

const char yes[] = "YES";
const char no[] = "NO";

char bigStr[MAX];
int n, len;
map<Hash, int> words;
int wordID[MAX];

char input[MAX];
string nextString(void) {
    scanf("%s", input);
    return string(input);
}

void init(void) {
    scanf("%d%d", &n, &len);
    scanf("%s", bigStr + 1);
    int numWords; scanf("%d", &numWords);
    FOR(i, 1, numWords) words[nextString()] = i;
}

int getWordID(const Hash &x) {
    __typeof(words.begin()) it = words.find(x);
    return it == words.end() ? -1 : it->se;
}
void checkPos(int pos) {
    set<int> used;
    REP(i, n) {
        if (wordID[pos + i * len] < 0) return;
        if (!used.insert(wordID[pos + i *len]).se) return;
    }
    printf("%s\n", yes);
    REP(i, n) printf("%d\n", wordID[pos + i * len]);
    exit(0);
}
void process(void) {
    FOR(i, 1, len) bigStr[n * len + i] = bigStr[i];
    Hash tmp;
    FOR(i, 1, n * len + len) {
        tmp.add(bigStr[i], min(len - 1, i - 1));
        if (i >= len) {
            wordID[i - len + 1] = getWordID(tmp);
            tmp.removeFirst(bigStr[i - len + 1]);
        }
    }
    FOR(i, 1, len) checkPos(i);
    printf("%s\n", no);
}

int main(void) {
    precalc();
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/