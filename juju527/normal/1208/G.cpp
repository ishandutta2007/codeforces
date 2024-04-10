#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+5;
int n,k,m;
int a[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int len;
int p[maxn],phi[maxn];
bool bj[maxn];
void pre(){
    for(int i=2;i<=n;i++){
        if(!bj[i])p[++len]=i,phi[i]=i-1;
        for(int j=1;i*p[j]<=n&&j<=len;j++){
            bj[i*p[j]]=1;
            phi[i*p[j]]=phi[i]*(p[j]-1);
            if(i%p[j]==0){phi[i*p[j]]=phi[i]*p[j];break;}
        }
    }
    return ;
}
int main(){
    n=read();k=read();
    if(k==1){puts("3");return 0;}
    pre();
    for(int i=3;i<=n;i++)a[++m]=phi[i];
    sort(a+1,a+m+1);
    ll res=0;
    for(int i=1;i<=k;i++)res+=a[i];
    printf("%lld\n",res+2);
    return 0;
}