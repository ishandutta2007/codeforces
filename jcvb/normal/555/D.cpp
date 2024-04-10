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
    int sg=1;char tmp;while(((tmp=getchar())<'0'||tmp>'9')&&tmp!='-');
    if(tmp=='-')sg=-1,x=0;else x=tmp-'0';
    while((tmp=getchar())>='0'&&tmp<='9')x=x*10+tmp-'0';
    x*=sg;
}
void gn(ll &x){
    int sg=1;char tmp;while(((tmp=getchar())<'0'||tmp>'9')&&tmp!='-');
    if(tmp=='-')sg=-1,x=0;else x=tmp-'0';
    while((tmp=getchar())>='0'&&tmp<='9')x=x*10+tmp-'0';
    x*=sg;
}
const int mo=1000000007;
int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}


int n,m;
int a[211111];


inline int getnext(int id,int len,int dir){//1 right 0 left
    if(dir==1){
        int tar=a[id]+len;
        int nu=upper_bound(a+1,a+1+n,tar)-a-1;
        return nu;
    }else{
        int tar=a[id]-len;
        int nu=lower_bound(a+1,a+1+n,tar)-a;
        return nu;
    }
}

int calc(int id,int len,int dir){
    int nex=getnext(id,len,dir),nex2=getnext(nex,len-abs(a[id]-a[nex]),!dir);
    if(nex2==id){
        int sun=2*abs(a[id]-a[nex]);
        if(sun==0)return id;
        else return calc(id,len%sun,dir);
    }else return calc(nex,len-abs(a[id]-a[nex]),!dir);
}
int ord[222222];
int fan[222222];
int cmp(int i,int j){
    return a[i]<a[j];
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)scanf("%d",&a[i]);
    for (int i=1;i<=n;i++)ord[i]=i;
    sort(ord+1,ord+1+n,cmp);
    for (int i=1;i<=n;i++)fan[ord[i]]=i;
    sort(a+1,a+1+n);
    while(m--){
        int id,len;
        scanf("%d%d",&id,&len);
        printf("%d\n",ord[calc(fan[id],len,1)]);
    }
    return 0;
}