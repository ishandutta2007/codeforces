#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
int i,j,k,n,m,a[maxn],b[maxn];
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        if(n&1)puts("NO");
        else{
            int Max=0,lst=1;
            for(i=2;i<=n+1;i++)
                if(i==n+1 || a[i]!=a[i-1])
                    Max=max(Max,i-lst),lst=i;
            for(i=1;i<=n/2;i++)b[i*2-1]=a[i],b[i*2]=a[i+n/2];
            bool B=true;
            for(i=1;i<=n;i++){
                if(b[i]>b[i%n+1] && b[i]>b[(i+n-2)%n+1]);
                else if(b[i]<b[i%n+1] && b[i]<b[(i+n-2)%n+1]);
                else B=false;
            }
            if(B){
                puts("YES");
                for(i=1;i<=n/2;i++)printf("%d %d ",a[i],a[i+n/2]);
                puts("");
            }else puts("NO");
        }
    }
}