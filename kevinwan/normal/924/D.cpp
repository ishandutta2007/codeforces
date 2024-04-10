#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
typedef long long ll;
typedef long double ld;
typedef pair<int,int>pii;
typedef pair<int,ll>pil;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;
typedef pair<ld,ld>pld;
const int mn=3e5+10;
const ll mod=1e9+7;
int bit[mn];
void up(int a,int b){for(a+=5;a<mn;a+=a&-a)bit[a]+=b;}
int qu(int a){int b=0;for(a+=5;a;a-=a&-a)b+=bit[a];return b;}
int gcd(int a,int b){
    while(b)a%=b,swap(a,b);
    return a;
}
pii hail(int a,int b){
    int g=gcd(a,b);
    return {a/g,b/g};
}
int main(){
    int n,w;
    scanf("%d%d",&n,&w);
    vector<pair<pii,pii>>v;
    vector<pii>nums,u(n);
    for(int i=0;i<n;i++){
        int x,s;
        scanf("%d%d",&x,&s);
        v.push_back({hail(abs(x),abs(-s-w)),hail(abs(x),abs(-s+w))});
        nums.push_back(v.back().first);
        nums.push_back(v.back().second);
    }

    sort(nums.begin(),nums.end(),[](pii a,pii b){return 1LL*a.first*b.second<1LL*b.first*a.second;});
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    map<pii,int>m;
    for(int i=0;i<nums.size();i++)m[nums[i]]=i;
    for(int i=0;i<n;i++)u[i]={m[v[i].first],m[v[i].second]};
    sort(u.begin(),u.end(),[](pii a,pii b){if(a.first!=b.first)return a.first<b.first;return a.second>b.second;});
    ll ans=0,ex=0;
    for(pii p:u){
        ans+=(ex++)-qu(p.second-1);
        up(p.second,1);
    }
    printf("%lld",ans);
}