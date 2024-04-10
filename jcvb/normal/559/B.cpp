#include<cstdio>
#include<cassert>
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

char s1[222222],s2[222222];
int n;


void doit(char *s,int l,int r){
    if((r-l+1)%2==1)return;
    int mid=l+r>>1;
    doit(s,l,mid);
    doit(s,mid+1,r);
    int bo=0;
    for (int i=1;i<=mid-l+1;i++)if(s[l+i-1]>s[mid+i]){
        bo=1;
        break;
    }else if(s[l+i-1]<s[mid+i]){
        bo=0;
        break;
    }
    if(bo){
        for (int i=1;i<=mid-l+1;i++)
            swap(s[l+i-1],s[mid+i]);
    }

}
int main()
{
    scanf("%s",s1+1);
    scanf("%s",s2+1);
    n=strlen(s1+1);
    doit(s1,1,n);
    doit(s2,1,n);
    for (int i=1;i<=n;i++)if(s1[i]!=s2[i]){
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    return 0;
}