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
#define rank   ___rank
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

#define MAX   1010
#define NUM_DIG   1050

int n, addLen, numLen[MAX];
int digits[MAX][NUM_DIG + 3], toAdd[NUM_DIG + 3];
int order[NUM_DIG + 3][MAX], rank[NUM_DIG + 3][MAX];
int countRank[NUM_DIG + 3][11][MAX], countDigit[NUM_DIG + 3][11];
int postValue[MAX][2];
int value[11];
int f[NUM_DIG + 3][MAX];
char input[NUM_DIG + 3];

void init(void) {
    scanf("%s", input);
    addLen = strlen(input);
    reverse(input, input + addLen);
    REP(i, addLen) toAdd[i] = input[i] == '?' ? -1 : input[i] - '0';

    scanf("%d", &n);
    FOR(i, 1, n) {
        scanf("%s", input);
        numLen[i] = strlen(input);
        reverse(input, input + numLen[i]);
        REP(j, numLen[i]) digits[i][j] = input[j] - '0';
    }

    REP(i, 10) scanf("%d", &value[i]);
}

int calcPostValue(const string &s) {
    int res = 0;
    FORE(it, s) res += value[*it - '0'];
    return res;
}

int curPos;
bool compare(const int &x, const int &y) {
    if (digits[x][curPos] != digits[y][curPos]) return digits[x][curPos] > digits[y][curPos];
    return curPos == 0 ? false : rank[curPos - 1][x] < rank[curPos - 1][y];
}
void prepare(void) {
    REP(i, NUM_DIG) {
        curPos = i;
        FOR(j, 1, n) order[i][j] = j;
        sort(order[i] + 1, order[i] + n + 1, compare);
        FOR(j, 1, n) rank[i][order[i][j]] = j;

        FOR(j, 1, n) countRank[i + 1][digits[j][i + 1]][rank[i][j]]++;
        REP(j, 10) FOR(k, 1, n) countRank[i + 1][j][k] += countRank[i + 1][j][k - 1];

        FOR(j, 1, n) countDigit[i][digits[j][i]]++;
    }

    FOR(i, 1, n) {
        if (numLen[i] <= addLen) {
            postValue[i][0] = 0;
            postValue[i][1] = value[1];
            continue;
        }

        string post;
        FOR(j, addLen, numLen[i] - 1) post.push_back(digits[i][j] + '0');
        postValue[i][0] = calcPostValue(post);
        int j = 0;
        while (j < post.size() && post[j] == '9') post[j++] = '0';
        if (j == post.size()) post.push_back('1'); else post[j]++;
        postValue[i][1] = calcPostValue(post);
    }
}

int getSum(int sum[], int l, int r) {
    if (l > r) return 0;
    return l == 0 ? sum[r] : sum[r] - sum[l - 1];
}

void optimize(void) {
    memset(f, -1, sizeof f);
    f[0][0] = 0;
    REP(i, addLen) {
        int countRem[11];
        memset(countRem, 0, sizeof countRem);

        REP(j, n + 1) {
            if (j > 0 && i > 0) {
                int pos = order[i - 1][j];
                countRem[digits[pos][i]]++;
            }
            if (f[i][j] < 0) continue;

            //printf("F %d %d = %d\n", i, j, f[i][j]);

            REP(k, 10) {
                if (toAdd[i] != -1 && toAdd[i] != k) continue;
                if (i == addLen - 1 && k == 0) continue;

                int gain = 0, newRem = 0;
                REP(l, 10) {
                    //printf("AT l = %d\n", l);
                    int tot = countDigit[i][l];
                    int haveRem = countRem[l];

                    gain += haveRem * value[(k + l + 1) % 10] + (tot - haveRem) * value[(k + l) % 10];
                    if (k + l > 9) newRem += tot;
                    if (k + l == 9) newRem += getSum(countRank[i][l], 1, j);
                    //printf("%d\n", newRem);
                }

                maximize(f[i + 1][newRem], f[i][j] + gain);
            }
        }
    }

    int res = 0;
    REP(j, n + 1) {
        int tmp = f[addLen][j];
        if (tmp <= 0) continue;
        FOR(i, 1, n) tmp += rank[addLen - 1][i] <= j ? postValue[i][1] : postValue[i][0];
        maximize(res, tmp);
    }

    //FOR(i, 1, n) printf("Post of %d is %d and %d\n", i, postValue[i][0], postValue[i][1]);

    printf("%d\n", res);
}

int main(void) {
    init();
    prepare();
    optimize();
    return 0;
}


/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/