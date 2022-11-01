#include <cstdio>
#include <algorithm>

using namespace std;

int n, k;
int p[10];

long double rek(int k){
     if (k == 0){
        int x = 0;
        for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (p[i] > p[j]) ++x;
        return x;
     }
     long double R = 0;
     for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j){
         int sz = j - i + 1;
         for (int kk = 0; kk < sz / 2; ++kk) swap(p[i + kk], p[j - kk]);
         R += rek(k - 1);
         for (int kk = 0; kk < sz / 2; ++kk) swap(p[i + kk], p[j - kk]);
     }
     R /= n;
     R /= n + 1;
     R *= 2;
     return R;
}

int main(){
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", p + i);
    printf("%.12lf\n", (double)rek(k));
    return 0;
}