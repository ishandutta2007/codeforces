#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int maxn=1e3+5;
ll c[maxn];
int suf[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
signed main(){
    int n;
    n=read();
    for(int i=1;i<=n;i++)c[i]=(i&1)?read():-read();
    if(n==1){puts("0");return 0;}
    for(int i=n;i>=1;i--){
        if(i%2==0)continue;
        ll sum=0;
        int pos=0;
        for(int j=i;j<=n;j++){
            sum+=c[j];
            if(sum<=0){pos=j;break;}
        }
        if(sum<0)suf[i]=1;
        else if(sum==0)suf[i]=suf[pos+1]+1;
    }
    int pos=1,p=c[1],q=c[2],res=0;
    while(pos<=n){
        if(p+q<0)res+=p;
        else res-=q,res+=suf[pos+2],c[pos+2]+=p+q;
        pos+=2;
        p=c[pos],q=c[pos+1];
    }
    printf("%lld\n",res);
    return 0;
}