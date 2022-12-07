#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,a) FOR(i,0,(a)-1)
#define SIZE(v) (int)(v).size()
#define PB push_back
#define IN insert
#define ER erase
#define ALL(a) (a).begin(),(a).end()
#define ST first
#define ND second

typedef vector<int> VI;
typedef pair<int, int> PII;

int tab[1000][1000];

void myk(int n, PII p) {
    if (p.ST < 0 || p.ST >= n) return;
    if (p.ND < 0 || p.ND >= n) return;
    if (tab[p.ST][p.ND] > 0) return;
    tab[p.ST][p.ND] = 2;
    for (int i : {-1, 0, 1})
        for (int j : {-1, 0, 1})
            myk(n, PII({p.ST + i, p.ND + j}));

}

void jebaj() {

    int n;
    cin >> n;

    vector<PII> pola(3);
    REP(i, 3) cin >> pola[i].ST >> pola[i].ND;
    REP(i, 3) {
        pola[i].ST--;
        pola[i].ND--;
    }

    REP(i,n) REP(j, n) {
        tab[i][j] = 0;
        int a = abs(i - pola[0].ST);
        int b = abs(j - pola[0].ND);
        if (a == b) tab[i][j] = 1;
        if (i == pola[0].ST) tab[i][j] = 1;
        if (j == pola[0].ND) tab[i][j] = 1;
    }

    myk(n, pola[1]);
    if (tab[pola[2].ST][pola[2].ND] == 2) cout << "YES\n";
    else cout << "NO\n";

}
int main() {
    ios_base::sync_with_stdio();
    cin.tie();
    int t = 1;
    while (t--) {
        jebaj();
    }
    return 0;
}