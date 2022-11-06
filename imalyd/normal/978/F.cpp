#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=200005;
ll n,m,r[N],k[N],a[N],x,y;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>r[i],k[i]=r[i];
    sort(k+1,k+n+1);//for(int i=1;i<=n;i++)cout<<k[i]<<' ';
    for(int i=1;i<=n;i++)a[i]=lower_bound(k+1,k+n+1,r[i])-k-1;//for(int i=1;i<=n;i++)cout<<a[i]<<' ';
    while(m--){
        cin>>x>>y;
        if(r[y]<r[x])a[x]--;
        if(r[x]<r[y])a[y]--;
    }
    for(int i=1;i<=n;i++)cout<<a[i]<<' ';
    return 0;
}