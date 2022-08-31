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



char s[1000];
char t[]="CODEFORCES";
int m=10;
int n;
char u[1000];
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    for (int i=1;i<=n;i++)
        for (int j=i;j<=n;j++){
            int tot=0;
            for (int k=1;k<=n;k++)if(k<i || k>j)u[tot++]=s[k];
            u[tot]=0;
            if(!strcmp(u,t)){
                printf("YES\n");
                return 0;
            }
        }
    printf("NO\n");
    return 0;
}