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

const int MOD = (int)1e9 + 7;

#define SQR(x) (1LL * (x) * (x) % MOD)

void add(int &x, const int &y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

void sub(int &x, const int &y) {
    x -= y;
    if (x < 0) x += MOD;
}

#define ARRAY_SIZE   12][12][12][12][12][12
int cnt[ARRAY_SIZE], sum[ARRAY_SIZE], sumSQR[ARRAY_SIZE];

#define MAX   1000100
int pw2[MAX];

void init(void) {
    int n; scanf("%d", &n);
    REP(love, n) {
        int x; scanf("%d", &x);
        int dig[6];
        int oldX = x;
        REP(i, 6) {
            dig[i] = x % 10;
            x /= 10;
        }

        #define DIGITS dig[0]][dig[1]][dig[2]][dig[3]][dig[4]][dig[5]
        add(cnt[DIGITS], 1);
        add(sum[DIGITS], oldX);
        add(sumSQR[DIGITS], SQR(oldX));
        #undef DIGITS
    }

    pw2[0] = 1;
    FOR(i, 1, MAX - 1) pw2[i] = pw2[i - 1] * 2 % MOD;
}

int getValue(int cnt, int sum, int sumSQR) {
    if (cnt == 0) return 0;
    if (cnt == 1) return sumSQR;
    return 1LL * pw2[cnt - 2] * (SQR(sum) + sumSQR) % MOD;
}

void process(void) {
    FORD(a, 9, 0) FORD(b, 9, 0) FORD(c, 9, 0) FORD(d, 9, 0) FORD(e, 9, 0) FORD(f, 9, 0)
        FOR(mask, 1, MASK(6) - 1) {
            int newA = a + BIT(mask, 0);
            int newB = b + BIT(mask, 1);
            int newC = c + BIT(mask, 2);
            int newD = d + BIT(mask, 3);
            int newE = e + BIT(mask, 4);
            int newF = f + BIT(mask, 5);

            #define CUR_INDEX a][b][c][d][e][f
            #define NEW_INDEX newA][newB][newC][newD][newE][newF

            if (__builtin_popcount(mask) % 2 == 1) {
                add(cnt[CUR_INDEX], cnt[NEW_INDEX]);
                add(sum[CUR_INDEX], sum[NEW_INDEX]);
                add(sumSQR[CUR_INDEX], sumSQR[NEW_INDEX]);
            } else {
                sub(cnt[CUR_INDEX], cnt[NEW_INDEX]);
                sub(sum[CUR_INDEX], sum[NEW_INDEX]);
                sub(sumSQR[CUR_INDEX], sumSQR[NEW_INDEX]);
            }
        }

    long long result = 0;

    FORD(a, 9, 0) FORD(b, 9, 0) FORD(c, 9, 0) FORD(d, 9, 0) FORD(e, 9, 0) FORD(f, 9, 0) {
        int total = 0;

        int value = f;
        value = value * 10 + e;
        value = value * 10 + d;
        value = value * 10 + c;
        value = value * 10 + b;
        value = value * 10 + a;

        REP(mask, MASK(6)) {
            int newA = a + BIT(mask, 0);
            int newB = b + BIT(mask, 1);
            int newC = c + BIT(mask, 2);
            int newD = d + BIT(mask, 3);
            int newE = e + BIT(mask, 4);
            int newF = f + BIT(mask, 5);

//            if ((value == 123 || value == 321 || value == 121) && cnt[NEW_INDEX] > 0) {
//                printf("With %d%d%d%d%d%d cnt = %d, sum = %d, sumSQR = %d\n", newF, newE, newD, newC, newB, newA,
//                       cnt[NEW_INDEX], sum[NEW_INDEX], sumSQR[NEW_INDEX]);
//            }

            if (__builtin_popcount(mask) % 2 == 0)
                add(total, getValue(cnt[NEW_INDEX], sum[NEW_INDEX], sumSQR[NEW_INDEX]));
            else sub(total, getValue(cnt[NEW_INDEX], sum[NEW_INDEX], sumSQR[NEW_INDEX]));
        }

        //if (total > 0) printf("FOR %d is %d\n", value, total);

        result ^= 1LL * value * total;
    }

    cout << result << endl;
}

int main(void) {
#ifdef SKY
    //freopen("tmp.txt", "r", stdin);
#endif // SKY
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/