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


int T, N, R;

int main() {
    scanf ("%d", &T);
    FO (_z,0,T) {
        scanf ("%d %d", &N, &R);
        R %= N;
        int cum = 0;
        FO (i,0,N-1) {
            int _a;
            scanf ("%d", &_a);
            cum += _a;
            cum %= N;
        }
        int ans = (R-cum+N) % N;
        if (ans == 0) ans = N;
        printf ("%d\n", ans);
    }
    return 0;
}