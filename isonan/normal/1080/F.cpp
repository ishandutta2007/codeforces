#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int mx[8000001],lson[8000001],rson[8000001],root[300001],top,cnt,n,m,k;
struct point{
    int l,r,x;
}num[300001];
bool cmp(point a,point b){return a.l>b.l;}
void init(int &pos,int l,int r,int v){
    pos=++cnt;
    mx[pos]=v;
    if(l==r)return;
    init(lson[pos],l,(l+r)>>1,v);
    init(rson[pos],((l+r)>>1)+1,r,v);
}
void build(int &pos,int pre,int l,int r,int e,int x){
    pos=++cnt;
    mx[pos]=mx[pre];
    lson[pos]=lson[pre];
    rson[pos]=rson[pre];
    if(l==r){
        mx[pos]=min(mx[pos],x);
        return;
    }
    if((l+r)>>1>=e)build(lson[pos],lson[pre],l,(l+r)>>1,e,x);
    else build(rson[pos],rson[pre],((l+r)>>1)+1,r,e,x);
    mx[pos]=max(mx[lson[pos]],mx[rson[pos]]);
}
int query(int pos,int l,int r,int el,int er){
    if(el>r||er<l)return 0;
    if(el<=l&&er>=r)return mx[pos];
    return max(query(lson[pos],l,(l+r)>>1,el,er),query(rson[pos],((l+r)>>1)+1,r,el,er));
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;i++)scanf("%d%d%d",&num[i].l,&num[i].r,&num[i].x);
    init(root[0],1,n,2000000000);
    sort(num+1,num+k+1,cmp);
    for(int i=1;i<=k;i++)build(root[i],root[i-1],1,n,num[i].x,num[i].r);
    for(int i=1;i<=m;i++){
        int a,b,x,y;
        scanf("%d%d%d%d",&a,&b,&x,&y);
        int l=1,r=k,mid,ans=k+1;
        while(l<=r){
            mid=(l+r)>>1;
            if(num[mid].l>=x)ans=mid,l=mid+1;
            else r=mid-1;
        }
        if(ans==k+1)puts("no");
        else if(query(root[ans],1,n,a,b)<=y)puts("yes");
        else puts("no");
        cout.flush();
    }
}