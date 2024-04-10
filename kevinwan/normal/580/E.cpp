#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int mn=1e5+10;
struct ht{
    const static ll mod1=1e9+7,mod2=1e9+9;
    ll a,b;
    ht operator+(const ht&ot)const{return {(a+ot.a)%mod1,(b+ot.b)%mod2};}
    ht operator-(const ht&ot)const{return {(a-ot.a+mod1)%mod1,(b+ot.b+mod2)%mod2};}
    ht operator*(const ht&ot)const{return {a*ot.a%mod1,b*ot.b%mod2};}
    ll hail(){return a*mod2+b;}
    ht(){a=b=0;}
    ht(ll x){a=x%mod1,b=x%mod2;}
    ht(ll aa,ll bb){a=aa%mod1,b=bb%mod2;}
};
ll mul=rand()+1473287;
string s;
ht p[mn],sp[mn],seg[mn*4],laz[mn*4];
#define mid ((l+r)>>1)
void prop(int x,int l,int r){
    if(!laz[x].a)return;
    seg[x]=laz[x]*sp[r-l];
    if(x*2+1<mn*4){
        laz[x*2]=laz[x];
        laz[x*2+1]=laz[x];
    }
    laz[x]=0;
}
void eval(int x,int l,int r){
    prop(x*2,l,mid),prop(x*2+1,mid+1,r);
    seg[x]=seg[x*2]*p[r-mid]+seg[x*2+1];
}
void upd(int x,int l,int r,int a,int b,ll c){
    if(l==a&&r==b)laz[x]=c;
    else{
        prop(x,l,r);
        if(b<=mid)upd(x*2,l,mid,a,b,c);
        else if(a>mid)upd(x*2+1,mid+1,r,a,b,c);
        else upd(x*2,l,mid,a,mid,c),upd(x*2+1,mid+1,r,mid+1,b,c);
        eval(x,l,r);
    }
}
ht qu(int x,int l,int r,int a,int b){
    prop(x,l,r);
    if(l==a&&r==b)return seg[x];
    else{
        if(b<=mid)return qu(x*2,l,mid,a,b);
        else if(a>mid)return qu(x*2+1,mid+1,r,a,b);
        else return qu(x*2,l,mid,a,mid)*p[b-mid]+qu(x*2+1,mid+1,r,mid+1,b);
    }
}
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    cin>>s;
    sp[0]=p[0]=1;
    for(int i=1;i<=n;i++)p[i]=p[i-1]*mul,sp[i]=sp[i-1]+p[i];
    for(int i=0;i<n;i++)upd(1,0,n-1,i,i,s[i]);
    m+=k;
    while(m--){
        int a,b,c;
        scanf("%d",&a);
        if(a==1){
            scanf("%d%d%d",&a,&b,&c);
            upd(1,0,n-1,a-1,b-1,c+'0');
        }
        else{
            scanf("%d%d%d",&a,&b,&c);
            if(b-a+1<=c)printf("YES\n");
            else printf("%s\n",qu(1,0,n-1,a-1,b-1-c).hail()==qu(1,0,n-1,a-1+c,b-1).hail()?"YES":"NO");
        }
    }
}