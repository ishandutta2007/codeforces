#include<bits/stdc++.h>
using namespace std;
int i,j,k,n,m,T;
int a[1000010],b[1000010];
int main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        if(m>=n)puts("0");
        else{
            long long Ans=0;
            for(i=1;i<=n;i++)
                b[i]=a[i]-(n-i),Ans+=a[i];
            sort(b+1,b+1+n);
            for(i=1;i<=m;i++)
                Ans-=b[n-i+1],Ans-=i-1;
            cout<<Ans<<endl;
        }
    }
}