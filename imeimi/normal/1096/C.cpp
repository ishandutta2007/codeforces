#include <cstdio>

int gcd(int x, int y){
if (y==0) return x;
return gcd(y, x % y);
}

int main() {
int T;
scanf("%d", &T);
while (T--){
int a;
scanf("%d", &a);
int bt = 180, tp = a;
int g = gcd(bt, tp);
bt /= g; tp /= g;
if (tp + 1 < bt) printf("%d\n", bt);
else printf("%d\n", bt * 2);
}
}