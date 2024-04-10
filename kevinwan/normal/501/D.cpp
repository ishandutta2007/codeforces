#include <bits/stdc++.h>
using namespace std;
const int mn=2e5+10;
int bit[mn];
void update(int a,int b){for(;a<mn;a+=a&-a)bit[a]+=b;}
int query(int a){int b=0;for(;a;a-=a&-a)b+=bit[a];return b;}
int a[mn],v[mn],n;
void go(){
    int i;
    for(i=0;i<n;i++)scanf("%d",a+i),a[i]++;
    for(i=1;i<=n;i++)update(i,1);
    for(i=0;i<n;i++){
        v[i]+=query(a[i])-1;
        update(a[i],-1);
    }
}
int main()
{
    int i;
    scanf("%d",&n);
    go();
    go();
    for(i=n-1;i;i--){
        if(v[i]>=n-i)v[i]-=n-i,v[i-1]++;
    }
    v[0]%=n;
    for(i=1;i<=n;i++)update(i,1);
    for(i=0;i<n;i++){
        int cur=0,tot=0;
        for(int j=1<<17;j;j>>=1){
            if(cur+j>n)continue;
            if(tot+bit[cur+j]<v[i]+1)cur+=j,tot+=bit[cur];
        }
        printf("%d ",cur);
        update(cur+1,-1);
    }
}