#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=2e5+10;
int a[mn],b[mn];
map<int,int>c;
int p[mn],bit[mn];
void upd(int a,int b){for(a++;a<mn;a+=a&-a)bit[a]+=b;}
int que(int a){int b=0;for(a++;a;a-=a&-a)b+=bit[a];return b;}
int main(){
    int n,m=1e9;
    scanf("%d",&n);
    vector<int>nums;
    for(int i=0;i<n;i++)scanf("%d%d",a+i,b+i),nums.push_back(a[i]),nums.push_back(b[i]);
    sort(nums.begin(),nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    for(int i=0;i<nums.size();i++)c[nums[i]]=i;
    for(int i=0;i<n;i++)a[i]=c[a[i]],b[i]=c[b[i]];
    ll ans=0;
    iota(p,p+nums.size(),0);
    for(int i=0;i<n;i++)swap(p[a[i]],p[b[i]]);
    for(int i=0;i<nums.size();i++){
        if(p[i]<i)ans+=nums[i]-nums[p[i]]-(i-p[i]);
        else ans+=nums[p[i]]-nums[i]-(p[i]-i);
    }
    for(int i=nums.size()-1;i>=0;i--){
        ans+=que(p[i]);
        upd(p[i],1);
    }
    printf("%lld",ans);
}