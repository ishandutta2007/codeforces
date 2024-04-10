#include <cstdio>
#include <algorithm>

using namespace std;

int n, k;
int a[105], b[105];

int memo[300005];
int &ac(int x){
    return memo[x + 150000];
}

int main(){
    for (int i = -150000; i <= 150000; ++i) ac(i) = -1000000000;
    ac(0) = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    for (int i = 0; i < n; ++i){scanf("%d", b + i); b[i] *= k; b[i] -= a[i];}
    for (int i = 0; i < n; ++i){
        if (b[i] >= 0){
           for (int j = 150000; j >= -150000; --j){
               if (ac(j) == -1000000000) continue;
               ac(j + b[i]) = max(ac(j + b[i]), a[i] + ac(j));
           }
        }
        else {
             for (int j = -150000; j <= 150000; ++j){
                 if (ac(j) == -1000000000) continue;
                 ac(j + b[i]) = max(ac(j + b[i]), a[i] + ac(j));
             }
        }
    }
    if (ac(0) == 0) ac(0) = -1;
    printf("%d\n", ac(0));
    return 0;
}