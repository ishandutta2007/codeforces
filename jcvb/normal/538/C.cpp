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


int n,m;
int d[111111],h[111111];
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++){
        scanf("%d%d",&d[i],&h[i]);
    }
    int ma=0;
    ma=max(ma,h[1]+d[1]-1);
    ma=max(ma,h[m]+(n-d[m]));
    for (int i=1;i<m;i++){
        if(abs(h[i]-h[i+1])>d[i+1]-d[i]){
            printf("IMPOSSIBLE\n");
            return 0;
        }
        ma=max(ma,h[i]+(h[i+1]-h[i]+d[i+1]-d[i])/2);
    }
    printf("%d\n",ma);
    return 0;
}