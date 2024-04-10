#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, k, color[100010], lrow[5010], lcol[5010];
int t, a, b;

int main(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= k; i++){
        scanf("%d%d%d", &t, &a, &b);
        color[i] = b;
        if(t == 1) lrow[a] = i;
        else lcol[a] = i;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            printf("%d ", color[max(lrow[i], lcol[j])]);
        }
        puts("");
    }
}