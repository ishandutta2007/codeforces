#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
    int n, m, a[1010];
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    sort(a, a + n);
    int sum = 0, ans = 0;
    for(int i = n - 1; i >= 0; i--){
        ans++;
        sum += a[i];
        if(sum >= m) break;
    }
    printf("%d", ans);
}