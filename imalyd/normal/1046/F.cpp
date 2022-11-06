//Problem H
#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N],x,f;
long long ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    scanf("%d%d",&x,&f);
    for(int i=1;i<=n;i++)ans+=(a[i]-1+f)/(x+f);
    cout<<ans*f;
    return 0;
}