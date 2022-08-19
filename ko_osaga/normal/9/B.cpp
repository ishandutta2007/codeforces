#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int n, v1, v2, a[105], x, y;
int main(){
    scanf("%d %d %d",&n,&v1,&v2);
    double maxv = 1e9;
    int pos = 0;
    for (int i=1; i<=n; i++) {
        scanf("%d",&a[i]);
    }
    scanf("%d %d",&x,&y);
    for (int i=2; i<=n; i++){
        double calc = 1.0 * a[i] / v1 + hypot(a[i] - x,y) / v2;
        if(fabs(maxv - calc) < 1e-8){
            pos = i;
        }
        if(maxv > calc){
            maxv = calc;
            pos = i;
        }
    }
    printf("%d",pos);
}