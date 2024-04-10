#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5,inf=0x3f3f3f3f;
int a[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
signed main(){
    int T;
    T=read();
    while(T--){
        int n;
        n=read();
        for(int i=1;i<=n;i++)a[i]=read()&1;
        int s=0,t=0,res0=0,res1=0,ans0=0,ans1=0;
        for(int i=1;i<=n;i++)if(!a[i])s++;else t++;
        if(abs(s-t)>1){puts("-1");continue;}
        int pos;
        pos=1;for(int i=1;i<=n;i++)if(a[i])res1+=abs(i-pos),pos+=2;
        pos=2;for(int i=1;i<=n;i++)if(!a[i])res0+=abs(i-pos),pos+=2;
        ans0=min(res0,res1);res1=res0=0;
        pos=1;for(int i=1;i<=n;i++)if(!a[i])res0+=abs(i-pos),pos+=2;
        pos=2;for(int i=1;i<=n;i++)if(a[i])res1+=abs(i-pos),pos+=2;
        ans1=min(res0,res1);
        if(s>t)printf("%lld\n",ans1);
        else if(t>s)printf("%lld\n",ans0);
        else printf("%lld\n",min(ans1,ans0));
    }
    return 0;
}