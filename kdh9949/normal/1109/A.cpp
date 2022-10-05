#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, a[2][1 << 20];
ll r;

int main(){
    scanf("%d", &n);
    a[1][0] = 1;
    for(int i = 0, j = 0, k = 0, x; i < n; i++, j ^= 1){
        scanf("%d", &x);
        k ^= x;
        r += a[j][k]++;
    }
    printf("%lld\n", r);
}