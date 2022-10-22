#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(423978);
typedef long long ll;
typedef pair<ll,ll>pll;
const ll mod=1e9+7;
const int mn=3e5+10;
int seg[mn*4][3][3];
int inf=0x3f3f3f3f3f3f3f3f;
#define mid ((l+r)>>1)
void upd(int x,int l,int r,int a,ll b){
    if(r<l)return;
    if(l==r){
        memset(seg[x],0xc0,sizeof(seg[x]));
        if(b>=1)seg[x][0][0]=seg[x][0][1]=seg[x][2][0]=seg[x][2][1]=seg[x][0][2]=seg[x][2][2]=1;
        else if(b<=-1)seg[x][1][1]=seg[x][2][1]=seg[x][1][2]=seg[x][2][2]=1;
        else seg[x][2][2]=0;
    }
    else{
        if(a<=mid)upd(x*2,l,mid,a,b);
        else upd(x*2+1,mid+1,r,a,b);
        seg[x][0][0]=seg[x*2][0][0]+seg[x*2+1][0][0];
        seg[x][0][1]=max(seg[x*2][0][0]+seg[x*2+1][0][1],seg[x*2][0][1]+seg[x*2+1][1][1]);
        seg[x][0][2]=max(max(seg[x*2][0][0]+seg[x*2+1][0][2],seg[x*2][0][1]+seg[x*2+1][1][2]),seg[x*2][0][2]);
        seg[x][1][1]=seg[x*2][1][1]+seg[x*2+1][1][1];
        seg[x][1][2]=max(seg[x*2][1][1]+seg[x*2+1][1][2],seg[x*2][1][2]);
        seg[x][2][0]=max(seg[x*2][2][0]+seg[x*2+1][0][0],seg[x*2+1][2][0]);
        seg[x][2][1]=max(max(seg[x*2][2][0]+seg[x*2+1][0][1],seg[x*2][2][1]+seg[x*2+1][1][1]),seg[x*2+1][2][1]);
        seg[x][2][2]=max(max(seg[x*2][2][2],seg[x*2+1][2][2]),max(seg[x*2][2][0]+seg[x*2+1][0][2],seg[x*2][2][1]+seg[x*2+1][1][2]));
        for(int i=0;i<3;i++)for(int j=0;j<3;j++)seg[x][i][j]=max(seg[x][i][j],-inf);
    }
}
ll a[mn],d[mn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%lld", a + i);
    }
    for(int i=1;i<=n-1;i++)d[i]=a[i+1]-a[i],upd(1,1,n-1,i,d[i]);
    int q;
    scanf("%d",&q);
    while(q--){
        int l,r,dd;
        scanf("%d%d%d",&l,&r,&dd);
        if(l!=1)d[l-1]+=dd,upd(1,1,n-1,l-1,d[l-1]);
        if(r!=n)d[r]-=dd,upd(1,1,n-1,r,d[r]);
        printf("%d\n",1+seg[1][2][2]);
    }
}