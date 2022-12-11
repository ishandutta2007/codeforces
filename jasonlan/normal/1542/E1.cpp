#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
const int maxn=501;
int n;
int cnt[maxn][maxn*maxn/2];
int cw[maxn][maxn];
int mod;
int f[maxn];
inline int read(){
    int res=0;
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return res;
}
int qmod(int x){
    return x>=mod?x-mod:x;
}
int qdec(int x){
    return x<0?x+mod:x;
}
int GetCW(int m,int x){
    int res=0;
    for(int i=x+1;i<=m*(m-1)/2;++i)
        res=qmod(res+1ll*qdec(cnt[m][i]-cnt[m][i-1])*cnt[m][i-x-1]%mod);
    return res;
}
void getcnt(){
    cnt[1][0]=1;
    for(int i=2;i<=n;++i){
        for(int j=0;j<=(i-1)*(i-2)/2;++j){
            cnt[i][j]=qmod(cnt[i][j]+cnt[i-1][j]);
            cnt[i][j+i]=qdec(cnt[i][j+i]-cnt[i-1][j]);
        }
        for(int j=1;j<=i*(i-1)/2;++j)
            cnt[i][j]=qmod(cnt[i][j-1]+cnt[i][j]);
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=i*(i-1)/2;++j)
            cnt[i][j]=qmod(cnt[i][j]+cnt[i][j-1]);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=i;++j)
            cw[i][j]=GetCW(i,j);
}
void proc(){
    n=read();mod=read();
    getcnt();
    f[1]=0;
    for(int i=2;i<=n;++i){
        f[i]=1ll*f[i-1]*i%mod;
        //
        for(int j=1;j<i;++j)
            for(int k=j+1;k<=i;++k)
                f[i]=qmod(f[i]+cw[i-1][k-j]);// cnt_A + j > cnt_B + k
    }
    cout<<f[n]<<endl;
}
int main(){
    int T=1;
    while(T--)proc();
    return 0;
}