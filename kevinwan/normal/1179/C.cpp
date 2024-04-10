#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=1e6+10;
int seg[mn*3],laz[mn*3];
inline void prop(int x){
    seg[x]+=laz[x];
    if(x<mn*3/2){
        laz[x*2]+=laz[x];
        laz[x*2+1]+=laz[x];
    }
    laz[x]=0;
}
inline void upd(int x){
    prop(x*2),prop(x*2+1);
    seg[x]=min(seg[x*2],seg[x*2+1]);
}
#define mid (l+r>>1)
void update(int x,int l,int r,int a,int b,int c){
    prop(x);
    if(l==a&&r==b){
        laz[x]+=c;
    }
    else{
        if(b<=mid)update(x*2,l,mid,a,b,c);
        else if(a>mid)update(x*2+1,mid+1,r,a,b,c);
        else update(x*2,l,mid,a,mid,c),update(x*2+1,mid+1,r,mid+1,b,c);
        upd(x);
    }
}
int query(int x,int l,int r){
    if(l==r)return l;
    else{
        prop(x*2),prop(x*2+1);
        if(seg[x*2+1]<0)return query(x*2+1,mid+1,r);
        else return query(x*2,l,mid);
    }
}
int a[mn],b[mn];
int main(){
    int n,m,i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d",a+i),update(1,1,mn,1,a[i],-1);
    for(i=1;i<=m;i++)scanf("%d",b+i),update(1,1,mn,1,b[i],1);
    int q;
    scanf("%d",&q);
    while(q--){
        int s,d,f;
        scanf("%d%d%d",&s,&d,&f);
        if(s==1){
            update(1,1,mn,1,a[d],1);
            update(1,1,mn,1,f,-1);
            a[d]=f;
        }
        else{
            update(1,1,mn,1,b[d],-1);
            update(1,1,mn,1,f,1);
            b[d]=f;
        }
        prop(1);
        if(seg[1]>=0)printf("-1\n");
        else printf("%d\n",query(1,1,mn));
    }
}