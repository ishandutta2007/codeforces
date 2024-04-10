#include <cstdio>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
    if (b) return gcd(b, a % b);
    return a;
}

int n;
int a[105];

int g;

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){scanf("%d", a + i); g = gcd(a[i], g);}
    for (int i = 0; i < n; ++i) a[i] /= g;
    int r = 0;
    for (int i = 0; i < n; ++i) r = max(r, a[i]);
    if ((r - n) & 1) printf("Alice\n");
    else printf("Bob\n");
    return 0;
}