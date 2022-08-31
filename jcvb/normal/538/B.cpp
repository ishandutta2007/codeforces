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



int len=0;
int a[10];
int an[10];
int po[10];
int main()
{
    int n;
    scanf("%d",&n);
    while(n){
        a[len++]=n%10;
        n/=10;
    }
    po[0]=1;
    for (int i=1;i<=7;i++)po[i]=po[i-1]*10;
    int ma=0;
    for (int i=0;i<len;i++)ma=max(ma,a[i]);
    for (int i=1;i<=ma;i++)
        for (int j=0;j<len;j++)if(a[j]>=i)an[i]+=po[j];
    printf("%d\n",ma);
    for (int i=1;i<=ma;i++)printf("%d ",an[i]);
    printf("\n");
    return 0;
}