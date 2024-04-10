#include<bits/stdc++.h>
#define MAXN   100100
#define MAXL   44
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
const int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
const int numPrime = 12;
struct PrimeFact {
    int base, exp, value;
    PrimeFact() {
        base = exp = value = 0;
    }
    PrimeFact(int base) {
        this->base = base;
        exp = 0;
        value = 1;
    }
};
int numSeq, maxVal, a[MAXN][MAXL], len[MAXN];
vector<PrimeFact> primeFacts[MAXL];
map<int, int> pos[MAXN];
map<pair<int, int>, int> haveMod[MAXL];
void init(void) {
    scanf("%d%d", &numSeq, &maxVal);
    REP(i, numSeq) {
        scanf("%d", &len[i]);
        REP(j, len[i]) scanf("%d", &a[i][j]);
    }
}
vector<PrimeFact> getPrimeFacts(int x) {
    vector<PrimeFact> facts;
    for (int i = 2; i * i <= x; i++) if (x % i == 0) {
        facts.push_back(PrimeFact(i));
        while (x % i == 0) {
            facts.back().exp++;
            facts.back().value *= i;
            x /= i;
        }
    }
    if (x > 1) {
        facts.push_back(PrimeFact(x));
        facts.back().exp = 1;
        facts.back().value = x;
    }
    return facts;
}
void prepare(void) {
    FOR(i, 2, MAXL - 1) primeFacts[i] = getPrimeFacts(i);
    REP(i, numSeq) REP(j, len[i]) pos[a[i][j]][i] = j;
}
bool okPrime(int prime) {
    pair<int, int> prev(-1, -1);
    map<pair<int, int>, int> &curMap = haveMod[prime];
    if (curMap.empty()) return true;
    FORE(it, curMap) {
        pair<int, int> cur = it->fi;
        if (prev.fi > 0) {
            if (cur.fi == prev.fi) return false;
            if (cur.se % prev.fi != prev.se) return false;
        }
        prev = cur;
    }
    return true;
}
bool ok(void) {
    REP(i, numPrime) if (!okPrime(prime[i])) return false;
    return true;
}
void insert(map<pair<int, int>, int> &mp, const pair<int, int> &key) {
    mp[key]++;
}
void remove(map<pair<int, int>, int> &mp, const pair<int, int> &key) {
    if (--mp[key] == 0) mp.erase(key);
}
int findMaxLen(int value, int left, int right) {
    int res = 1;
    int j = left;
    FORE(it, primeFacts[len[left]]) insert(haveMod[it->base], make_pair(it->value, pos[value][left] % it->value));
    FOR(i, left, right) {
        while (j <= right && ok()) {
            if (++j <= right) FORE(it, primeFacts[len[j]])
                insert(haveMod[it->base], make_pair(it->value, pos[value][j] % it->value));
        }
        maximize(res, j - i);
        FORE(it, primeFacts[len[i]]) remove(haveMod[it->base], make_pair(it->value, pos[value][i] % it->value));
    }
    return res;
}
int findMaxLen(int value) {
    vector<pair<int, int> > segments;
    vector<pair<int, int> > cur(ALL(pos[value]));
    FORE(it, cur) {
        if (segments.empty() || segments.back().se != it->fi - 1) segments.push_back(make_pair(it->fi, it->fi));
        else segments.back().se++;
    }
    int res = 0;
    //FORE(it, segments) printf("(%d %d) ", it->fi, it->se); printf("\n");
    FORE(it, segments) maximize(res, findMaxLen(value, it->fi, it->se));
    return res;
}
void process(void) {
    FOR(i, 1, maxVal) printf("%d\n", findMaxLen(i));
}
int main(void) {
#ifdef SKY
    freopen("tmp.txt", "r", stdin);
#endif // SKY
    init();
    prepare();
    process();
    return 0;
}