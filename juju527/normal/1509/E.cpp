#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
int a[maxn];
ll read(){
    ll x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
ll f[64];
int main(){
    int T;
    T=read();
    f[0]=f[1]=1;
    for(int i=2;i<=63;i++)f[i]=f[i-1]+f[i-1];
    while(T--){
        int n;ll k;
        n=read();k=read();
        if(n<=63&&k>f[n]){puts("-1");continue;}
        for(int i=1;i<=n;i++){
            if((n-i)>62){a[i]=i;continue;}
            int c=0;
            for(int j=1;j<=n-i+1;j++){
                if(k>f[n-i+1-j])k-=f[n-i+1-j];
                else{c=j;break;}
            }
            for(int j=i;j<=i+c-1;j++)a[j]=i+c-1-j+i;
            i+=c-1;
        }
        for(int i=1;i<=n;i++)printf("%d ",a[i]);puts("");
    }
    return 0;
}