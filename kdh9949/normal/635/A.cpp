#include <cstdio>
#include <algorithm>
using namespace std;

int r, c, n, kk, x, y;
int chk[11][11];
int cnt, ans;

int main(){
    scanf("%d%d%d%d", &r, &c, &n, &kk);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &x, &y);
        chk[x][y]++;
    }
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            for(int k = i; k <= r; k++){
                for(int l = j; l <= c; l++){
                    cnt = 0;
                    for(int q = i; q <= k; q++){
                        for(int w = j; w <= l; w++){
                            cnt += chk[q][w];
                        }
                    }
                    ans += (cnt >= kk);
                }
            }
        }
    }
    printf("%d", ans);
}