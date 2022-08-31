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
int n,m;
char s[105][105];
int a[105][105];
int f[105][105];

int main()
{
    scanf("%d%d",&n,&m);
    int cnt=0;
    for (int i=1;i<=n;i++)scanf("%s",s[i]+1);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)a[i][j]=s[i][j]=='W'?1:-1;
    for (int i=n;i>=1;i--)
        for (int j=m;j>=1;j--){
            int al=f[i+1][j]+f[i][j+1]-f[i+1][j+1];
            if(al!=a[i][j]){
                cnt++;
            }
                f[i][j]=a[i][j];
        }
    printf("%d\n",cnt);
    return 0;

}