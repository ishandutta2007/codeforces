#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(423978);
typedef long long ll;
typedef pair<ll,ll>pll;
const ll mod=998244353;
const int mn=2e5+10;
int a[mn];
struct bit{
    int bit[mn];
    void up(int a,int b){for(;a<mn;a+=a&-a)bit[a]+=b;}
    int qu(int a){int b=0;for(;a;a-=a&-a)b+=bit[a];return b;}
};
int main(){
    int n;
    ll k;
    scanf("%d%lld",&n,&k);
    vector<int>nums;
    map<int,int>comp;
    nums.push_back(0);
    for(int i=1;i<=n;i++)scanf("%d",a+i),nums.push_back(a[i]);
    sort(nums.begin(),nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    for(int i=0;i<nums.size();i++)comp[nums[i]]=i;
    for(int i=1;i<=n;i++)a[i]=comp[a[i]];
    bit lb=bit(),rb=bit();
    ll ans=0,pr=0;
    for(int i=n;i>=1;i--)ans+=rb.qu(a[i]-1),rb.up(a[i],1);
    for(int i=1,j=1;i<=n;i++){
        ans+=rb.qu(a[i]-1)+lb.qu(mn-1)-lb.qu(a[i]);
        lb.up(a[i],1);
        while(i==j||(j<=n&&ans>k)){
            rb.up(a[j],-1);
            ans-=rb.qu(a[j]-1)+lb.qu(mn-1)-lb.qu(a[j]);
            j++;
        }
        pr+=n+1-j;
    }
    printf("%lld",pr);
}