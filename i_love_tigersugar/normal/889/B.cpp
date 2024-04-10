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

const string NO = "NO";
void answerNO(void) {
    cout << NO << endl;
    exit(EXIT_SUCCESS);
}

bool havePath[226][226], need[226][226];
int countIn[226], countOut[226];

bool compare(const string &s, const string &t) {
    return s + t < t + s;
}

void process(void) {
    int needChar = 0;

    int n; cin >> n;
    REP(love, n) {
        string s; cin >> s;
        int mask = 0;
        FORE(it, s) {
            if (BIT(mask, *it - 'a')) answerNO();
            mask |= MASK(*it - 'a');
        }
        REP(i, (int)s.size() - 1) {
            int x = s[i] - 'a';
            int y = s[i + 1] - 'a';
            need[x][y] = true;
        }
        needChar |= mask;
    }

    REP(i, 26) havePath[i][i] = true;
    REP(i, 26) REP(j, 26) havePath[i][j] |= need[i][j];

    REP(k, 26) REP(i, 26) REP(j, 26) havePath[i][j] |= havePath[i][k] && havePath[k][j];
    REP(i, 26) REP(j, 26) if (i != j && havePath[i][j] && havePath[j][i]) answerNO();

    REP(i, 26) REP(j, 26) if (need[i][j]) {
        countIn[j]++; countOut[i]++;
    }

    REP(i, 26) if (countIn[i] > 1 || countOut[i] > 1) answerNO();

    vector<string> str;
    REP(i, 26) if (countOut[i] > 0 && countIn[i] == 0) {
        int tmp = i;
        string s;
        while (countOut[tmp] > 0) {
            s.push_back(tmp + 'a');
            REP(j, 26) if (need[tmp][j]) {
                tmp = j; break;
            }
        }
        s.push_back(tmp + 'a');
        str.push_back(s);
    }

    REP(i, 26) if (BIT(needChar, i) && countIn[i] == 0 && countOut[i] == 0) str.push_back(string(1, i + 'a'));
    sort(ALL(str), compare);

    FORE(it, str) cout << *it; cout << endl;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/