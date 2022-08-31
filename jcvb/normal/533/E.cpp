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
#define mo1 1000000007
#define mo2 998244353
#include<map>
typedef long long ll;
#define inf 10000000000000000ll
#define hashmod 3000007
#define sta 5555555
int sd=10009;
int ps1[111111],ps2[111111];
map<ll,int>ma;
int n;
struct has{
    ll S[sta];int V[sta],next[sta];
    int head[hashmod];
    int tot;
    void cl(){
        tot=0;
        memset(head,-1,sizeof(head));
    }
    ll push(ll s,ll v=0){
        int t=s%hashmod;
        for (int i=head[t];~i;i=next[i])if(S[i]==s)
            return V[i]|=v;
        S[tot]=s;V[tot]=v;next[tot]=head[t];head[t]=tot++;
        return v;
    }
}hh;
char s[111111],t[111111];

int ha1[111111],ha2[111111];
void work(char *s,int w){
    ha1[0]=0;
    for (int i=1;i<=n;i++)ha1[i]=(1ll*ha1[i-1]*sd+s[i])%mo1,ha2[i]=(1ll*ha2[i-1]*sd+s[i])%mo2;
    for (int i=0;i<=n;i++){
        for (int j=0;j<26;j++){
            int h1=(ha1[n]-1ll*ha1[i]*ps1[n-i]+1ll*ha1[i]*ps1[n-i+1]+1ll*(j+'a')*ps1[n-i])%mo1;
            int h2=(ha2[n]-1ll*ha2[i]*ps2[n-i]+1ll*ha2[i]*ps2[n-i+1]+1ll*(j+'a')*ps2[n-i])%mo2;
            if(h1<0)h1+=mo1;
            if(h2<0)h2+=mo2;
            ll su=(1ll*h1)<<32|h2;
            ///ma[su]|=w;
            hh.push(su,w);
        }
    }
}

int main()
{
    hh.cl();
    ps2[0]=ps1[0]=1;
    for (int i=1;i<=110000;i++)ps1[i]=1ll*ps1[i-1]*sd%mo1,ps2[i]=1ll*ps2[i-1]*sd%mo2;
    scanf("%d",&n);
    scanf("%s",s+1);
    scanf("%s",t+1);
    work(s,1);
    work(t,2);
    int ans=0;
    //for (map<ll,int >::iterator it=ma.begin();it!=ma.end();it++)if(it->second==3)ans++;
    for (int i=0;i<hh.tot;i++)if(hh.V[i]==3)ans++;
    printf("%d\n",ans);
    return 0;
}