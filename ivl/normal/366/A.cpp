#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a, b, c, d;

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= 4; ++i){
        scanf("%d%d%d%d", &a, &b, &c, &d);
        int e = min(a, b), f = min(c, d);
        if (e + f <= n){
           printf("%d %d %d\n", i, e, n - e);
           return 0;
        }
    }
    printf("-1\n");
    return 0;
}