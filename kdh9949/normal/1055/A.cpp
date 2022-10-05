#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, k, a[N], b[N];

int main(){
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    for(int i = 1; i <= n; i++) scanf("%d", b + i);
    for(int i = 1; i <= n; i++){
        if(!a[i]) continue;
        if(i == k && a[1] && a[i]){ puts("YES"); return 0; }
        if(i >= k && a[1] && b[i] && b[k]){ puts("YES"); return 0; }
    }
    puts("NO");
}