#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=2e5+10;
ll a[mn];
int b[mn];
bool comp(const int&f,const int&s){
    return a[f]>a[s];
}
int main(){
    int n,m,k,i;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<n;i++)scanf("%lld",a+i),b[i]=i;
    sort(b,b+n,comp);
    ll ans=0;
    for(i=0;i<m*k;i++)ans+=a[b[i]];
    printf("%lld\n",ans);
    sort(b,b+m*k);
    for(i=m-1;i<m*(k-1);i+=m)printf("%d ",b[i]+1);
}