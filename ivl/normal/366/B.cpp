#include <cstdio>
#include <algorithm>

using namespace std;

int n, k;
int a[100005];

int main(){
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i){
        scanf("%d", a + i);
    }
    int p1 = 0, p2 = 1000000000;
    for (int i = 0; i < k; ++i){
        int cnt = 0;
        for (int j = 0; j < n / k; ++j){
            cnt += a[i + j * k];
        }
        if (cnt < p2){p1 = i; p2 = cnt;}
    }
    printf("%d\n", p1 + 1);
    return 0;
}