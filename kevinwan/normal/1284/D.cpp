
#include<bits/stdc++.h>
using namespace std;
#define mid (l+r>>1)
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
ll mod=1e9+7;
const int mn=2e5+10;
int a[mn];
int sa[mn],ea[mn],sb[mn],eb[mn];
int bit[mn],bit2[mn];
void up(int a,int b){for(;a<mn;a+=a&-a)bit[a]+=b;}
int qu(int a){int b=0;for(;a;a-=a&-a)b+=bit[a];return b;}
void up2(int a,int b){for(;a<mn;a+=a&-a)bit2[a]+=b;}
int qu2(int a){int b=0;for(;a;a-=a&-a)b+=bit2[a];return b;}
void die(){printf("NO");exit(0);}
vector<int>hail[mn];
int main(){
    int n;
    scanf("%d",&n);
    vector<int>nums,nums2;
    for(int i=0;i<n;i++)scanf("%d%d%d%d",sa+i,ea+i,sb+i,eb+i),nums.push_back(sa[i]),nums.push_back(ea[i]),nums2.push_back(sb[i]),nums2.push_back(eb[i]);
    map<int,int>comp,comp2;
    sort(nums.begin(),nums.end()),sort(nums2.begin(),nums2.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    nums2.erase(unique(nums2.begin(),nums2.end()),nums2.end());
    for(int i=0;i<nums.size();i++)comp[nums[i]]=i+1;
    for(int i=0;i<nums2.size();i++)comp2[nums2[i]]=i+1;
    for(int i=0;i<n;i++)sa[i]=comp[sa[i]],ea[i]=comp[ea[i]],sb[i]=comp2[sb[i]],eb[i]=comp2[eb[i]];
    for(int i=0;i<n;i++)a[i]=i;
    sort(a,a+n,[](const int&a,const int&b){return ea[a]<ea[b];});
    for(int i=0;i<n;i++){
        ea[n]=sa[a[i]];
        int lo=lower_bound(a,a+n,n,[](const int&a,const int&b){return ea[a]<ea[b];})-a;
        if(lo)hail[lo-1].push_back(i);
    }
    for(int i=0;i<n;i++){
        up(sb[a[i]],1);
        up(eb[a[i]],-1);
        up2(sb[a[i]],1);
        up2(eb[a[i]],1);
        for(int j:hail[i]){
            if(qu(sb[a[j]]-1)||qu(eb[a[j]])||(qu2(eb[a[j]])-qu2(sb[a[j]]-1)))die();
        }
    }
    for(int i=0;i<n;i++)hail[i].clear();
    swap(sa,sb),swap(ea,eb);
    memset(bit,0,sizeof(bit));
    memset(bit2,0,sizeof(bit2));
    sort(a,a+n,[](const int&a,const int&b){return ea[a]<ea[b];});
    for(int i=0;i<n;i++){
        ea[n]=sa[a[i]];
        int lo=lower_bound(a,a+n,n,[](const int&a,const int&b){return ea[a]<ea[b];})-a;
        if(lo)hail[lo-1].push_back(i);
    }
    for(int i=0;i<n;i++){
        up(sb[a[i]],1);
        up(eb[a[i]],-1);
        up2(sb[a[i]],1);
        up2(eb[a[i]],1);
        for(int j:hail[i]){
            if(qu(sb[a[j]]-1)||qu(eb[a[j]])||(qu2(eb[a[j]])-qu2(sb[a[j]]-1)))die();
        }
    }
    printf("YES");
}