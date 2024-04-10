#include<bits/stdc++.h>

using namespace std;

const int MAXN =1e5 + 10;

int a[MAXN], b[MAXN], c[MAXN], d[MAXN];

int main(){
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    a[0] = a[1] - 1;
    int m = 0;
    for(int i = 1; i <= n; i++)
        if (a[i] != a[i-1]){
            b[++m] = a[i];
            d[m] = 1;
        }
        else
            d[m]++;
    int ans = d[1]+d[2];
    for(int i = 1; i <= n; i++)
        c[i] = c[i-1] + d[i];
    int i = 1;
    for(int k = 3; k <= n; k++){
        if (b[k] == b[i] || b[k] == b[i+1])
            ans = max(c[k] - c[i-1], ans);
        else{
            i = k-1;
            ans = max(c[k] - c[k-2], ans);
        }
    }
    cout<<ans<<endl;
    return 0;
}