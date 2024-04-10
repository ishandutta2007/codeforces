#include <cstdio>

using namespace std;

int n, k;
int p[105];
int pos[105];

double memo[35][35][205];
bool bio[35][35][205];
double dp(int a, int b, int k){
     if (k == 0) return (a > b);
     double &r = memo[a][b][k];
     if (bio[a][b][k]++) return r;
     r = 0;
     for (int i = 1; i <= n; ++i)
         for (int j = i; j <= n; ++j){
             int aa = a, bb = b;
             if (i <= aa && aa <= j)
                aa = j - (aa - i);
             if (i <= bb && bb <= j)
                bb = j - (bb - i);
             r += dp(aa, bb, k - 1);
         }
     r /= n;
     r /= n + 1;
     r *= 2;
     return r;
}

int main(){
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i){
        scanf("%d", p + i);
        pos[p[i]] = i;
    }
    double sol = 0;
    for (int i = 1; i <= n; ++i) for (int j = i + 1; j <= n; ++j)
        sol += dp(pos[i], pos[j], k);
    printf("%.15lf\n", sol);
    return 0;
}