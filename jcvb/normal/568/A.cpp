#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
using namespace std;
typedef long long ll;
typedef double db;
const db pi=acos(-1);
void gn(int &x){
    int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c=='-')sg=-1,x=0;else x=c-'0';
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
    x*=sg;
}
void gn(ll &x){
    int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c=='-')sg=-1,x=0;else x=c-'0';
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
    x*=sg;
}
const int mo=1000000007;
int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}

int pr[5555555],tot=0;
int vis[5555555];
void sieve(int n){
    for (int i=2;i<=n;i++){
        if(!vis[i]){
            pr[tot++]=i;
        }
        for (int j=0;j<tot && pr[j]*i<=n;j++){
            vis[i*pr[j]]=1;
            if(i%pr[j]==0){
                break;
            }
        }
    }
}       
int tes(int x){
    int y=x;int ans=0;
    while(y){
        int t=y%10;y/=10;
        ans=ans*10+t;
    }
    return ans==x;
}
int pal[5555555];
int N=2333333;
int main()
{
    int p,q;
    scanf("%d%d",&p,&q);
    sieve(N);
    for (int i=1;i<=N;i++)pal[i]=tes(i);
    int ma=0;
    int cpr=0,cpl=0;
    for (int i=1;i<=N;i++){
        if(pal[i])cpl++;
        if(i>=2 && !vis[i])cpr++;
        if(1ll*q*cpr<=1ll*p*cpl)ma=i;
    }
    printf("%d\n",ma);
    return 0;
}