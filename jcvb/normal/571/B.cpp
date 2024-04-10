#include<cstdio>
#include<ctime>
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
int n,a[333333];

int k;
int num1,num2;
int sz1,sz2;
int f[5555][5555];
int df(int x){
    return a[x+1]-a[x];
}
int main()
{
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    a[0]=a[1];
    num2=n%k;
    num1=k-num2;
    sz1=n/k;
    sz2=sz1+1;

    for (int i=0;i<=num1;i++)
        for (int j=0;j<=num2;j++){
            if(i==0 && j==0)continue;
            if(i!=0){
                f[i][j]=max(f[i][j],f[i-1][j]+df((i-1)*sz1+j*sz2));
            }
            if(j!=0){
                f[i][j]=max(f[i][j],f[i][j-1]+df(i*sz1+(j-1)*sz2));
            }
        }
    int an=a[n]-a[1]-f[num1][num2];
    printf("%d\n",an);
    return 0;
}