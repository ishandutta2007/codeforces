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
#define mo 1000000007
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
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int n;

int p,a;

char str[1005];

int s[1005];int le;

int r[5555];int cn=0;

int tmp[5555];
int divi(){
    ll cur=0;
    int ini0=0;
    int tt=0;
    for (int i=1;i<=le;i++){
        cur=cur*10+s[i];
        int q=cur/p;cur%=p;
        if(q==0 && !ini0)continue;
        else{
            tmp[++tt]=q;
            ini0=1;
        }
    }
    le=tt;
    for (int i=1;i<=tt;i++)s[i]=tmp[i];
    return int(cur);
}

int f[3500][2][2][3500];

inline int calc(int a,int b){
    if(a>b)return 0;
    return int((1ll*(a+b)*(b-a+1)/2)%mo);
}
inline int get(int i,int les,int pre,int tot){
    if(i==-1)return pre==0 && tot>=a;
    if(f[i][les][pre][tot]!=-1)return f[i][les][pre][tot];
    
    int ans=0;
    // bujin
    if(pre){
        if(les==0)ans=(ans+1ll*(p-r[i]-1)*get(i-1,0,0,tot) + 1ll*(calc(p-(r[i]-1)-1,p-(0)-1))*get(i-1,1,0,tot))%mo;
        else ans=(ans+1ll*(calc(1,p-0-1))*get(i-1,1,0,tot))%mo;
    }else{
        if(les==0)ans=(ans+1ll*(r[i]+1)*get(i-1,0,0,tot) + 1ll*(calc(0+1,r[i]-1+1))*get(i-1,1,0,tot))%mo;
        else ans=(ans+1ll*(calc(0+1,p-1+1))*get(i-1,1,0,tot))%mo;
    }
    //jin
    if(pre){
        if(les==0)ans=(ans+1ll*(p-r[i]+1-1)*get(i-1,0,1,tot+1) + 1ll*(calc(p-(r[i]-1-1)-1,p))*get(i-1,1,1,tot+1))%mo;
        else ans=(ans+1ll*(calc(p-(p-2)-1,p))*get(i-1,1,1,tot+1))%mo;
    }else{
        if(les==0)ans=(ans+1ll*(r[i]-1+1)*get(i-1,0,1,tot+1) + 1ll*(calc(0+1,max(0,r[i]-1-1+1)))*get(i-1,1,1,tot+1))%mo;
        else ans=(ans+1ll*(calc(0+1,p-1-1+1))*get(i-1,1,1,tot+1))%mo;
    }
    return f[i][les][pre][tot]=ans;
}
int main()
{
    scanf("%d%d",&p,&a);
    scanf("%s",str+1);
    le=strlen(str+1);
    for (int i=1;i<=le;i++)s[i]=str[i]-'0';

    while(le!=0)r[cn++]=divi();
    if(a>cn){
        printf("0\n");
        return 0;
    }
    memset(f,-1,sizeof(f));
    int ans=0;
    ans+=get(cn-1,0,0,0);
    printf("%d\n",ans);
    return 0;
}