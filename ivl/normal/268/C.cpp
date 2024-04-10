#include <cstdio>

using namespace std;

int n, m;

int main(){
    scanf("%d%d", &n, &m);
    if (m < n){
       n = m;
    }
    printf("%d\n", n + 1);
    for (int i = 0; i <= n; ++i){
        printf("%d %d\n", i, n - i);
    }
    return 0;
}