#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,a[5]={},b;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&b);
        a[b]++;
    }
    int ans = a[4]+a[3];
    a[1] = max(0,a[1]-a[3]);
    ans += (a[2]+1)/2;
    a[2] %= 2;
    if(a[2]){
        a[1] = max(0,a[1]-2);
    }
    ans += (a[1]+3)/4;
    printf("%d", ans);
}