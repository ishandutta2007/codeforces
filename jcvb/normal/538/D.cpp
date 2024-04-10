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
char s[55][55];
int v[111][111]={0};
int ma[55][55];
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    for (int i1=1;i1<=n;i1++)
        for (int j1=1;j1<=n;j1++)if(s[i1][j1]=='o'){
            for (int i2=1;i2<=n;i2++)
                for (int j2=1;j2<=n;j2++)if(s[i2][j2]=='.'){
                    v[i2-i1+n][j2-j1+n]=1;
                }
        }
    for (int i1=1;i1<=n;i1++)
        for (int j1=1;j1<=n;j1++)if(s[i1][j1]=='o'){
            for (int i2=1;i2<=n;i2++)
                for (int j2=1;j2<=n;j2++)if(s[i2][j2]=='x'){
                    if(v[i2-i1+n][j2-j1+n]==0)ma[i2][j2]=1;
                }
        }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)if(s[i][j]=='x' && !ma[i][j]){
            printf("NO\n");
            return 0;
        }
    printf("YES\n");
    for (int i=1;i<=2*n-1;i++){
        for (int j=1;j<=2*n-1;j++){
            if(i==n && j==n)putchar('o');
            else if(v[i][j])putchar('.');
            else putchar('x');
        }
        putchar('\n');
    }
    return 0;
}