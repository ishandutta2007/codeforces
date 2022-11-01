#include <cstdio>

using namespace std;

int n;
int a[305];

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    for (int i = 0; i < 300; ++i){
        for (int i = 0; i < n - 1; ++i){
            if (a[i]){
               --a[i];
               printf("P");
            }
            printf("R");
        }
        for (int i = n - 1; i; --i){
            if (a[i]){
               printf("P");
               --a[i];
            }
            printf("L");
        }
    }
    printf("\n");
    return 0;
}