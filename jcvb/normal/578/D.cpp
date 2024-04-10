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
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int n;
ll ans=0;
char s[111111];
int m;
int id[111111];
int ge(int x,int y){
    if(x==y)return -1;
    if(x>y)swap(x,y);
    return x*1000+y;
}
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    ans=1ll*(m-1)*n;
    for (int i=2;i<=n;i++)if(s[i-1]!=s[i])ans+=1ll*(i-1)*(m-1);
    for (int i=1;i<=n-1;i++)if(s[i]!=s[i+1])ans+=1ll*(n-i)*(m-1);
    for (int i=1;i<=n-1;i++)id[i]=ge(s[i],s[i+1]);
    for (int i=1;i<=n-1;i++)if(id[i]!=-1 && (i==1||id[i]!=id[i-1])){
        for (int j=i;j<=n-1 && id[j]==id[i];j++)ans-=(j-i+1);
    }
    cout<<ans<<endl;
    return 0;
}