#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

ll ax, ay, bx, by, x, y, d1[2020], d2[2020];
ll cans, cmax, ans = (1ll << 62);
bool chk[2020];
int n;

int main(){
    scanf("%d%I64d%I64d%I64d%I64d", &n, &ax, &ay, &bx, &by);
    for(int i = 0; i < n; i++){
        scanf("%I64d%I64d", &x, &y);
        d1[i] = (x - ax) * (x - ax) + (y - ay) * (y - ay);
        d2[i] = (x - bx) * (x - bx) + (y - by) * (y - by);
    }
    for(int i = 0; i <= n; i++){
        cans = d1[i];
        for(int j = 0; j < n; j++){
            chk[j] = (d1[j] <= cans);
        }
        cmax = 0;
        for(int j = 0; j < n; j++) if(!chk[j]) cmax = max(cmax, d2[j]);
        ans = min(ans, cans + cmax);
    }
    printf("%I64d", ans);
}