#include <cstdio>

using namespace std;

int n;

int main(){
    scanf("%d", &n);
    int poin = 1;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j * 2 <= n; ++j){
            printf("%d %d ", poin, n * n - poin + 1);
            ++poin;
        }
        printf("\n");
    }
    return 0;
}