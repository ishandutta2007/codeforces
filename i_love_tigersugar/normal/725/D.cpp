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

#define MAX   300300

struct Team {
    long long have, need;
    Team() {
        have = need = 0;
    }

    void input(void) {
        cin >> have >> need;
    }

    bool operator < (const Team &t) const {
        return have > t.have;
    }
};

Team teams[MAX], myTeam;
int n;
void init(void) {
    cin >> n; n--;
    myTeam.input();
    REP(i, n) teams[i].input();
    sort(teams, teams + n);
}

bool ok(int k) {
    priority_queue<long long, vector<long long>, greater<long long> > q;
    int j = 0;
    Team curTeam = myTeam;

    while (true) {
        while (j < n && teams[j].have > curTeam.have) {
            q.push(teams[j].need + 1 - teams[j].have);
            j++;
        }
        if (q.size() < k) return true;
        while (q.size() >= k) {
            if (curTeam.have < q.top()) return false;
            curTeam.have -= q.top(); q.pop();
        }
    }
}

int process(void) {
    int L = 1;
    int R = n + 1;
    while (true) {
        if (L == R) return L;
        if (R - L == 1) return ok(L) ? L : R;
        int M = (L + R) >> 1;
        if (ok(M)) R = M; else L = M + 1;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    init();
    printf("%d\n", process());
    return 0;
}
/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/