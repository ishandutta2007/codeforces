#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 131072
#define mid (l+r)/2
int s[20][1<<18];
bool laz[20][1<<18];
void update(int bit,int x,int a,int b,int l,int r){
    if(a==l&&b==r){laz[bit][x]^=1;return;}
    else if(b<=mid)update(bit,x*2,a,b,l,mid);
    else if(a>mid)update(bit,x*2+1,a,b,mid+1,r);
    else update(bit,x*2,a,mid,l,mid),update(bit,x*2+1,mid+1,b,mid+1,r);
    s[bit][x]=0;
    if(laz[bit][x*2])s[bit][x]+=(r-l+1)/2-s[bit][x*2];
    else s[bit][x]+=s[bit][x*2];
    if(laz[bit][x*2+1])s[bit][x]+=(r-l+1)/2-s[bit][x*2+1];
    else s[bit][x]+=s[bit][x*2+1];
}
int query(int bit,int x,int a,int b,int l,int r){
    if(laz[bit][x])s[bit][x]=(r-l+1)-s[bit][x];
    if(x<maxn)laz[bit][x*2]^=laz[bit][x],laz[bit][x*2+1]^=laz[bit][x];
    laz[bit][x]=0;
    if(a==l&&b==r)return s[bit][x];
    else if(b<=mid)return query(bit,x*2,a,b,l,mid);
    else if(a>mid)return query(bit,x*2+1,a,b,mid+1,r);
    else return query(bit,x*2,a,mid,l,mid)+query(bit,x*2+1,mid+1,b,mid+1,r);
}
int main(){
    int n,q,x,i,j,a,b,c,d;
    scanf("%d",&n);
    for(i=0;i<n;i++){scanf("%d",&x);for(j=0;j<20;j++)s[j][maxn+i]=(x>>j)&1;}
    for(i=maxn-1;i;i--)for(j=0;j<20;j++)s[j][i]=s[j][2*i]+s[j][2*i+1];
    scanf("%d",&q);
    while(q--){
        scanf("%d%d%d",&a,&b,&c);
        b--,c--;
        if(a==1){
            ll ans=0;
            for(i=0;i<20;i++)ans+=((ll)query(i,1,b,c,0,maxn-1))<<i;
            cout<<ans<<"\n";
        }
        else{
            scanf("%d",&d);
            for(i=0;i<20;i++)if((d>>i)&1)update(i,1,b,c,0,maxn-1);
        }
    }
    
}