#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=5e5+10;
const ll mod=1e6+3;
int a[mn];
int nxt[mn],lst[mn],fi[mn];
struct query{int l,r,i;bool operator<(const query&ot)const {return l<ot.l;}};
query q[mn];
int seg[mn*2];
void up(int x,int a){
    seg[x+=mn]=a;
    for(x>>=1;x;x>>=1)seg[x]=max(seg[x*2],seg[x*2+1]);
}
int qu(int l,int r){
    int ans=0;
    for(l+=mn,r+=mn;l<=r;l>>=1,r>>=1){
        if(l&1)ans=max(ans,seg[l++]);
        if(!(r&1))ans=max(ans,seg[r--]);
    }
    return ans;
}
int ans[mn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        nxt[i]=n+a[i];
        nxt[lst[a[i]]]=i;
        if(!fi[a[i]])fi[a[i]]=i;
        if(fi[a[i]]==lst[a[i]])up(fi[a[i]],i);
        lst[a[i]]=i;
    }
    for(int i=1;i<=n;i++)if(lst[i]&&lst[i]==fi[i])up(fi[i],n+i);
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&q[i].l,&q[i].r),q[i].i=i;
    }
    sort(q,q+m);
    int cl=1;
    for(int i=0;i<m;i++){
        while(cl<q[i].l){
            up(cl,0);
            if(nxt[cl]<=n)up(nxt[cl],nxt[nxt[cl]]);
            ++cl;
        }
        int v=qu(q[i].l,q[i].r);
        if(v<=q[i].r)ans[q[i].i]=0;
        else if(v<=n)ans[q[i].i]=a[v];
        else ans[q[i].i]=v-n;
    }
    for(int i=0;i<m;i++)printf("%d\n",ans[i]);
}