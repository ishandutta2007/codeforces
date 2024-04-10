#include <cstdio>

using namespace std;

int n, m;

int ab[1005][1005], xy[1005][1005];
int a[100005], b[100005], x[100005], y[100005];

int min(int a, int b){
    if (a < b){
       return a;
    }
    return b;
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i){
        scanf("%d%d", x + i, y + i);
        xy[x[i]][y[i]]++;
    }
    for (int i = 0; i < m; ++i){
        scanf("%d%d", a + i, b + i);
        ab[a[i]][b[i]]++;
    }
    int r1 = 0, r2 = 0;
    for (int i = 0; i < 1003; ++i){
        for (int j = 0; j < 1003; ++j){
            int pom = min(xy[i][j], ab[i][j]);
            r2 += pom;
            r1 += pom;
            xy[i][j] -= pom;
            ab[i][j] -= pom;
        }
    }
    for (int i = 0; i < 1003; ++i){
        int pom1 = 0, pom2 = 0;
        for (int j = 0; j < 1003; ++j){
            pom1 += ab[j][i];
            pom2 += xy[j][i];
        }
        r1 += min(pom1, pom2);
    }
    printf("%d %d\n", r1, r2);
    //while (true);
    return 0;
}