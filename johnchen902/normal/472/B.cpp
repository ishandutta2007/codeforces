#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
int f[2000];
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%d", f + i);
    sort(f, f + n, greater<int>());
    int sum = 0;
    for(int i = 0; i < n; i += k)
        sum += f[i] * 2 - 2;
    printf("%d\n", sum);
}