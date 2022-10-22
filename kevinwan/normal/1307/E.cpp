#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
const int mn=5e3+10;
const ll mod=1e9+7;
int a[mn];
vector<int>bes1[mn],bes2[mn];
vector<ll>num1[mn],num2[mn];
vector<int>h[mn],p[mn];
void hail(int x){
    sort(h[x].begin(),h[x].end());
    bes1[x].resize(p[x].size()+1);
    bes2[x].resize(p[x].size()+1);
    num1[x].resize(p[x].size()+1);
    num2[x].resize(p[x].size()+1);
    for(int i=0;i<=p[x].size();i++)num1[x][i]=num2[x][i]=1,bes2[x][i]=-mn;
    for(int i=0;i<=p[x].size();i++){
        int exi=upper_bound(h[x].begin(),h[x].end(),i)-lower_bound(h[x].begin(),h[x].end(),i);
        int lei=upper_bound(h[x].begin(),h[x].end(),i)-h[x].begin();
        int leni=upper_bound(h[x].begin(),h[x].end(),p[x].size()-i)-h[x].begin();
        ll num=1LL*lei*leni-min(lei,leni);
        if(num)bes1[x][i]=2,num1[x][i]=num;
        else{
            if(lei+leni)bes1[x][i]=1,num1[x][i]=lei+leni;
        }
        num=1LL*exi*leni;
        if(p[x].size()-i>=i)num-=1LL*exi;
        if(num)bes2[x][i]=2,num2[x][i]=num;
        else{
            if(exi)bes2[x][i]=1,num2[x][i]=exi;
        }
    }
}
ll po(ll a,ll b=mod-2){
    ll ans=1;
    for(;b;b>>=1,a*=a,a%=mod)if(b&1)ans*=a,ans%=mod;
    return ans;
}
int ind[mn];
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",a+i),p[a[i]].push_back(i);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        h[a].push_back(b);
    }
    for(int i=1;i<=n;i++)hail(i);
    ll ans=0,num=0;
    ll cans=0,cnum=1;
    for(int i=1;i<=n;i++)cans+=bes1[i][0],cnum*=num1[i][0],cnum%=mod;
    ans=cans,num=cnum;
    cans-=bes1[a[1]][0],cnum*=po(num1[a[1]][0]),cnum%=mod,ind[a[1]]++;
    cans+=bes2[a[1]][1],cnum*=num2[a[1]][1],cnum%=mod;
    if(cans>ans)ans=cans,num=cnum;
    else if(cans==ans)num+=cnum,num%=mod;
    for(int i=2;i<=n;i++){
        cans-=bes2[a[i-1]][ind[a[i-1]]],cnum*=po(num2[a[i-1]][ind[a[i-1]]]),cnum%=mod;
        cans+=bes1[a[i-1]][ind[a[i-1]]],cnum*=num1[a[i-1]][ind[a[i-1]]],cnum%=mod;
        cans-=bes1[a[i]][ind[a[i]]],cnum*=po(num1[a[i]][ind[a[i]]]),cnum%=mod,ind[a[i]]++;
        cans+=bes2[a[i]][ind[a[i]]],cnum*=num2[a[i]][ind[a[i]]],cnum%=mod;
        if(cans>ans)ans=cans,num=cnum;
        else if(cans==ans)num+=cnum,num%=mod;
    }
    printf("%lld %lld",ans,num);
}