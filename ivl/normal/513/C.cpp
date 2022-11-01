#include <cstdio>

using namespace std;

int n;
int l[10], r[10];

long double check(int bit, int val){
     long double p = 1;
     int c1 = 0, c2 = 0;
     for (int i = 0; i < n; ++i){
         int x = (bit >> (2 * i));
         x &= 3;
         if (x == 3) return 0;
         if (x == 2){++c2;
            int v = val + 1;
            if (r[i] < v) return 0;
            if (l[i] >= v) continue;
            p *= (double)(r[i] - v + 1) / (double)(r[i] - l[i] + 1);
         }
         if (x == 1){++c1;
            int v = val;
            if (v < l[i] || r[i] < v) return 0;
            p /= (double)(r[i] - l[i] + 1);
         }
         if (x == 0){
            int v = val - 1;
            if (l[i] > v) return 0;
            if (r[i] <= v) continue;
            p *= (double)(v - l[i] + 1) / (double)(r[i] - l[i] + 1);
         }
     }
     if (c2 >= 2) return 0;
     if (c2 == 0 && c1 <= 1) return 0;
     if (c1 == 0) return 0;
     //printf("%lf\n", (double)p);
     return p;
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d%d", l + i, r + i);
    long double SOL = 0;
    for (int x = 1; x <= 10000; ++x){
        long double p = 0;
        for (int i = 0; i < (1 << (2 * n)); ++i) p += check(i, x);
        SOL += p * (double)x;
    }
    printf("%.12lf\n", (double)SOL);
    return 0;
}