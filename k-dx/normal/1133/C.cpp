#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10e5 * 2 + 5;
const int MAXAi = 10e9 + 200;

int n;
int t[MAXN];
int jump[MAXN];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &t[i]);
    
    sort(t, t+n);
    t[n] = MAXAi;

    int from = 0;
    for(int i = 1; i <= n; i++){
        if(t[from] != t[i]){
            jump[from] = i;
            from = i;
        }
    }

    /*
    for(int i = 0; i < n; i++)
        printf("%d ", jump[i]);
    */

    int best = 0;
    for(int i = 0; i < n; i++){
        if(jump[i] == 0) continue;
        int now = 0;

        int j = i;
        while(t[j] - t[i] <= 5 and j < n){
            now += jump[j] - j;
            j = jump[j];
        }

        best = max(best, now);
    }

    printf("%d\n", best);
    return 0;
}