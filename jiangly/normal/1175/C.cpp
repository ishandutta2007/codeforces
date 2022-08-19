// remote judge
#include<bits/stdc++.h>
using namespace std;
const int MAXN=200000;
int T,n,k;
int a[MAXN];
pair<bool,int>check(int*a,int n,int k,int l){
    for(int i=0;i<n-k;++i)
        if(a[i+k]-a[i]<=l)
            return {true,(a[i]+a[i+k])>>1};
    return {false,-1};
}
int main(){
    scanf("%d",&T);
    for(;T>0;--T){
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;++i)
            scanf("%d",&a[i]);
        int l=0,r=1e9,ans=a[0];
        for(;l!=r;){
            int mid=(l+r)>>1;
            pair<bool,int>x=check(a,n,k,mid*2);
            if(x.first){
                ans=x.second;
                r=mid;
            }else
                l=mid+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}