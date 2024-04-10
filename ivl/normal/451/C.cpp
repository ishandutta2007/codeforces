#include <cstdio>

using namespace std;

long long abs(long long a){if (a < 0) return -a; return a;}

void solve(){
     long long n, k, d1, d2;
     scanf("%I64d%I64d%I64d%I64d", &n, &k, &d1, &d2);
     if (n % 3 != 0){printf("no\n"); return;}
     long long x, y, z;
     
     x = (k + 2 * d1 + d2) / 3;
     y = x - d1;
     z = y - d2;
     if (abs(x - y) == d1 && abs(y - z) == d2 && x + y + z == k && x >= 0 && y >= 0 && z >= 0 && x <= n / 3 && y <= n / 3 && z <= n / 3){printf("yes\n"); return;}
     
     y = (k - d1 - d2) / 3;
     x = y + d1;
     z = y + d2;
     if (abs(x - y) == d1 && abs(y - z) == d2 && x + y + z == k && x >= 0 && y >= 0 && z >= 0 && x <= n / 3 && y <= n / 3 && z <= n / 3){printf("yes\n"); return;}
     
     y = (k + d1 + d2) / 3;
     x = y - d1;
     z = y - d2;
     if (abs(x - y) == d1 && abs(y - z) == d2 && x + y + z == k && x >= 0 && y >= 0 && z >= 0 && x <= n / 3 && y <= n / 3 && z <= n / 3){printf("yes\n"); return;}
     
     z = (k + d1 + 2 * d2) / 3;
     y = z - d2;
     x = y - d1;
     if (abs(x - y) == d1 && abs(y - z) == d2 && x + y + z == k && x >= 0 && y >= 0 && z >= 0 && x <= n / 3 && y <= n / 3 && z <= n / 3){printf("yes\n"); return;}
     
     printf("no\n");
}

int main(){
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) solve();
    return 0;
}