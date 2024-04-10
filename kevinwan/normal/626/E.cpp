//Oshvleiki Svlaiyoska Ranasku sachi
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=2e5+10;
typedef long long ll;
ll a[mn],p[mn];
int l[mn];
bool les(ll a,ll b,ll c,ll d){
    return a*d<b*c;
}
int n;
ll eval(int r,int l){
    return p[r]-p[l-1]+p[n]-p[n-(r-l)];
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",a+i);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)p[i]=p[i-1]+a[i];
    for(int i=1,j=1;i<=n;i++){
        while(j+1<=i&&les(eval(i,j)-a[i]*(2*(i-j)+1),2*(i-j)+1,eval(i,j+1)-a[i]*(2*(i-(j+1))+1),2*(i-(j+1))+1))j++;
        l[i]=j;
    }
    int bes=1;
    for(int i=2;i<=n;i++)if(les(eval(bes,l[bes])-a[bes]*(2*(bes-l[bes])+1),2*(bes-l[bes])+1,eval(i,l[i])-a[i]*(2*(i-l[i])+1),2*(i-l[i])+1))bes=i;
    printf("%d\n",2*(bes-l[bes])+1);
    for(int i=l[bes];i<=bes;i++)printf("%lld ",a[i]);
    for(int i=n-(bes-l[bes])+1;i<=n;i++)printf("%lld ",a[i]);
}