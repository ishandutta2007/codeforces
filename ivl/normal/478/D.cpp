#include <cstdio>

using namespace std;

int r, g;

int h;

long long ways[400005];

int main(){
    scanf("%d%d", &r, &g);
    int n = r + g;
    while (n >= h + 1){++h; n -= h;}
    
    ways[0] = 1;
    for (int i = 1; i <= h; ++i)
        for (int j = 400000 - i; j >= 0; --j){
            ways[j + i] += ways[j];
            if (ways[j + i] >= 1000000007) ways[j + i] -= 1000000007;
        }
    
    int t = (h * (h + 1)) / 2;
    long long sol = 0;
    
    for (int R = 0; R <= r; ++R){
        if (R > t) break;
        int G = t - R;
        if (G > g) continue;
        sol += ways[R];
        if (sol >= 1000000007) sol -= 1000000007;
    }
    
    printf("%I64d\n", sol);
    
    return 0;
}