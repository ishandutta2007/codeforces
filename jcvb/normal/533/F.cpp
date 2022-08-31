#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>
#include<queue>
#include<map>
using namespace std;
#define mo 1000000007
#include<map>
typedef long long ll;
int qp(int a,ll b){
    int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;
}
#define inf 10000000000000000ll


int ans[222222],atot=0;
char s[222222],t[222222];
ll ct[26];
int n,m;
ll cs[26];
int sd=10007;
map<pair<ll,ll>,int>ma;
ll ps[222222];
int test(){
    ma.clear();
    for (int i=0;i<26;i++){
        if(cs[i]==ct[i])continue;
        if(ma[make_pair(ct[i],cs[i])])ma[make_pair(ct[i],cs[i])]--;
        else ma[make_pair(cs[i],ct[i])]++;
    }
    for (map<pair<ll,ll>,int>::iterator it=ma.begin();it!=ma.end();it++){
        if(it->second)return 0;
    }
    return 1;
}
int main()
{
    ps[0]=1;
    for (int i=1;i<=211111;i++)ps[i]=ps[i-1]*sd;
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    scanf("%s",t+1);
    for (int i=1;i<=m;i++)ct[t[i]-'a']+=ps[m-i+1];
    for (int i=1;i<=m;i++)cs[s[i]-'a']+=ps[m-i+1];
    for (int i=1;i+m-1<=n;i++){
        if(test())ans[++atot]=i;
        cs[s[i]-'a']-=ps[m];
        for (int j=0;j<26;j++)cs[j]*=sd;
        cs[s[i+m]-'a']+=ps[1];
    }
    printf("%d\n",atot);
    for (int i=1;i<=atot;i++)printf("%d ",ans[i]);
    printf("\n");
    return 0;
}