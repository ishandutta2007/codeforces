#include <bits/stdc++.h>
using namespace std;
const int mn=1<<18;
int seg[mn*3];
void prop(int x){
    seg[x*2]=max(seg[x*2],seg[x]);
    seg[x*2+1]=max(seg[x*2+1],seg[x]);
    seg[x]=0;
}
#define mid (l+r>>1)
void update(int x,int l,int r,int a,int b){
    if(l==r)seg[x]=b;
    else{
        prop(x);
        if(a<=mid)update(x*2,l,mid,a,b);
        else update(x*2+1,mid+1,r,a,b);
    }
}
int main()
{
    int n,q,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",seg+i+mn);
    scanf("%d",&q);
    while(q--){
        int a,b;
        scanf("%d",&a);
        if(a==1){
            scanf("%d%d",&a,&b);
            update(1,0,mn-1,a-1,b);
        }
        else{
            scanf("%d",&a);
            seg[1]=max(seg[1],a);
        }
    }
    for(i=1;i<mn;i++)prop(i);
    for(i=0;i<n;i++)printf("%d ",seg[i+mn]);
}