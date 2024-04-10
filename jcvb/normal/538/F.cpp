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
int n;
int a[222222];
int f[222222];
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)scanf("%d",&a[i]);
    for (int v=2;v<=n;v++){
        int nex;
        for (int k=1;k<=n-1;k=nex+1){
            int xx=(v-2)/k;
            if(xx)nex=(v-2)/xx;
            else nex=n;
            if(a[v]<a[xx+1]){
                f[k]++;
                f[nex+1]--;
            }
        }
    }
    for (int i=2;i<=n-1;i++)f[i]+=f[i-1];
    for (int i=1;i<=n-1;i++)printf("%d ",f[i]);
    printf("\n");
    return 0;
}