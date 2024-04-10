#include <cstdio>
#include <algorithm>
using namespace std;

int n, a[55][55], ans[55];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 1; i <= n - 1; i++){
        for(int j = 1; j <= n; j++){
            int cnt = 0;
            for(int k = 1; k <= n; k++) cnt += (a[j][k] == i);
            for(int k = 1; k <= n; k++) cnt += (a[k][j] == i);
            if(cnt == 2 * (n - i)){
                for(int k = 1; k <= n; k++) a[j][k] = 0;
                for(int k = 1; k <= n; k++) a[k][j] = 0;
                ans[j] = i;
                break;
            }
        }
    }
    for(int i = 1; i <= n; i++) printf("%d ", ans[i] ? ans[i] : n);
}