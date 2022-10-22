#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef __int128 lll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod=1e9+7;
const ll mn=3e5+10;
ll seg[mn*4],laz[mn*4],num[mn*4];
void prop(int x){
    if(!laz[x])return;
    seg[x]+=laz[x];
    if(x*2+1<mn*4){
        laz[x*2]+=laz[x];
        laz[x*2+1]+=laz[x];
    }
    laz[x]=0;
}
void eval(int x){
    prop(x*2),prop(x*2+1);
    seg[x]=min(seg[x*2],seg[x*2+1]);
    num[x]=(seg[x]==seg[x*2]?num[x*2]:0)+(seg[x]==seg[x*2+1]?num[x*2+1]:0);
}
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
    if(l==r)seg[x]=0x3f3f3f3f,num[x]=1;
    else{
        init(x*2,l,mid);
        init(x*2+1,mid+1,r);
        eval(x);
    }
}
int a[mn],nxt[mn],lv[mn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    a[n+1]=0x3f3f3f3f;
    stack<int>s;
    s.push(n+1);
    memset(lv,0x3f,sizeof(lv));
    init(1,1,n);
    for(int i=n;i>=1;i--){
        nxt[i]=lv[a[i]];
        lv[a[i]]=i;
    }
    int ans=0;
    for(int i=n;i>=1;i--){
        if(nxt[i]!=0x3f3f3f3f)upd(1,1,n,nxt[i],n,0x3f3f3f3f);
        while(a[i]>a[s.top()]){
            int l=s.top();
            s.pop();
            upd(1,1,n,l,s.top()-1,a[i]-a[l]);
        }
        if(i!=n)upd(1,1,n,i+1,n,-1);
        upd(1,1,n,i,i,-0x3f3f3f3f+a[i]-1);
        prop(1);
        if(seg[1]==0)ans+=num[1];
        s.push(i);
    }
    printf("%d",ans);
}