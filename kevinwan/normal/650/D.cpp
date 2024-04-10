#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<int,ll>pil;
typedef pair<ll,ll>pll;
const int mn=4e5+10;
const ll mod=1e9+rng()%((ll)1e9);
int v[mn],a[mn],b[mn];
inline pil vesh(pil a,pil b){
    if(a.first!=b.first)return a.first>b.first?a:b;
    return {a.first,(a.second+b.second)%mod};
}
pil bit[mn*2];
void up(int a,pil b){for(;a<mn*2;a+=a&-a)bit[a]=vesh(bit[a],b);}
pil qu(int a){pil b={0,0};for(;a;a-=a&-a)b=vesh(b,bit[a]);return b;}
int u[mn],d[mn];
ll nu[mn],nd[mn],vu[mn],vd[mn];
vector<int>pro[mn];
bool gud[mn];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    vector<int>nums={-1,0};
    for(int i=0;i<n;i++)scanf("%d",v+i),nums.push_back(v[i]);
    for(int i=0;i<m;i++)scanf("%d%d",a+i,b+i),a[i]--,nums.push_back(b[i]);
    sort(nums.begin(),nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    map<int,int>comp;
    for(int i=0;i<nums.size();i++)comp[nums[i]]=i;
    for(int i=0;i<m;i++)pro[a[i]].push_back(i),b[i]=comp[b[i]];
    up(1,{0,1});
    for(int i=0;i<n;i++)v[i]=comp[v[i]];
    for(int i=0;i<n;i++){
        pil p=qu(v[i]-1);
        for(int j:pro[i])u[j]=max(u[j],qu(b[j]-1).first);
        up(v[i],{p.first+1,p.second});
        nu[i]=p.second;
        vu[i]=p.first;
    }
    memset(bit,0,sizeof(bit));
    up(1,{0,1});
    for(int i=0;i<n;i++)v[i]=nums.size()+1-v[i];
    for(int i=0;i<m;i++)b[i]=nums.size()+1-b[i];
    for(int i=n-1;i>=0;i--){
        pil p=qu(v[i]-1);
        for(int j:pro[i])d[j]=max(d[j],qu(b[j]-1).first);
        up(v[i],{p.first+1,p.second});
        nd[i]=p.second;
        vd[i]=p.first;
    }
    pil en=qu(mn*2-1);
    for(int i=0;i<n;i++)if(vu[i]+vd[i]+1!=en.first||nu[i]*nd[i]%mod!=en.second)gud[i]=1;
    for(int i=0;i<m;i++){
        int ans=max(en.first-(!gud[a[i]]),u[i]+d[i]+1);
        printf("%d\n",ans);
    }
}