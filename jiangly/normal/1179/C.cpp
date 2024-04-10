// remote judge
#include<bits/stdc++.h>
using namespace std;
const int N=300005,P=N*40;
int n,m,q,rt,tot;
int a[N],b[N],c[P][2],mx[P],tg[P];
void addp(int&p,int x){
    if(!p)
        p=++tot;
    tg[p]+=x;
    mx[p]+=x;
}
void add(int&p,int l,int r,int L,int R,int x){
    if(l>R||r<L)
        return;
    if(!p)
        p=++tot;
    if(l>=L&&r<=R)
        return addp(p,x);
    int mid=l+r>>1;
    if(tg[p]){
        addp(c[p][0],tg[p]);
        addp(c[p][1],tg[p]);
        tg[p]=0;
    }
    add(c[p][0],l,mid,L,R,x);
    add(c[p][1],mid+1,r,L,R,x);
    mx[p]=max(mx[c[p][0]],mx[c[p][1]]);
}
int query(int p,int l,int r){
    if(mx[p]<=0)
        return -1;
    if(l==r)
        return l;
    int mid=l+r>>1;
    if(tg[p]){
        addp(c[p][0],tg[p]);
        addp(c[p][1],tg[p]);
        tg[p]=0;
    }
    if(mx[c[p][1]]>0)
        return query(c[p][1],mid+1,r);
    return query(c[p][0],l,mid);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        add(rt,1,1e6,1,a[i],1);
    }
    for(int i=1;i<=m;++i){
        scanf("%d",&b[i]);
        add(rt,1,1e6,1,b[i],-1);
    }
    scanf("%d",&q);
    for(int i=1;i<=q;++i){
        int opt,x,y;
        scanf("%d%d%d",&opt,&x,&y);
        if(opt==1){
            add(rt,1,1e6,1,a[x],-1);
            a[x]=y;
            add(rt,1,1e6,1,a[x],1);
        }else{
            add(rt,1,1e6,1,b[x],1);
            b[x]=y;
            add(rt,1,1e6,1,b[x],-1);
        }
        printf("%d\n",query(1,1,1e6));
    }
    return 0;
}