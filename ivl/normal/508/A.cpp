#include <cstdio>
#include <cstdlib>

using namespace std;

void gotov(int x){printf("%d\n", x); exit(0);}

int n, m, k;
bool mat[1005][1005];

int main(){
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        mat[a][b] = true;
        if (mat[a - 1][b - 1] && mat[a - 1][b] && mat[a][b - 1]) gotov(i + 1);
        if (mat[a + 1][b + 1] && mat[a + 1][b] && mat[a][b + 1]) gotov(i + 1);
        if (mat[a - 1][b + 1] && mat[a - 1][b] && mat[a][b + 1]) gotov(i + 1);
        if (mat[a + 1][b - 1] && mat[a + 1][b] && mat[a][b - 1]) gotov(i + 1);
    }
    gotov(0);
    return 0;
}