#include<cstdio>
#include<algorithm>
#include<cassert>
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
int qp(int a,ll b,int mo){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
const int mo=1000000007;


ll a,b;


void doit(ll a,ll b){
    if(a==1 && b==1)return;
    if(a==1){
        printf("%I64dB",b-1);
        return;
    }
    if(b==1){
        printf("%I64dA",a-1);
        return;
    }
    if(a>b){
        printf("%I64dA",a/b);
        doit(a%b,b);
    }else{
        printf("%I64dB",b/a);
        doit(a,b%a);
    }
}

int main()
{
    cin>>a>>b;
    if(gcd(a,b)!=1){
        printf("Impossible\n");
    }else{
        doit(a,b);
        putchar('\n');
    }
    return 0;
}