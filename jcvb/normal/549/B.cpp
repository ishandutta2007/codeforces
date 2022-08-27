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

int n;
char s[105][105];
int cur[105]={0};
int tar[105];
int go[105];
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
    }
    for (int i=1;i<=n;i++)scanf("%d",&tar[i]);
    while(1){
        int u=0;
        for (int i=1;i<=n;i++)if(tar[i]==cur[i]){
            u=i;
            break;
        }
        if(u==0)break;
        for (int i=1;i<=n;i++)if(s[u][i]=='1')cur[i]++;
        go[u]=1;
    }
    int su=0;
    for (int i=1;i<=n;i++)if(go[i])su++;
    printf("%d\n",su);
    for (int i=1;i<=n;i++)if(go[i])printf("%d ",i);
    printf("\n");
    return 0;
}