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

int f[1111111];
int N=1000000;
int n;
int main()
{
    scanf("%d",&n);
    while(n--){
        int x;
        scanf("%d",&x);
        f[x]=1;
    }
    int ma=0;
    for (int i=N;i>=1;i--){
        if(f[i]){
            for (int j=i+i;j<=N;j+=i)
                f[i]=max(f[i],1+f[j]);
            ma=max(ma,f[i]);
        }
    }
    printf("%d\n",ma);
    return 0;
}