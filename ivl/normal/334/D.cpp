#include <cstdio>

using namespace std;

int n, m;
int in[100005][3];

int x[1005], y[1005];

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 2; i < n; ++i) x[i] = y[i] = 1;
    for (int i = 0; i < m; ++i){
        scanf("%d%d", in[i], in[i] + 1);
        x[in[i][0]] = 0;
        y[in[i][1]] = 0;
    }
    int rez = 0;
    for (int i = 1; i <= n; ++i) rez += x[i] + y[i];
    if (n % 2 == 1) if (x[(1 + n) / 2] == 1 && y[(1 + n) / 2] == 1) --rez;
    printf("%d\n", rez);
    return 0;
}