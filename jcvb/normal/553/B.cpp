#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
using namespace std;
typedef long long ll;
typedef double db;
void gn(int &x){
    int sg=1;char tmp;while(((tmp=getchar())<'0'||tmp>'9')&&tmp!='-');
    if(tmp=='-')sg=-1,x=0;else x=tmp-'0';
    while((tmp=getchar())>='0'&&tmp<='9')x=x*10+tmp-'0';
    x*=sg;
}
void gn(ll &x){
    int sg=1;char tmp;while(((tmp=getchar())<'0'||tmp>'9')&&tmp!='-');
    if(tmp=='-')sg=-1,x=0;else x=tmp-'0';
    while((tmp=getchar())>='0'&&tmp<='9')x=x*10+tmp-'0';
    x*=sg;
}
const int mo=1000000007;
int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}

ll f[55];
int n;
ll k;
int ans[55];
void work(int st,ll k){
    if(st>n)return;
    if(st==n){
        ans[st]=n;
        return;
    }
    if(k<=f[n-st]){
        ans[st]=st;
        work(st+1,k);
        return;
    }else{
        ans[st]=st+1;
        ans[st+1]=st;
        work(st+2,k-f[n-st]);
    }
}
int main()
{
    f[0]=1;f[1]=1;f[2]=2;
    for (int i=3;i<=52;i++)f[i]=f[i-1]+f[i-2];
    cin>>n>>k;
    work(1,k);
    for (int i=1;i<=n;i++)printf("%d ",ans[i]);
    printf("\n");
    return 0;
}