#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define IS_INF(x)   (std::isinf(x))
#define IS_NAN(x)   (std::isnan(x))
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

#define tget(i) BIT(t[(i) >> 3], (i) & 7)
#define tset(i, b) { if (b) t[(i) >> 3] |= MASK((i) & 7); else t[(i) >> 3] &= ~MASK((i) & 7); }
#define chr(i) (cs == sizeof(int) ? ((int *)s)[i] : ((unc *)s)[i])
#define isLMS(i) ((i) > 0 && tget(i) && !tget((i) - 1))

typedef unsigned char unc;
class SuffixArray {
    public:
    int *sa, *lcp, *rank, n;
    unc *s;
    void getbuckets(unc s[], vector<int> &bkt, int n, int k, int cs, bool end) {
        FOR(i, 0, k) bkt[i] = 0;
        REP(i, n) bkt[chr(i)]++;
        int sum = 0;
        FOR(i, 0, k) {
            sum += bkt[i];
            bkt[i] = end ? sum : sum - bkt[i];
        }
    }
    void inducesal(vector<unc> &t, int sa[], unc s[], vector<int> &bkt, int n, int k, int cs, bool end) {
        getbuckets(s, bkt, n, k, cs, end);
        REP(i, n) {
            int j = sa[i] - 1;
            if (j >= 0 && !tget(j)) sa[bkt[chr(j)]++] = j;
        }
    }
    void inducesas(vector<unc> &t, int sa[], unc s[], vector<int> &bkt, int n, int k, int cs, bool end) {
        getbuckets(s, bkt, n, k, cs, end);
        FORD(i, n - 1, 0) {
            int j = sa[i] - 1;
            if (j >= 0 && tget(j)) sa[--bkt[chr(j)]]=j;
        }
    }
    void build(unc s[], int sa[], int n, int k, int cs) {
        int j;
        vector<unc> t = vector<unc>(n / 8 + 1, 0);
        tset(n - 2, 0);
        tset(n - 1, 1);
        FORD(i, n - 3, 0) tset(i, chr(i) < chr(i+1) || (chr(i) == chr(i+1) && tget(i+1)));
        vector<int> bkt = vector<int> (k + 1, 0);
        getbuckets(s, bkt, n, k, cs, true);
        REP(i, n) sa[i] = -1;
        REP(i, n) if (isLMS(i)) sa[--bkt[chr(i)]] = i;
        inducesal(t, sa, s, bkt, n, k, cs, false);
        inducesas(t, sa, s, bkt, n, k, cs, true);
        bkt.clear();
        int n1 = 0;
        REP(i, n) if (isLMS(sa[i])) sa[n1++] = sa[i];
        FOR(i, n1, n - 1) sa[i] = -1;
        int name = 0;
        int prev = -1;
        REP(i, n1) {
            int pos = sa[i];
            bool diff = false;
            REP(d, n) {
                if (prev < 0 || chr(prev + d) != chr(pos + d) || tget(prev + d) != tget(pos + d)) {
                    diff = true;
                    break;
                }
                else if (d > 0 && (isLMS(prev + d) || isLMS(pos + d))) break;
            }
            if (diff) {
                name++;
                prev = pos;
            }
            sa[n1 + pos / 2] = name - 1;
        }
        j = n - 1;
        FORD(i, n - 1, n1) if (sa[i] >= 0) sa[j--] = sa[i];
        int *sa1 = sa;
        int *s1 = sa + n - n1;
        if (name < n1) build((unc *)s1, sa1, n1, name-1, sizeof(int));
        else REP(i, n1) sa1[s1[i]] = i;
        bkt.assign(k + 1, 0);
        getbuckets(s, bkt, n, k, cs, true);
        j = 0;
        REP(i, n) if (isLMS(i)) s1[j++] = i;
        REP(i, n1) sa1[i] = s1[sa1[i]];
        FOR(i, n1, n - 1) sa[i] = -1;
        FORD(i, n1 - 1, 0) {
            j = sa[i];
            sa[i] = -1;
            sa[--bkt[chr(j)]] = j;
        }
        inducesal(t, sa, s, bkt, n, k, cs, false);
        inducesas(t, sa, s, bkt, n, k, cs, true);
        bkt.clear();
        t.clear();
    }
    void calc_lcp(void) {
        FOR(i, 1, n) rank[sa[i]] = i;
        int h = 0;
        REP(i, n) if (rank[i] < n) {
            int j = sa[rank[i] + 1];
            while (s[i + h] == s[j + h]) h++;
            lcp[rank[i]] = h;
            if (h > 0) h--;
        }
    }
    SuffixArray() {
        n = 0;
        sa = lcp = rank = NULL;
        s=NULL;
    }
    SuffixArray(const string &ss) {
        n = ss.size();
        sa = new int[n + 7];
        lcp = new int [n + 7];
        rank = new int [n + 7];
        s = (unc *)ss.c_str();
        build(s, sa, n + 1, 256, sizeof(char));
        calc_lcp();
    }
};

// Sorted suffices are SA[1] to SA[N]. The values of SA[1], SA[2], ..., SA[N] are 0, 1, ..., N - 1
// The longest common prefix of SA[i] and SA[i + 1] is LCP[i]
// rank[i] is the position of the i-th suffix. The values of rank[0], rank[1],..., rank[N - 1] are 1, 2, ..., N

/** END OF TEMPLATE. DRINK A CUP OF TIGERSUGAR BEFORE READING MY CODE. **/

#define MAX   100100
#define LENGTH   3333333
#define LOG   22
const string SPECIAL = "$";

int numSmall;
string big, small[MAX], combined;
SuffixArray sa;
int firstPosInCombined[MAX];
int left[LENGTH], right[LENGTH];
int rmq[LENGTH][LOG + 1];
int numBigSuffix[LENGTH];
bool used[LENGTH];

void init(void) {
    cin >> big >> numSmall;
    FOR(i, 1, numSmall) cin >> small[i];
}

void buildSuffixArray(void) {
    combined = big;
    FOR(i, 1, numSmall) {
        combined += SPECIAL;
        firstPosInCombined[i] = combined.size();
        REP(love, 2) combined += small[i];
    }

    sa = SuffixArray(combined);
    FOR(i, 1, combined.size()) numBigSuffix[i] = numBigSuffix[i - 1] + (sa.sa[i] < (int)big.size());

//    FOR(i, 1, combined.size()) {
//        printf("#%d: %s (lcp = %d)\n", i, combined.substr(sa.sa[i]).c_str(), sa.lcp[i]);
//    }
}

void calcRMQRight(void) {
    FOR(i, 1, combined.size() - 1) rmq[i][0] = sa.lcp[i];
    FOR(j, 1, LOG) FOR(i, 1, combined.size() - MASK(j)) rmq[i][j] = min(rmq[i][j - 1], rmq[i + MASK(j - 1)][j - 1]);
}

int rangeRight(int pos, int delta) {
    int res = 0;
    FORD(j, LOG, 0) if (pos + MASK(j) - 1 <= (int)combined.size() - 1 && rmq[pos][j] >= delta) {
        res += MASK(j); pos += MASK(j);
    }
    return res;
}

void calcRMQLeft(void) {
    FORD(i, combined.size() - 1, 1) rmq[i][0] = sa.lcp[i];
    FOR(j, 1, LOG) FORD(i, combined.size() - 1, MASK(j)) rmq[i][j] = min(rmq[i][j - 1], rmq[i - MASK(j - 1)][j - 1]);
}

int rangeLeft(int pos, int delta) {
    int res = 0;
    FORD(j, LOG, 0) if (pos >= MASK(j) && rmq[pos][j] >= delta) {
        res += MASK(j); pos -= MASK(j);
    }
    return res;
}

void calcRange(void) {
    calcRMQRight();
    FOR(i, 1, numSmall) {
        int delta = small[i].size();
        REP(j, delta) {
            int pos = sa.rank[firstPosInCombined[i] + j];
            right[pos] = pos + rangeRight(pos, delta);
        }
    }

    calcRMQLeft();
    FOR(i, 1, numSmall) {
        int delta = small[i].size();
        REP(j, delta) {
            int pos = sa.rank[firstPosInCombined[i] + j];
            left[pos] = pos - rangeLeft(pos - 1, delta);
        }
    }
}

void solve(void) {
    FOR(i, 1, numSmall) {
        int res = 0;
        REP(j, small[i].size()) {
            int pos = sa.rank[firstPosInCombined[i] + j];
            int L = left[pos], R = right[pos];
            if (used[L]) continue;
            used[L] = true;
            res += numBigSuffix[R] - numBigSuffix[L - 1];
        }

        printf("%d ", res);

        REP(j, small[i].size()) {
            int pos = sa.rank[firstPosInCombined[i] + j];
            used[left[pos]] = false;
        }
    }

    printf("\n");
}

int main(void) {
    ios::sync_with_stdio(false);
    init();
    buildSuffixArray();
    calcRange();
    solve();
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/