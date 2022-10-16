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
#define index   ___index
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

class SegmentTree {
    private:
    vector<bool> active;
    vector<int> cnt;
    vector<long long> sum;
    int n;

    void update(int pos, int type, int value) {
        int i = 1;
        int L = 1;
        int R = n;
        while (true) {
            cnt[i] += type;
            sum[i] += value;
            if (L == R) return;
            int M = (L + R) >> 1;
            if (pos > M) {
                i = 2 * i + 1;
                L = M + 1;
            } else {
                i = 2 * i;
                R = M;
            }
        }
    }

    public:
    SegmentTree(int n = 0) {
        this->n = n;
        active.assign(n + 7, false);
        cnt.assign(4 * n + 7, 0);
        sum.assign(4 * n + 7, 0);
    }

    void insert(int pos, int value) {
        if (pos < 1 || pos > n) return;
        if (active[pos]) return;
        active[pos] = true;
        update(pos, 1, value);
    }
    void remove(int pos, int value) {
        if (pos < 1 || pos > n) return;
        if (!active[pos]) return;
        active[pos] = false;
        update(pos, -1, -value);
    }

    long long getSum(int k) const {
        if (k == 0) return 0;
        if (cnt[1] <= k) return sum[1];
        int i = 1;
        int L = 1;
        int R = n;
        long long res = 0;
        while (true) {
            if (L == R) return res + sum[i];
            int M = (L + R) >> 1;
            if (cnt[2 * i] < k) {
                res += sum[2 * i];
                k -= cnt[2 * i];
                i = 2 * i + 1;
                L = M + 1;
            } else {
                i = 2 * i;
                R = M;
            }
        }
    }

    void debug(void) {
        printf("Tree info: ");
        FOR(i, 1, n) if (active[i]) printf("%d ", i); printf("\n");
    }
};

#define MAXN   200200
#define MAXV   5050

int dur[MAXN], reduce[MAXN], value[MAXN], index[MAXN];
long long sumDur[MAXN], sumValue[MAXN];
int n, allowTime, allowReduce;

void init(void) {
    scanf("%d%d%d", &n, &allowReduce, &allowTime);
    FOR(i, 1, n) scanf("%d", &value[i]);
    FOR(i, 1, n) scanf("%d", &dur[i]);
    FOR(i, 1, n) reduce[i] = dur[i] / 2;
}

bool compReduce(const int &x, const int &y) {
    return reduce[x] > reduce[y];
}
void process(void) {
    vector<int> v;
    FOR(i, 1, n) v.push_back(i);
    sort(ALL(v), compReduce);
    REP(i, n) index[v[i]] = i + 1;
//    FOR(i, 1, n) printf("%d ", index[i]); printf("\n");

    FOR(i, 1, n) sumDur[i] = sumDur[i - 1] + dur[i];
    FOR(i, 1, n) sumValue[i] = sumValue[i - 1] + value[i];

    SegmentTree myit(n);

    long long res = 0;
    int j = 1;
    myit.insert(index[1], reduce[1]);
    FOR(i, 1, n) {
        if (j < i) {
            j = i;
            myit.insert(index[i], reduce[i]);
        }
        while (j <= n) {
            long long needTime = sumDur[j] - sumDur[i - 1] - myit.getSum(allowReduce);
//            myit.debug();
//            printf("From %d to %d need %lld\n", i, j, needTime);
            if (needTime > allowTime) {
                myit.remove(index[j], reduce[j]);
                j--;
                break;
            }
            if (j == n) break;
            j++;
            myit.insert(index[j], reduce[j]);
        }

        if (j >= i) {
//            printf("Best of %d is %d\n", i, j);
            maximize(res, sumValue[j] - sumValue[i - 1]);
            myit.remove(index[i], reduce[i]);
        }
    }

    cout << res << endl;
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