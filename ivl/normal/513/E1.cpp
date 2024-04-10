#include <cstdio>
#include <algorithm>

using namespace std;

const int oo = 1000000000;

int n, k;
int a[30005];

int memo[30005][205][3][3][2];
int dp(int pos, int k, int pr, int cr, bool used){
    // + (pr + cr) * a[pos]
    if (k == 0 && !used) return 0;
    if (k == 0 && pos == n) return 0;
    if (pos == n) return -oo;
    int &r = memo[pos][k][pr + 1][cr + 1][used];
    if (r){
       if (r == -oo - 5) return 0;
       return r;
    }
    r = -oo;
    if (used){
       r = max(r, dp(pos, k, pr, cr, false));
       r = max(r, dp(pos + 1, k, pr, cr, used) + a[pos] * (pr + cr));
    }
    else {
         r = max(r, dp(pos + 1, k, pr, cr, used));
         if (k > 1) r = max(r, dp(pos + 1, k - 1, -cr, 1, true) + a[pos] * (-cr + 1));
         if (k > 1) r = max(r, dp(pos + 1, k - 1, -cr, -1, true) + a[pos] * (-cr - 1));
         if (k == 1) r = max(r, dp(pos + 1, k - 1, -cr, 0, true) + a[pos] * (-cr));
    }
    if (r == 0){r = -oo - 5; return 0;}
    return r;
}

int main(){
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    int r = dp(0, k, 0, 0, false);
    //r = max(r, dp(0, k, 0, -1, true));
    printf("%d\n", r);
    //printf(" --- %d\n", dp(4, 1, 0, 0, false));
    return 0;
}