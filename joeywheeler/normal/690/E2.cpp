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

#define FIXED_WINDOW_LENGTH 30
#define MAX_K 17
#define MAX_W 605
#define MAX_H 605

int Q, H, W, K, v[MAX_H][MAX_W];
int d[MAX_K][MAX_K];
int windowLength;

void makeAllDists() {
    FO (i,0,K) {
        FO (p,0,K) {
            if (i == p) continue;
            int fR = H/K * (i+1)-1;
            int sR = H/K * p;
            // Make the averages:
            int avg1[MAX_W], avg2[MAX_W];
            int dist = 0;
            windowLength = min(W/2,FIXED_WINDOW_LENGTH);
            FO (t,0,W-windowLength+1) {
                int mn = 300;
                int mx = -1;
                int sum = 0;
                FO (q,0,windowLength) {
                    sum += v[fR][t+q];
                    mn = min (mn, v[fR][t+q]);
                    mx = max (mx, v[fR][t+q]);
                }
                avg1[t] = sum-mn-mx;
                mn = 300; mx = -1; sum = 0;
                FO (q,0,windowLength) {
                    sum += v[sR][t+q];
                    mn = min (mn, v[sR][t+q]);
                    mx = max (mx, v[sR][t+q]);
                }
                avg2[t] = sum-mn-mx;
                dist += abs(avg1[t]-avg2[t]);
            }
            d[i][p] = dist;
            //printf ("dist: %d %d: %d\n", i, p, d[i][p]);
        }
    }
}

ll bst[70000][MAX_K];
int prv[70000][MAX_K];

void doDp() {
    FO (i,0,(1<<K)) {
        FO (p,0,K) {
            bst[i][p] = INF;
        }
    }
    FO (i,0,K) {
        bst[(1<<i)][i] = 0;
    }
    FO (i,1,(1<<K)) {
        FO (p,0,K) {
            if (i & (1<<p)) {
                FO (t,0,K) {
                    if (!(i & (1<<t))) {
                        int newMsk = i | (1<<t);
                        int newBst = bst[i][p] + d[p][t];
                        if (newBst < bst[newMsk][t]) {
                            bst[newMsk][t] = newBst;
                            prv[newMsk][t] = p;
                        }
                    }
                }
                //printf ("bst: %d\n", bst[i][p]);
            }
        }
    }
    return;
}


int main() {
    scanf ("%d", &Q);
    FO (i,0,Q) {
        scanf ("%d %d %d", &H, &W, &K);
        FO (i,0,H) {
            FO (p,0,W) {
                scanf ("%d", &v[i][p]);
            }
        }
        makeAllDists();
        doDp();
        vector <int> ans;
        int cMsk = (1<<K)-1;
        int cEnd = 0;
        int cBest = bst[cMsk][0];
        FO (i,1,K) {
            if (bst[cMsk][i] < cBest) {
                cBest = bst[cMsk][i];
                cEnd = i;
            }
        }
        while (cMsk != 0) {
            ans.push_back (cEnd);
            int nMsk = cMsk ^ (1 << cEnd);
            cEnd = prv[cMsk][cEnd];
            cMsk = nMsk;
        }
        reverse(ans.begin(), ans.end());
        int othAns[MAX_K];
        FO (i,0,ans.size()) {
            othAns[ans[i]] = i;
        }
        FO (i,0,K) {
            printf ("%d ", othAns[i]+1);
        }
        printf ("\n");
    }
    return 0;
}