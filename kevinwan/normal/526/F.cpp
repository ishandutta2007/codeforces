#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef __int128 lll;
const ll mod=1e9+7;
const int mn=3e5+10;
int val[mn*4],laz[mn*4],num[mn*4];
void prop(int x){
    if(!laz[x])return;
    val[x]+=laz[x];
    if(x*2+1<mn*4){
        laz[x*2]+=laz[x];
        laz[x*2+1]+=laz[x];
    }
    laz[x]=0;
}
void eval(int x){
    prop(x*2),prop(x*2+1);
    val[x]=min(val[x*2],val[x*2+1]);
    num[x]=(val[x]==val[x*2]?num[x*2]:0)+(val[x]==val[x*2+1]?num[x*2+1]:0);
}
int v[mn];
#define mid ((l+r)>>1)
void upd(int x,int l,int r,int a,int b,int c){
    if(l==a&&r==b)laz[x]+=c;
    else{
        prop(x);
        if(b<=mid)upd(x*2,l,mid,a,b,c);
        else if(a>mid)upd(x*2+1,mid+1,r,a,b,c);
        else upd(x*2,l,mid,a,mid,c),upd(x*2+1,mid+1,r,mid+1,b,c);
        eval(x);
    }
}
void init(int x,int l,int r){
    if(l==r)val[x]=0x3f3f3f3f,num[x]=1;
    else init(x*2,l,mid),init(x*2+1,mid+1,r),eval(x);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        v[a]=b;
    }
    stack<int>ma,mi;
    ma.push(n+1);
    mi.push(n+1);
    init(1,1,n);
    ll ans=0;
    for(int i=n;i>=1;i--){
        while(ma.top()!=n+1&&v[i]>v[ma.top()]){
            int l=ma.top();
            ma.pop();
            int r=ma.top()-1;
            upd(1,1,n,l,r,v[i]-v[l]);
        }
        while(mi.top()!=n+1&&v[i]<v[mi.top()]){
            int l=mi.top();
            mi.pop();
            int r=mi.top()-1;
            upd(1,1,n,l,r,v[l]-v[i]);
        }
        if(i<n)upd(1,1,n,i+1,n,-1);
        upd(1,1,n,i,i,-0x3f3f3f3f);
        prop(1);
        if(val[1]==0)ans+=num[1];
        mi.push(i),ma.push(i);
    }
    printf("%lld",ans);
}