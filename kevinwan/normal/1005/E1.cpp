#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const ll mod=1e9+7;
const int mn=2e5+10;
int bit[mn*2];
int a[mn],b[mn];
void up(int a,int b){for(a+=mn;a<mn*2;a+=a&-a)bit[a]+=b;}
int qu(int a){int b=0;for(a+=mn;a;a-=a&-a)b+=bit[a];return b;}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    ll bad=0;
    for(int i=1;i<=n;i++)b[i]=(a[i]>m)?1:-1;
    for(int i=1;i<=n;i++)b[i]+=b[i-1];
    for(int i=n;i>=0;i--){
        bad+=n-i-qu(b[i]);
        up(b[i],1);
    }
    memset(bit,0,sizeof(bit));
    for(int i=1;i<=n;i++)b[i]=(a[i]<m)?1:-1;
    for(int i=1;i<=n;i++)b[i]+=b[i-1];
    for(int i=n;i>=0;i--){
        bad+=n-i-qu(b[i]-1);
        up(b[i],1);
    }
    printf("%lld",1LL*n*(n+1)/2-bad);
}