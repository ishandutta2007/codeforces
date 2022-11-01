#include <cstdio>
#include <algorithm>
using namespace std;
constexpr int m = 1000000007;
int p[100000];
constexpr int E = 0, O = 1, G = 2;
long long x[100000][2][3];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        scanf("%d", p + i);
        p[i]--;
    }
    for(int i = 0; i < n; i++)
        x[i][E][E] = x[i][E][O] = x[i][E][G] = 1;
    for(int i = n - 1; ; i--) {
        long long xiOG = (x[i][E][G] * 2 + m - x[i][E][E] + m - x[i][O][E]) % m;
        long long xiEG = (x[i][O][G] * 2 + m - x[i][O][O]) % m;
        x[i][O][G] = xiOG;
        x[i][E][G] = xiEG;
        if(i == 0)
            break;
        long long tmp[2][3];
        tmp[E][E] = x[p[i]][E][E] + x[p[i]][O][E] * x[i][E][G];
        tmp[E][O] = x[p[i]][E][O] + x[p[i]][O][O] * x[i][O][G];
        tmp[E][G] = x[p[i]][E][G] + x[p[i]][E][G] * x[i][E][G] + x[p[i]][O][G] * x[i][O][G];
        tmp[O][E] = x[p[i]][O][E] + x[p[i]][E][E] * x[i][E][G];
        tmp[O][O] = x[p[i]][O][O] + x[p[i]][E][O] * x[i][O][G];
        tmp[O][G] = x[p[i]][O][G] + x[p[i]][O][G] * x[i][E][G] + x[p[i]][E][G] * x[i][O][G];
        for(int j = 0; j < 6; j++)
            x[p[i]][j / 3][j % 3] = tmp[j / 3][j % 3] % m;
    }
    printf("%d\n", (int)((x[0][E][G] + x[0][O][G]) % m));
}