#include<bits/stdc++.h>
using namespace std;
#define mid (l+r>>1)
const int mn=3e5+10;
int a[mn],b[mn],seg[mn*8];
void up(int x,int l,int r,int a,int b){
    if(l==r)seg[x]=b;
    else{
        if(a<=mid)up(x*2,l,mid,a,b);
        else up(x*2+1,mid+1,r,a,b);
        seg[x]=min(seg[x*2],seg[x*2+1]);
    }
}
int qu(int x,int l,int r,int k){
    if(l==r)return l;
    else{
        if(seg[x*2]<=k)return qu(x*2,l,mid,k);
        else return qu(x*2+1,mid+1,r,k);
    }
}
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int n,i;
        bool ded=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)scanf("%d",a+i),up(1,0,n-1,i,a[i]);
        for(i=0;i<n;i++)scanf("%d",b+i);
        for(i=0;i<n;i++){
            int pos=qu(1,0,n-1,b[i]);
            if(a[pos]==b[i]){
                up(1,0,n-1,pos,0x3f3f3f3f);
                a[pos]=0x3f3f3f3f;
            }
            else{
                ded=1;
            }
        }
        if(ded)printf("NO\n");
        else printf("YES\n");
    }
}