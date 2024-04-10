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


int a,b,c,l;




ll work2(int l){
    if(l<0)return 0;
    return 1ll*(l+1)*(l+2)/2;
}
ll work(int a,int d,int l){
    ll an=0;
    for (int i=0;i<=l;i++)an+=work2(min(l-i,a+i-d));
    return an;
}
int main()
{
    scanf("%d%d%d%d",&a,&b,&c,&l);
    ll to=1ll*(l+1)*(l+2)*(l+3)/6;
    to-=work(a,b+c,l);
    to-=work(b,a+c,l);
    to-=work(c,a+b,l);
    cout<<to<<endl;
    return 0;
}