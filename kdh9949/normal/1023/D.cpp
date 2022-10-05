#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, q, a[N], b[N], l[N], r[N];

int main(){
    scanf("%d%d", &n, &q);
    fill(l + 1, l + q + 1, n + 1);
    for(int i = 1; i <= n; i++){
        scanf("%d", a + i);
        b[i] = !a[i];
        l[a[i]] = min(l[a[i]], i);
        r[a[i]] = max(r[a[i]], i);
    }
    for(int i = 1; i <= q; i++){
        for(; l[i] < r[i]; l[i]++){
            if(!a[l[i]]) a[l[i]] = i;
            else if(a[l[i]] < i){ puts("NO"); return 0; }
            else if(a[l[i]] > i) break;
        }
        for(; l[i] < r[i]; r[i]--){
            if(!a[r[i]]) a[r[i]] = i;
            else if(a[r[i]] < i){ puts("NO"); return 0; }
            else if(a[r[i]] > i) break;
        }
    }
    if(*max_element(a + 1, a + n + 1) < q){
        for(int i = 1; i <= n; i++) if(b[i]){ a[i] = q; break; }
    }
    for(int i = 1; i <= n; i++) if(!a[i]) a[i] = a[i - 1];
    for(int i = n; i >= 1; i--) if(!a[i]) a[i] = a[i + 1];
    for(int i = 1; i <= n; i++) if(!a[i]) a[i] = q;
    if(*max_element(a + 1, a + n + 1) < q){ puts("NO"); return 0; }
    puts("YES");
    for(int i = 1; i <= n; i++) printf("%d ", a[i]);
    puts("");
    return 0;
}