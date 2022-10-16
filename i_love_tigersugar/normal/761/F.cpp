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

struct Picture {
    int top, bot, left, right, ch;

    Picture() {
        top = bot = left = right = ch = 0;
    }

    void input(void) {
        scanf("%d%d%d%d", &top, &left, &bot, &right);
        char c; scanf(" %c", &c); ch = c - 'a';
    }
};

struct Event {
    int left, right, value;

    Event(int _left = 0, int _right = 0, int _value = 0) {
        left = _left; right = _right; value = _value;
    }
};

#define MAX_SIZE   1111
#define MAX_NUM   300300
#define NUM_CHAR   26
const long long INF = (long long)1e18 + 7LL;

char board[MAX_SIZE][MAX_SIZE];
int cntLetter[NUM_CHAR][MAX_SIZE][MAX_SIZE];
long long sumLetter[NUM_CHAR][MAX_SIZE][MAX_SIZE];
long long score[MAX_SIZE][MAX_SIZE], sumScore[MAX_SIZE][MAX_SIZE], totalScore;
int numRow, numCol, numPic;
Picture pictures[MAX_NUM];
vector<Event> events[NUM_CHAR][MAX_SIZE];

void init(void) {
    scanf("%d%d%d", &numRow, &numCol, &numPic);
    FOR(i, 1, numRow) scanf("%s", board[i] + 1);
    FOR(i, 1, numPic) pictures[i].input();
}

int tmpCnt[MAX_SIZE];

void countLetter(int charID) {
    memset(tmpCnt, 0, sizeof tmpCnt);

    FOR(i, 1, numRow) {
        FORE(it, events[charID][i]) {
            tmpCnt[it->left] += it->value;
            tmpCnt[it->right + 1] -= it->value;
        }

        int sum = 0;
        FOR(j, 1, numCol) {
            sum += tmpCnt[j];
            cntLetter[charID][i][j] = sum;
        }
    }
}

template<class Type>
    void calcPrefixSum(Type a[][MAX_SIZE], long long sum[][MAX_SIZE]) {
        FOR(i, 1, numRow) FOR(j, 1, numCol)
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
    }

void prepare(void) {
    FOR(i, 1, numPic) {
        events[pictures[i].ch][pictures[i].top].push_back(Event(pictures[i].left, pictures[i].right, 1));
        events[pictures[i].ch][pictures[i].bot + 1].push_back(Event(pictures[i].left, pictures[i].right, -1));
    }

    REP(i, NUM_CHAR) countLetter(i);

    FOR(i, 1, numRow) FOR(j, 1, numCol) {
        int tot = 0;
        REP(k, NUM_CHAR) tot += cntLetter[k][i][j];
        cntLetter[board[i][j] - 'a'][i][j] += numPic - tot;
    }

    REP(i, NUM_CHAR) calcPrefixSum(cntLetter[i], sumLetter[i]);

    FOR(i, 1, numRow) FOR(j, 1, numCol) REP(k, NUM_CHAR)
        score[i][j] += 1LL * Abs(board[i][j] - 'a' - k) * cntLetter[k][i][j];
    FOR(i, 1, numRow) FOR(j, 1, numCol) totalScore += score[i][j];

    calcPrefixSum(score, sumScore);

//    FOR(i, 1, numRow) FOR(j, 1, numCol) {
//        printf("Score of %d %d is %lld\n", i, j, score[i][j]);
//        REP(k, NUM_CHAR) if (cntLetter[k][i][j] > 0) printf("Cell %d %d has %d %c\n", i, j, cntLetter[k][i][j], k + 'a');
//    }

    cerr << totalScore << endl;
}

long long getSum(long long sum[][MAX_SIZE], int top, int bot, int left, int right) {
    if (top > bot || left > right) return 0;
    return sum[bot][right] - sum[top - 1][right] - sum[bot][left - 1] + sum[top - 1][left - 1];
}

void process(void) {
    long long res = INF;

    FOR(i, 1, numPic) {
        long long curScore = totalScore - getSum(sumScore, pictures[i].top, pictures[i].bot,
                                                   pictures[i].left, pictures[i].right);

        REP(j, NUM_CHAR) {
            //printf("area (%d, %d) x (%d, %d) has %lld %c\n", pictures[i].top, pictures[i].bot, pictures[i].left, pictures[i].right, getSum(sumLetter[j], pictures[i].top, pictures[i].bot, pictures[i].left, pictures[i].right), j + 'a');
            curScore += 1LL * Abs(pictures[i].ch - j) *
                getSum(sumLetter[j], pictures[i].top, pictures[i].bot, pictures[i].left, pictures[i].right);
        }

        minimize(res, curScore);
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