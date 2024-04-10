#include <cstdio>

using namespace std;

int n;
int l[605], r[605];

int dp(int lo, int hi){
    static int memo[605][605];
    static bool bio[605][605];
    if (lo > hi) return 0;
    int &r = memo[lo][hi];
    if (bio[lo][hi]++) return r;
    
    r = -1;
    for (int i = l[lo]; i <= ::r[lo]; ++i){
        if (i % 2 == 0) continue;
        if (2 * (hi - lo + 1) - 1 < i) break;
        int x = dp(lo + 1, lo + (i - 1) / 2);
        int y = dp(lo + (i + 1) / 2, hi);
        if (x == -1 || y == -1) continue;
        r = i; break;
    }
    
    return r;
}

void rek(int lo, int hi){
     int x = dp(lo, hi);
     if (x == 0) return;
     printf("(");
     rek(lo + 1, lo + (x - 1) / 2);
     printf(")");
     rek(lo + (x + 1) / 2, hi);
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d%d", l + i, r + i);
    
    if (dp(1, n) == -1){printf("IMPOSSIBLE\n"); return 0;}
    
    rek(1, n);
    printf("\n");
    
    return 0;
}