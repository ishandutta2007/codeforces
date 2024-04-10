#include <cstdio>

using namespace std;

int n, k;
int a[55];

int main(){
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i){
        scanf("%d", a + i);
    }
    int pos = k;
    --pos;
    if (a[pos] <= 0){
       while (pos >= 0){
             if (a[pos] > 0){
                break;
             }
             --pos;
       }
       printf("%d\n", pos + 1);
       //while (true);
       return 0;
    }
    int pom = a[pos];
    while (a[pos] == pom && pos < n){
          ++pos;
    }
    printf("%d\n", pos);
    //while (true);
    return 0;
}