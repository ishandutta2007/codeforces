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

#define MAX_DIM 605
#define THRESHOLD 20

int Q, H, W;
int v[MAX_DIM][MAX_DIM];

int getDiff() {
    int ans = 0;
    FO (i,0,W) {
        ans += abs(v[H/2][i] - v[H/2-1][i]);
    }
    return ans;
}



int main() {
    scanf ("%d", &Q);
    FO (i,0,Q) {
        scanf ("%d %d", &H, &W);
        FO (i,0,H) {
            FO (p,0,W) {
                scanf ("%d", &v[i][p]);
            }
        }
        int diff = getDiff();
        if (diff > THRESHOLD*W) {
            printf ("YES\n");
            //printf ("YES %lf\n", (1.0*diff)/W);
        } else {
            printf ("NO\n");
            //printf ("NO %lf\n", (1.0*diff)/W);
        }
    }
    return 0;
}