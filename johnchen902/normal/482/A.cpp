#include <cstdio>
using namespace std;
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int x = 1;
    printf("%d ", x);
    for(int i = 0; i < k - 1; i++) {
        if(i % 2 == 0)
            x += n - 1 - i;
        else
            x -= n - 1 - i;
        printf("%d ", x);
    }
    if(k % 2 == 1) {
        for(int i = k; i < n; i++)
            printf("%d ", ++x);
    } else {
        for(int i = k; i < n; i++)
            printf("%d ", --x);
    }
}