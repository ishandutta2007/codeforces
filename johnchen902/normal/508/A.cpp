#include <cstdio>
using namespace std;
bool x[1002][1002];
int main(){
    int n, m, kk;
    scanf("%d %d %d", &n, &m, &kk);
    for(int i = 1; i <= kk; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        x[a][b] = true;
        for(int j = -1; j <= 0; j++)
            for(int k = -1; k <= 0; k++)
                if(x[a + j][b + k] && x[a + j + 1][b + k] &&
                        x[a + j][b + k + 1] && x[a + j + 1][b + k + 1]) {
                    printf("%d\n", i);
                    return 0;
                }
    }
    puts("0");
}