#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 100005, K = 4000005;

int n;
ll a[N], sq[K];

int main(){
    for(int i = 1; i < K; i++) sq[i] = 1LL*i*i;
    scanf("%d", &n);
    for(int i = 2, j = 1, jj = 1; i <= n; i += 2){
        scanf("%lld", a+i);
        int k = jj;
        for(j = jj; j < K; j++){
            for(; jj < K; jj++) if(sq[jj] >= sq[j]+a[i]) break;
            if(jj == K){ puts("No"); return 0; }
            if(sq[jj] == sq[j]+a[i]) break;
        }
        if(j == K){ puts("No"); return 0; }
        a[i-1] = sq[j]-sq[k];
    }
    puts("Yes");
    a[1]++;
    for(int i = 1; i <= n; i++) printf("%lld ", a[i]);
}