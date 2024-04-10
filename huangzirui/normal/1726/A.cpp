#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int i,j,k,n,m,a[maxn];
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        int Min=1e9,Max=0;
        for(i=1;i<=n;i++)Min=min(Min,a[i]);
        for(i=1;i<=n;i++)Max=max(Max,a[i]);
        int Ans=max(a[n]-Min,Max-a[1]);
        for(i=1;i<n;i++)Ans=max(Ans,a[i]-a[i+1]);
        cout<<Ans<<endl;
    }
}