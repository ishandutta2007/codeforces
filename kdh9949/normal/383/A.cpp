#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 200005;

int n, a[N];
ll r;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    for(int i = n, j = 0; i >= 1; i--){
        if(a[i]) r += j;
        else j++;
    }
    printf("%lld\n", r);
}