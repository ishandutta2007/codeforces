#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
const int mn=1e6+10;
const ll mod=1e9+7;
vector<int>p[mn],in[mn];
int ind[mn];
int a[mn];
ll po(ll a,ll b=mod-2){
    ll ans=1;
    for(;b;b>>=1,a*=a,a%=mod)if(b&1)ans*=a,ans%=mod;
    return ans;
}
ll bit[mn],ans[mn];
void upd(int a,ll b){for(;a<mn;a+=a&-a)bit[a]*=b,bit[a]%=mod;}
ll qu(int a){ll b=1;for(;a;a-=a&-a)b*=bit[a],b%=mod;return b;}
struct query{int l,r,i;};
int main(){
    int n;
    scanf("%d",&n);
    for(int i=2;i<mn;i++)if(!p[i].size()){
        for(int j=i;j<mn;j+=i)p[j].push_back(i);
    }
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=n;i++)for(int j:p[a[i]])in[j].push_back(i);
    fill(bit,bit+mn,1);
    for(int i=1;i<=n;i++)upd(i,a[i]);
    for(int i=2;i<mn;i++)if(in[i].size())upd(in[i][0],(i-1)*po(i)%mod);
    vector<query>que;
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        que.push_back({l,r,i});
    }
    sort(que.begin(),que.end(),[](query a,query b){return a.l<b.l;});
    int cl=1;
    for(query q:que){
        while(cl<q.l){
            upd(cl,po(a[cl]));
            for(int i:p[a[cl]]){
                upd(cl,po(i-1)*i%mod);
                ind[i]++;
                if(ind[i]<in[i].size())upd(in[i][ind[i]],(i-1)*po(i)%mod);
            }
            cl++;
        }
        ans[q.i]=qu(q.r);
    }
    for(int i=0;i<m;i++)printf("%lld\n",ans[i]);
}