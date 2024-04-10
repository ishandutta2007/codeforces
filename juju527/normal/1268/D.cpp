#include<bits/stdc++.h>
using namespace std;
const int maxn=2005,mod=998244353;
int n;
char s[maxn];
int a[maxn][maxn];
int out[maxn],d[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
void trans(int x){
    for(int i=1;i<=n;i++){
        if(i==x)continue;
        out[x]-=a[x][i];a[x][i]^=1;out[x]+=a[x][i];
        out[i]-=a[i][x];a[i][x]^=1;out[i]+=a[i][x];
    }
    return ;
}
bool check(){
    for(int i=1;i<=n;i++)d[i]=out[i];
    sort(d+1,d+n+1);
    int sum=0;
    for(int i=1;i<n;i++){
        sum+=d[i];
        if(sum==i*(i-1)/2)return 0;
    }
    return 1;
}
namespace task1{
    void solve(){
        int S=(1<<n),mn=0x3f3f3f3f,res=0;
        for(int i=0;i<S;i++){
            int num=0;
            for(int j=0;j<n;j++)if(i&(1<<j))trans(j+1),num++;
            if(check()){
                if(num<mn)mn=num,res=1;
                else if(num==mn)res++;
            }
            for(int j=0;j<n;j++)if(i&(1<<j))trans(j+1);
        }
        if(mn==0x3f3f3f3f)puts("-1");
        else{
            for(int i=1;i<=mn;i++)res=1ll*res*i%mod;
            printf("%d %d\n",mn,res);
        }
        exit(0);
    }
};
int main(){
    n=read();
    for(int i=1;i<=n;i++){
        scanf("%s",s+1);
        for(int j=1;j<=n;j++)a[i][j]=s[j]-'0',out[i]+=a[i][j];
    }
    if(check()){puts("0 1");return 0;}
    if(n<=6)task1::solve();
    int res=0;
    for(int i=1;i<=n;i++){
        trans(i);
        res+=check();
        trans(i);
    }
    printf("1 %d\n",res);
    return 0;
}