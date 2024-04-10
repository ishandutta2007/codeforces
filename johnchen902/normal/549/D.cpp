#include <cstdio>
using namespace std;

int v[101][101];

int main() {
    int n, m;
    scanf("%d %d\n", &n, &m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            v[i][j] = getchar() == 'W' ? +1 : -1;
        getchar();
    }
    int cnt = 0;
    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) {
            if(v[i][j]) {
                cnt++;
                for(int k = 0; k <= i; k++)
                    for(int l = 0; l <= j; l++)
                        v[k][l] -= v[i][j];
            }
        }
    }
    printf("%d\n", cnt);
}