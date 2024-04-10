//Oshvleiki Svlaiyoska Ranasku sachi
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=2e5+10,mv=500;
int n,m;
vector<int>p,np,val;
int cont(int x){
    if(x==0)return val.back()-1;
    int ans=0;
    for(int i=0;i<p.size();i++){
        int num=0;
        while(x%p[i]==0){
            x/=p[i];
            num++;
        }
        ans+=min(num,np[i])*val[i];
    }
    return ans;
}
bool in[mn];
vector<int> bin[mv];
int dp[mv],bac[mv];
ll inv(ll a,ll m,ll e){
    ll ans=1;
    for(ll b=e-1;b;b>>=1,a*=a,a%=m)if(b&1)ans*=a,ans%=m;
    return ans;
}
int tot[mv];
int idk(int x){
    int ans=x;
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            ans/=i,ans*=i-1;
            while(x%i==0)x/=i;
        }
    }
    if(x!=1)ans/=x,ans*=x-1;
    return ans;
}
int num[mv];
int main(){
    //freopen("hail.in","r",stdin);
    scanf("%d%d",&n,&m);
    memset(in,1,sizeof(in));
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        in[x]=0;
    }
    int mm=m;
    for(int i=2;i*i<=mm;i++){
        if(mm%i==0){
            p.push_back(i);
            np.push_back(0);
            while(mm%i==0){
                mm/=i;
                np.back()++;
            }
        }
    }
    if(mm!=1)p.push_back(mm),np.push_back(1);
    val.resize(p.size()+1);
    val[0]=1;
    for(int i=1;i<=p.size();i++)val[i]=val[i-1]*(np[i-1]+1);
    for(int i=1;i<=m;i++){
        int x=cont(i);
        if(num[x]==0)num[x]=i,tot[x]=idk(i);
    }
    for(int i=0;i<m;i++)if(in[i])bin[cont(i)].push_back(i);
    bac[val.back()-1]=val.back();
    memset(dp,0xc0,sizeof(dp));
    dp[val.back()-1]=0;
    for(int i=val.back()-1;i>=0;i--){
        for(int j=0;j<p.size();j++){
            if((i%val[j+1])/val[j]==np[j])continue;
            if(dp[i+val[j]]>dp[i])dp[i]=dp[i+val[j]],bac[i]=i+val[j];
        }
        dp[i]+=bin[i].size();
    }
    vector<int>v,ans;
    int lst=1;
    for(int i=0;i<val.back();i=bac[i]){
        for(int j:bin[i]){
            v.push_back(j);
        }
    }
    ans.resize(v.size());
    ans[0]=v[0];
    for(int i=1;i<v.size();i++){
        int b=cont(v[i]),a=cont(v[i-1]);
        int ex=num[b-a];
        int s=v[i-1]/num[a],e=v[i]/num[b];
        int ref=val.back()-1-b;
        ans[i]=inv(s,num[ref],tot[ref])*e%num[ref]*ex;
    }
    printf("%d\n",ans.size());
    for(int x:ans)printf("%d ",x);
}