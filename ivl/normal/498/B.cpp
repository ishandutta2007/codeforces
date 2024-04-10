#include <cstdio>

using namespace std;

double pow(double x, int y){
       if (y == 0) return 1;
       double r = pow(x * x, y / 2);
       if (y & 1) r *= x;
       return r;
}

int n, T;
int p[5005], t[5005];
double v[5005];

int curr; double cf;
double r1[5005][2], r2[5005][2];
double dp(int pt, int tm, bool tr){ // true -> zanemari t[pt]
       if (pt >= n || tm >= T + 1) return 0;;
       if (tr){
          return (1.0 - v[pt]) * r1[tm + 1][true] + v[pt] * (1 + r2[tm + 1][false]);
       }
       else {
            if (tm + t[pt] - 1 >= T + 1) return r1[tm][true];
            return r1[tm][true] + cf * (1 - r1[tm + t[pt] - 1][true] + r2[tm + t[pt]][false]);
       }
}

int main(){
    scanf("%d%d", &n, &T);
    for (int i = 0; i < n; ++i){
        scanf("%d%d", p + i, t + i);
        v[i] = (double)p[i] / 100.0;
    }
    for (int i = 0; i < 5003; ++i) r2[i][0] = r2[i][1] = 0;
    for (curr = n - 1; curr >= 0; --curr){ cf = pow(1.0 - v[curr], t[curr] - 1);
        for (int i = 5003; i >= 0; --i) r1[i][true] = dp(curr, i, true);
        for (int i = 5003; i >= 0; --i) r1[i][false] = dp(curr, i, false);
        for (int i = 0; i < 5003; ++i){
            r2[i][0] = r1[i][0];
            r2[i][1] = r1[i][1];
        }
    }
    printf("%.9lf\n", r2[1][0]);
    return 0;
}