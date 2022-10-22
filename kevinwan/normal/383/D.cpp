#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mn=1e3+10;
const ll mod=1e9+7;
#define mid ((l+r)>>1)
ll ans=0;
int num[mn];
ll p[mn][10001],suml[10001],sumr[10001];
void iter(ll a[10001],ll b[10001],int c){
    for(int i=0;i<c;i++)a[i]=b[i+c];
    for(int i=c;i<=10000-c;i++){
        a[i]=(b[i+c]+b[i-c]);
        if(a[i]>=mod)a[i]-=mod;
    }
    for(int i=10001-c;i<=10000;i++)a[i]=b[i-c];
}
void solve(int l,int r){
    if(l==r)return;
    memset(p[mid],0,sizeof(p[mid]));
    memset(p[mid+1],0,sizeof(p[mid]));
    p[mid][5000+num[mid]]=p[mid][5000-num[mid]]=1;
    p[mid+1][5000+num[mid+1]]=p[mid+1][5000-num[mid+1]]=1;
    int i,j;
    for(i=mid+2;i<=r;i++)iter(p[i],p[i-1],num[i]);
    for(i=mid-1;i>=l;i--)iter(p[i],p[i+1],num[i]);
    memset(suml,0,sizeof(suml));
    memset(sumr,0,sizeof(sumr));
    for(i=l;i<=mid;i++){
        for(j=0;j<=10000;j++)suml[j]+=p[i][j];
    }
    for(i=mid+1;i<=r;i++){
        for(j=0;j<=10000;j++)sumr[j]+=p[i][j];
    }
    for(j=0;j<=10000;j++)suml[j]%=mod,sumr[j]%=mod;
    for(i=0;i<=10000;i++)ans+=suml[i]*sumr[10000-i],ans%=mod;
    solve(l,mid);
    solve(mid+1,r);
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>num[i];
    solve(0,n-1);
    printf("%lld",ans);
}