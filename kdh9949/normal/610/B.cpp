#include <stdio.h>
#include <algorithm>

#define INF (0x7fffffff)
using namespace std;


int n, a[200010], m = INF;
long long ans, cur, ext;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    for(int i = 0; i < n; i++) m = min(m, a[i]);
    for(int i = 0; i < 2 * n; i++){
        if(a[i % n] == m){
            ext = max(ext, cur);
            cur = 0;
        }
        else cur++;
    }
    ans = (long long)m * n;
    printf("%I64d", ans + ext);
}