#include <bits/stdc++.h>

#define INF 1000000010
#define FO(i,a,b) for (int (i) = (a); (i) < (b); ++(i))
#define sz(v) int(v.size())

using namespace std;
//PAIRS:
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;
typedef long long ll;

/*~~~~TEMPLATE END~~~~*/

#define MAX_N 100005

struct aEdge {
    int p;
    int d;
    aEdge();
    aEdge (int _p=0, int _d=0) {
        p = _p; d = _d;
    }
};

int N, M;
vector <aEdge> allE[MAX_N];


bool seen[MAX_N];
int sD[MAX_N];
int enD[MAX_N];
int frm[MAX_N];

int bEn[MAX_N];

bool tSeen[MAX_N];

int bPow (INF), bEdge (INF);
vector <int> ansD;
int cDist;

queue <int> bfs;

vector <int> cSet;
vector <int> oSet;

int main() {
    scanf ("%d %d", &N, &M);
    int en = N-1;
    FO (i,0,M) {
        int _a, _b, _c;
        scanf ("%d %d %d", &_a, &_b, &_c);
        allE[_a].push_back (aEdge (_b,_c));
        allE[_b].push_back (aEdge (_a,_c));
    }
    seen[0] = true;
    bfs.push (0);
    while (!bfs.empty()) {
        int cT = bfs.front();
        bfs.pop();
        for (int i = 0; i < sz(allE[cT]); i++) {
            int nP = allE[cT][i].p;
            if (seen[nP]) continue;
            seen[nP] = true;
            sD[nP] = sD[cT]+1;
            bfs.push (nP);
        }
    }
    memset (seen,0,sizeof(seen));
    seen[en] = true;
    enD[en] = 1;
    bfs.push (en);
    while (!bfs.empty()) {
        int cT = bfs.front();
        bEn[cT] = enD[cT];
        bfs.pop();
        if (sD[cT] < bPow) {
            bPow = sD[cT];
            bEdge = INF;
        }
        for (int i = 0; i < sz(allE[cT]); i++) {
            aEdge cE = allE[cT][i];
            if (cE.d == 0) {
                if (seen[cE.p]) continue;
                enD[cE.p] = enD[cT]+1;
                frm[cE.p] = cT;
                bfs.push (cE.p);
                seen[cE.p] = true;
            } else {
                if (sD[cT] != bPow) continue;
                if (cE.d < bEdge && sD[cE.p] == sD[cT]-1) {
                    bEdge = cE.d;
                }
            }
        }
    }
    if (seen[0]) {
        printf ("0\n");
        printf ("%d\n", enD[0]);
        for (int i = 0; i != en; i = frm[i]) {
            printf ("%d ", i);
        }
        printf ("%d\n", en);
        return 0;
    }
    ansD.push_back (bEdge);
    for (int i = 0; i < N; i++) {
        if (seen[i] && sD[i] == bPow) {
            for (int p = 0; p < sz(allE[i]); p++) {
                aEdge cE = allE[i][p];
                if (cE.d == bEdge && sD[cE.p] == bPow-1) {
                    if (!tSeen[cE.p]) {
                        tSeen[cE.p] = true;
                        cSet.push_back (cE.p);
                        frm[cE.p] = i;
                        bEn[cE.p] = bEn[i]+1;
                    }
                    if (bEn[i]+1 < bEn[cE.p]) {
                        bEn[cE.p] = bEn[i]+1;
                        frm[cE.p] = i;
                    }
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        if (tSeen[i]) seen[i] = true;
        else seen[i] = false;
    }
    for (;;) {
        if (seen[0]) break;
        bEdge = INF;
        cDist = sD[cSet[0]];
        for (int i = 0; i < cSet.size(); i++) {
            int cN = cSet[i];
            for (int p = 0; p < sz(allE[cN]); p++) {
                aEdge cE = allE[cN][p];
                if (cE.d < bEdge && sD[cE.p] == cDist-1) {
                    bEdge = cE.d;
                }
            }
        }
        for (int i = 0; i < cSet.size(); i++) {
            int cN = cSet[i];
            for (int p = 0; p < sz(allE[cN]); p++) {
                aEdge cE = allE[cN][p];
                if (cE.d == bEdge && sD[cE.p] == cDist-1) {
                    if (!seen[cE.p]) {
                        oSet.push_back (cE.p);
                        seen[cE.p] = true;
                        bEn[cE.p] = bEn[cN]+1;
                        frm[cE.p] = cN;
                    }
                    if (bEn[cN]+1 < bEn[cE.p]) {
                        bEn[cE.p] = bEn[cN]+1;
                        frm[cE.p] = cN;
                    }
                }
            }
        }
        cSet.clear();
        for (int i = 0; i < sz(oSet); i++) {
            cSet.push_back (oSet[i]);
        }
        oSet.clear();
        ansD.push_back (bEdge);
    }
    for (int i = 0; i < sz(ansD); i++) {
        printf ("%c", ansD[i]+'0');
    }
    /*
    FO (i,0,N) {
        printf ("%d: %d\n", i, bEn[i]);
    }
    */
    printf ("\n%d\n", bEn[0]);
    for (int i = 0; i != en; i = frm[i]) {
        printf ("%d ", i);
    }
    printf ("%d\n", en);
    return 0;
}