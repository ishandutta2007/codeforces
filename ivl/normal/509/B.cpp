#include <cstdio>
#include <algorithm>

using namespace std;

int n, k;
int a[1005];

int cnt[1005];

int main(){
    scanf("%d%d", &n, &k);
    int mini = 10000, maxi = -1;
    for (int i = 0; i < n; ++i){
        scanf("%d", a + i);
        ++cnt[a[i]];
        mini = min(mini, a[i]);
        maxi = max(maxi, a[i]);
    }
    if (maxi - mini > k){printf("NO\n"); return 0;}
    printf("YES\n");
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < mini; ++j) printf("%d ", 1);
        a[i] -= mini;
        for (int j = 0; j < a[i]; ++j) printf("%d ", j + 1);
        printf("\n");
    }
    
    return 0;
}