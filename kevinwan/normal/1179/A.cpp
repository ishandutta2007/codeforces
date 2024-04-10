#include<bits/stdc++.h>
using namespace std;
const int mn=3e5+10;
int a[mn*2],ans[mn*2][2];
int main(){
    int n,q,i;
    scanf("%d%d",&n,&q);
    for(i=0;i<n;i++)scanf("%d",a+i);
    int m=0;
    for(i=1;i<n;i++){
        if(a[i]>m)m=i;
    }
    for(i=0;i<m;i++){
        ans[i][0]=a[i];
        ans[i][1]=a[i+1];
        a[i+n]=min(a[i],a[i+1]);
        a[i+1]=max(a[i],a[i+1]);
        a[i]=0;
    }
    for(i=0;i<n;i++)a[i]=a[i+m];
    while(q--){
        long long x;
        scanf("%lld",&x);
        x--;
        if(x<m)printf("%d %d\n",ans[x][0],ans[x][1]);
        else{
            x-=m;
            x%=n-1;
            printf("%d %d\n",a[0],a[1+x]);
        }
    }
}