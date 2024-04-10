//Problem E
#include<bits/stdc++.h>
using namespace std;
int rd(){
    int a=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))a=(a<<1)+(a<<3)+(ch^48),ch=getchar();
    return a;
}
const int N=300005;
int n,a,c[2],b[N],z[N];
long long ans;
int main(){
    cin>>n;++c[0];
    for(int i=1;i<=n;i++){
        long long x;
        cin>>x;
        while(x){
            if(x&1)++b[i],a^=1;
            x>>=1;
        }
        ans+=c[a];++c[a];z[i]=a;//printf("%d\n",a);
    }
    //for(int i=1;i<=n;i++)cout<<b[i]<<" ";cout<<endl;
    //cout<<ans<<endl;
    for(int i=1;i<=n;i++){
        int mx=0,sum=0;
        for(int j=i;j<=min(n,i+61);j++){
            mx=max(mx,b[j]);
            sum+=b[j];
            if(mx>sum-mx&&z[i-1]==z[j])--ans;
        }
    }
    cout<<ans;
    return 0;
}