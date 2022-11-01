#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a[5005];
//int mini[5005][5005];

long long memo[5005][5005];
bool bio[5005][5005];
long long dp(int cp, int h){
     if (cp == n + 1) return 0;
     long long &r = memo[cp][h];
     if (bio[cp][h]++) return r;
     r = 1 + dp(cp + 1, 0);
     if (a[h] > a[cp]) h = cp;
     if (a[h] == a[cp]) return r = dp(cp + 1, h);
     r = min(r, dp(cp + 1, h) + 1);
     r = min(r, dp(cp + 1, cp) + a[cp] - a[h]);
     return r;
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i){
        scanf("%d", a + i);
        //mini[i][i] = i;
    }
    /*
    for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j){
        if (a[mini[i][j - 1]] < a[j]) mini[i][j] = mini[i][j - 1];
        else mini[i][j] = j;
    }*/
    printf("%I64d\n", dp(0, 0));
    return 0;
}