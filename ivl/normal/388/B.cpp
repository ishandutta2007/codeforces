#include <cstdio>

using namespace std;

// 0 --- 1

int k;

int n = 1000;
char out[1005][1005];

int main(){
    scanf("%d", &k);
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j) out[i][j] = 'N';
        out[i][n] = '\0';
    }
    out[0][2] = out[2][0] = 'Y';
    out[0][3] = out[3][0] = 'Y';
    int p1 = 2, p2 = 4;
    for (int i = 1; i <= 30; ++i){
        int x = p2;
        for (int j = 0; j < i; ++j){
            out[p2][p1 + j] = out[p1 + j][p2] = 'Y';
            ++p2;
        }
        out[p2][p1 + i] = out[p1 + i][p2] = 'Y';
        out[p2][p1 + i - 1] = out[p1 + i - 1][p2] = 'Y';
        ++p2;
        out[p2][p1 + i] = out[p1 + i][p2] = 'Y';
        out[p2][p1 + i - 1] = out[p1 + i - 1][p2] = 'Y';
        ++p2;
        p1 = x;
    }
    for (int i = 0; k; ++i){
        if (k & 1) out[1][p1 + i] = out[p1 + i][1] = 'Y';
        k >>= 1;
    }
    printf("%d\n", n);
    for (int i = 0; i < n; ++i){
        printf("%s\n", out[i]);
    }
    return 0;
}