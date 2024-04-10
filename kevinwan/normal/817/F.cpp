#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(423978);
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll>pll;
const ll mod=1e9+7;
const int mn=2e5+10;
int t[mn];
ll l[mn],r[mn];
vector<ll>nums;
map<ll,ll>comp;
int seg[mn*4],rseg[mn*4];
bool rem[mn*4],ad[mn*4],rev[mn*4];
#define mid ((l+r)>>1)
inline void prop(int x,int l,int r){
    assert((!ad[x])||(!rem[x]));
    if(rev[x])swap(seg[x],rseg[x]);
    if(ad[x])seg[x]=nums.size()-1,rseg[x]=l;
    if(rem[x])seg[x]=l,rseg[x]=nums.size()-1;
    if(l!=r){
        if(rev[x]){
            swap(rem[x*2],ad[x*2]);
            swap(rem[x*2+1],ad[x*2+1]);
            rev[x*2]^=1,rev[x*2+1]^=1;
        }
        if(ad[x]){
            ad[x*2]=ad[x*2+1]=1;
            rem[x*2]=rem[x*2+1]=0;
        }
        if(rem[x]){
            ad[x*2]=ad[x*2+1]=0;
            rem[x*2]=rem[x*2+1]=1;
        }
    }
    rev[x]=ad[x]=rem[x]=0;
}
inline void eval(int x,int l,int r){
    prop(x*2,l,mid),prop(x*2+1,mid+1,r);
    seg[x]=min(seg[x*2],seg[x*2+1]);
    rseg[x]=min(rseg[x*2],rseg[x*2+1]);
}
void upd(int x,int l,int r,int a,int b,int t){
    if(l==a&&r==b){
        if(t==1)ad[x]=1,rem[x]=0;
        else if(t==2)ad[x]=0,rem[x]=1;
        else swap(ad[x],rem[x]),rev[x]^=1;
    }
    else{
        prop(x,l,r);
        if(b<=mid)upd(x*2,l,mid,a,b,t);
        else if(a>mid)upd(x*2+1,mid+1,r,a,b,t);
        else upd(x*2,l,mid,a,mid,t),upd(x*2+1,mid+1,r,mid+1,b,t);
        eval(x,l,r);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d%lld%lld",t+i,l+i,r+i),nums.push_back(l[i]),nums.push_back(r[i]+1);
    nums.push_back(1);
    sort(nums.begin(),nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    for(int i=0;i<nums.size();i++)comp[nums[i]]=i;
    upd(1,0,nums.size()-1,0,nums.size()-1,2);
    for(int i=0;i<n;i++){
        upd(1,0,nums.size()-1,comp[l[i]],comp[r[i]+1]-1,t[i]);
        prop(1,0,nums.size()-1);
        printf("%lld\n",nums[seg[1]],nums[rseg[1]]);
    }
}