#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int a[N], f[N];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        f[i] = 0;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        f[a[i]] = f[a[i]-1] + 1;
        ans = max(ans, f[a[i]]);
    }
    cout<<n - ans<<endl;
    return 0;
}