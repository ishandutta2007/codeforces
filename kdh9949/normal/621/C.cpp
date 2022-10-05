#include <cstdio>
#include <algorithm>
using namespace std;

int n, p, l[100010], r[100010];
double ans;

int main(){
    scanf("%d%d", &n, &p);
    for(int i = 0; i < n; i++){
        scanf("%d%d", l + i, r + i);
    }
    long long a1, a2, b1, b2;
    for(int i = 0; i < n; i++){
        a1 = r[i] - l[i] + 1;
        a2 = r[(i + 1) % n] - l[(i + 1) % n] + 1;
        b1 = (r[i] / p) - ((l[i]  - 1) / p) ;
        b2 = (r[(i + 1) % n] / p) - ((l[(i + 1) % n]  - 1) / p);
        ans += 2000.0 * (double)(a1 * a2 - (a1 - b1) * (a2 - b2)) / (double)(a1 * a2);
    }
    printf("%lf", ans);
}