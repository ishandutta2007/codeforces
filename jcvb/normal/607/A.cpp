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
#define cl(a) memset(a,0,sizeof(a))
using namespace std;
typedef long long ll;
typedef double db;
const db pi=3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862;
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
int mo=1000000007;
int inf=1061109567;
db eps=1e-6;
//ll inf=1000000000000000000ll;
int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define x1 x192837465
#define x2 x123456789
#define y1 y192837465
#define y2 y123456789


/*int go[1111111];
int f[1111111];int n;
int main()
{
    gn(n);
    for (int i=1;i<=n;i++){
        int x,y;
        gn(x);gn(y);
        x++;
        go[x]=y;
    }
    int ma=0;
    for (int i=1;i<=1000005;i++){
        if(go[i]==0)f[i]=f[i-1];
        else{
            f[i]=f[i-1];
            f[i]=max(f[i],1+f[max(i-go[i]-1,0)]);
        }
        ma=max(ma,f[i]);
    }
    printf("%d\n",n-ma);
    return 0;
}*/

struct node{
    int a,b;
}t[111111];int n;
int cmp(const node&a,const node&b){
    return a.a<b.a;
}
int arr[111111];
int f[111111];
int main()
{
    gn(n);
    for (int i=1;i<=n;i++){
        gn(t[i].a);gn(t[i].b);
    }
    sort(t+1,t+1+n,cmp);    
    for (int i=1;i<=n;i++)arr[i]=t[i].a;

    int ma=0;
    for (int i=1;i<=n;i++){
        int x=lower_bound(arr+1,arr+1+n,t[i].a-t[i].b)-arr-1;
        f[i]=1+f[x];
        ma=max(ma,f[i]);
    }
    printf("%d\n",n-ma);
    return 0;
}