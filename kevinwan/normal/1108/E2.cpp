#include<bits/stdc++.h>
#include<functional>
using namespace std;
const int mn=1e5+10;
int seg[mn*3],laz[mn*3];
void prop(int x){
    if(laz[x]){
        seg[x]+=laz[x];
        if(x*2+1<mn*3){
            laz[x*2]+=laz[x];
            laz[x*2+1]+=laz[x];
        }
        laz[x]=0;
    }
}
void eval(int x){
    prop(x*2);
    prop(x*2+1);
    seg[x]=min(seg[x*2],seg[x*2+1]);
}
#define mid (l+r>>1)
void upd(int x,int l,int r,int a,int b,int c){
    if(l==a&&r==b)laz[x]+=c;
    else{
        if(b<=mid)upd(x*2,l,mid,a,b,c);
        else if(a>mid)upd(x*2+1,mid+1,r,a,b,c);
        else upd(x*2,l,mid,a,mid,c),upd(x*2+1,mid+1,r,mid+1,b,c);
        eval(x);
    }
}
int a[mn];
void init(int x,int l,int r){
    if(l==r)seg[x]=a[l];
    else{
        init(x*2,l,mid);
        init(x*2+1,mid+1,r);
        eval(x);
    }
}
int val[mn];
int bes;
int o[2][mn];
struct vesh{
    int l,r;
};
vesh v[mn];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    init(1,1,n);
    //cout<<"HAIL1";
    for(int i=1;i<=m;i++)scanf("%d%d",&v[i].l,&v[i].r),upd(1,1,n,v[i].l,v[i].r,-1);
    val[0]=0xc0c0c0c0;
    iota(o[0],o[0]+m+1,0);
    iota(o[1],o[1]+m+1,0);
    sort(o[0]+1,o[0]+m+1,[](int const&a,int const&b){return v[a].l<v[b].l;});
    sort(o[1]+1,o[1]+m+1,[](int const&a,int const&b){return v[a].r<v[b].r;});
    for(int i=1,j=1,k=1;i<=n;i++){
        while(j<=m&&v[o[0][j]].l<=i)upd(1,1,n,v[o[0][j]].l,v[o[0][j]].r,1),j++;
        while(k<=m&&v[o[1][k]].r<i)upd(1,1,n,v[o[1][k]].l,v[o[1][k]].r,-1),k++;
        prop(1);
        val[i]=a[i]-seg[1];
        if(val[i]>val[bes])bes=i;
    }
    printf("%d\n",val[bes]);
    vector<int>ans;
    for(int i=1;i<=m;i++)if(!(v[i].l<=bes&&v[i].r>=bes))ans.push_back(i);
    printf("%d\n",ans.size());
    for(int x:ans)printf("%d ",x);
}