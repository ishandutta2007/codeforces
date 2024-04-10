#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 100005;

int n;
ll a[N], b[N], ad[N], bd[N];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%lld", a + i);
    for(int i = 1; i <= n; i++) scanf("%lld", b + i);
    if(a[1] != b[1] || a[n] != b[n]){
        puts("No");
        return 0;
    }
    for(int i = 1; i < n; i++) ad[i] = a[i + 1] - a[i];
    for(int i = 1; i < n; i++) bd[i] = b[i + 1] - b[i];
    sort(ad + 1, ad + n);
    sort(bd + 1, bd + n);
    for(int i = 1; i < n; i++) if(ad[i] != bd[i]){ puts("No"); return 0; }
    puts("Yes");
}