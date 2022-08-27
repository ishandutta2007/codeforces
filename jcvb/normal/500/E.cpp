#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
int n,q;
int x[200005],h[200005];
struct que{
    int l,r,i;
}qu[200005];
int cmp(const que&a,const que&b){
    return a.l>b.l;
}
ll ans[200005];
int lx[200005],rx[200005],lid[200005],rid[200005],top=0;
int su[200005]={0};
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)scanf("%d%d",&x[i],&h[i]);
    scanf("%d",&q);
    for (int i=1;i<=q;i++){
        scanf("%d%d",&qu[i].l,&qu[i].r);
        qu[i].i=i;
    }
    sort(qu+1,qu+1+q,cmp);
    int cur=1;
    for (int i=n;i>=1;i--){
        int ri=0;
        int rd=i;
        while(top && x[i]+h[i]>=lx[top]){
            ri=rx[top];
            rd=rid[top];
            top--;
        }
        ri=max(ri,x[i]+h[i]);
        top++;
        lx[top]=x[i];
        rx[top]=ri;
        lid[top]=i;
        rid[top]=rd;
        if(top>=2)su[top-1]=su[top-2]+lx[top-1]-rx[top];
        //work i
        while(cur<=q && qu[cur].l==i){
            int r=qu[cur].r;
            int lef=1,rig=top,mid;
            while(lef<=rig){
                mid=lef+rig>>1;
                if(lid[mid]<=r && r<=rid[mid]){
                    break;
                }else if(r>rid[mid]){
                    rig=mid-1;
                }else lef=mid+1;
            }
            ans[qu[cur].i]=su[top-1]-su[mid-1];
            cur++;
        }
    }
    for (int i=1;i<=q;i++){

        //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        printf("%I64d\n",ans[i]);
    }
    return 0;
}