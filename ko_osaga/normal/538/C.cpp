#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int n, m, a[100005], b[100005];

int hi_max = 0;

int main(){
    scanf("%d %d",&n,&m);
    for (int i=1; i<=m; i++) {
        scanf("%d %d",&a[i],&b[i]); // a[i] = pos, b[i] = val
    }
    hi_max = max(b[1] + a[1] - 1, hi_max);
    hi_max = max(n - a[m] + b[m], hi_max);
    for (int i=1; i<m; i++) {
        int dx = abs(b[i+1] - b[i]);
        if(dx > a[i+1] - a[i]){
            puts("IMPOSSIBLE");
            return 0;
        }
        int eudori = (a[i+1] - a[i] - dx) / 2;
        hi_max = max(hi_max,max(b[i],b[i+1]) + eudori);
    }
    printf("%d",hi_max);
}