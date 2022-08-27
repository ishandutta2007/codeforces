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


db work(int a,int b,int c,int d){
    db mi=1e18;
    if(b+c-a-d!=0)mi=min(mi,abs((1.0*a*d-1.0*b*c)/(1.0*b+c-a-d)));
    if(a+b+c+d!=0)mi=min(mi,abs((1.0*b*c-1.0*a*d)/(1.0*a+b+c+d)));
    if(a+c-b-d!=0)mi=min(mi,abs((1.0*a*d-1.0*b*c)/(1.0*a+c-b-d)));
    db B=b+c+a-d;
    db del=1.0*(b+c+a-d)*(b+c+a-d)-8*(1.0*b*c-1.0*a*d);
    if(del>=0){
        db x1=(-B+sqrt(del))/4.0;
        db x2=(-B-sqrt(del))/4.0;
        mi=min(mi,abs(x1));
        mi=min(mi,abs(x2));
    }
    return mi;
}
int main()
{
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(1ll*a*d==1ll*b*c){
        printf("%.10lf\n",0.0);
        return 0;
    }
    db mi=1e18;
    mi=min(mi,work(a,b,c,d));       
    mi=min(mi,work(b,d,a,c));       
    mi=min(mi,work(d,c,b,a));       
    mi=min(mi,work(c,a,d,b));       
    printf("%.10lf\n",mi);
    return 0;
}