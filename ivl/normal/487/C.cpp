#include <cstdio>

using namespace std;

int n;

long long pow(long long a, int x){
     if (x == 0) return 1;
     long long r = pow(a, x / 2);
     r = (r * r) % n;
     if (x & 1) r = (r * a) % n;
     return r;
}

int main(){
    scanf("%d", &n); if (n == 4){printf("YES\n1\n3\n2\n4\n"); return 0;}
    for (int i = 2; i * i <= n; ++i) if (n % i == 0){printf("NO\n"); return 0;}
    // n je prost
    // ai = i / (i-1) (mod p)
    printf("YES\n");
    for (int i = 1; i <= n; ++i){
        if (i == 1){printf("1\n"); continue;}
        if (i == n){printf("%d\n", n); continue;}
        printf("%d\n", (int)((pow(i - 1, n - 2) * (long long)i) % n));
    }
    return 0;
}