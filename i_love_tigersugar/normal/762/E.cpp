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

class FenwickTree {
private:
    vector<int> v;
    int n;

    int get(int x) const {
        int res = 0;
        for (; x >= 1; x &= x - 1) res += v[x];
        return res;
    }

public:
    FenwickTree(int n = 0) {
        this->n = n;
        if (n > 0) v.assign(n + 7, 0);
    }

    void update(int x) {
        for (; x <= n; x += x & -x) v[x]++;
    }

    int get(int l, int r) const {
        return l == 1 ? get(r) : get(r) - get(l - 1);
    }
};

struct Radio {
    int x, r, f;

    Radio() {
        x = r = f = 0;
    }

    void input(void) {
        scanf("%d%d%d", &x, &r, &f);
    }

    bool operator < (const Radio &a) const {
        return r > a.r;
    }
};

#define MAX   100100

int numRadio, freqDiff;
Radio radios[MAX];
vector<int> valuesOfFreq[MAX];
FenwickTree bitOfFreq[MAX];

void init(void) {
    scanf("%d%d", &numRadio, &freqDiff);
    FOR(i, 1, numRadio) radios[i].input();
}

void prepare(void) {
    FOR(i, 1, numRadio) valuesOfFreq[radios[i].f].push_back(radios[i].x);
    REP(i, MAX) if (!valuesOfFreq[i].empty()) {
        vector<int> &cur = valuesOfFreq[i];
        sort(ALL(cur));
        cur.resize(unique(ALL(cur)) - cur.begin());
        bitOfFreq[i] = FenwickTree(cur.size());
    }

    sort(radios + 1, radios + numRadio + 1);
}

int count(const vector<int> &values, const FenwickTree &bit, int L, int R) {
    int idL = lower_bound(ALL(values), L) - values.begin() + 1;
    int idR = upper_bound(ALL(values), R) - values.begin();
    return idL <= idR ? bit.get(idL, idR) : 0;
}

void process(void) {
    long long res = 0;

    FOR(i, 1, numRadio) {
        int L = radios[i].x - radios[i].r;
        int R = radios[i].x + radios[i].r;

        FOR(j, radios[i].f - freqDiff, radios[i].f + freqDiff)
            if (0 <= j && j < MAX) res += count(valuesOfFreq[j], bitOfFreq[j], L, R);

        int idX = lower_bound(ALL(valuesOfFreq[radios[i].f]), radios[i].x) - valuesOfFreq[radios[i].f].begin() + 1;
        bitOfFreq[radios[i].f].update(idX);
    }

    cout << res << endl;
}

int main(void) {
    init();
    prepare();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/