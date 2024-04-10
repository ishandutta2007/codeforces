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

int a,b;

db work1(){
    int t=(a-b)/b;
    t/=2;
    return 1.0*(a-b)/2/t;
}
db work2(){
    int t=(a+b)/b;
    t/=2;
    return 1.0*(a+b)/2/t;
}
int main(){
    scanf("%d%d",&a,&b);
    if(b>a){
        printf("-1\n");
        return 0;
    }
    if(a==b){
        printf("%.10lf\n",1.0*b);
        return 0;
    }
    db ans=1e18;
    ans=min(ans,work1());
    ans=min(ans,work2());
    printf("%.10lf\n",ans);
    return 0;
}