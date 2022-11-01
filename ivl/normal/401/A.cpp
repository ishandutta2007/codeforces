#include <cstdio>

using namespace std;

int n, x;

int main(){
    scanf("%d%d", &n, &x);
    int s = 0;
    for (int i = 0; i < n; ++i){
        int a;
        scanf("%d", &a);
        s += a;
    }
    if (s < 0) s = -s;
    printf("%d\n", (s + x - 1) / x);
    return 0;
}