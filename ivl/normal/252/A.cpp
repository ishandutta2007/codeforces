#include <cstdio>

using namespace std;

int niz[105];
int n;

int dp[105];

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        scanf("%d", niz + i);
    }
    int rez = 0;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j <= i; ++j){
            dp[j] ^= niz[i];
            if (dp[j] > rez){
               rez = dp[j];
            }
        }
    }
    printf("%d\n", rez);
    return 0;
}