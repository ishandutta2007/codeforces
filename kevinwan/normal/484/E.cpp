#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int mn=1e5+10;
struct hail{
    ll n=0,l=0,r=0,lr=0;
    hail(ll a,ll b,ll c,ll d):n(a),l(b),r(c),lr(d){};
    hail(){n=l=r=lr=0;};
};
hail add(const hail&a,const hail&b){
    return {
        max(a.r+b.l,max(a.n,b.n)),
        max(a.l,a.lr+b.l),
        max(b.r,a.r+b.lr),
        a.lr+b.lr
    };
}
hail seg[mn*2];
void up(int a,ll b){
    seg[a+=mn]={b,b,b,b};
    for(a>>=1;a;a>>=1)seg[a]=add(seg[a*2],seg[a*2+1]);
}
ll qu(int a,int b){
    hail l,r;
    l=r=hail();
    for(a+=mn,b+=mn;a<=b;a>>=1,b>>=1){
        if(a&1)l=add(l,seg[a++]);
        if(!(b&1))r=add(seg[b--],r);
    }
    return add(l,r).n;
}
int h[mn];
int cur[mn];
int l[mn],r[mn],w[mn];
vector<int>tst[mn],u[mn];
int main(){
    int n;
    vector<int>nums;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",h+i);
        nums.push_back(h[i]);
    }
    sort(nums.begin(),nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    map<int,int>comp;
    for(int i=0;i<nums.size();i++)comp[nums[i]]=i;
    for(int i=1;i<=n;i++)h[i]=comp[h[i]],u[h[i]].push_back(i);
    int q;
    scanf("%d",&q);
    for(int i=1;i<=q;i++)scanf("%d%d%d",l+i,r+i,w+i);
    for(int i=1<<16;i;i>>=1){
        for(int j=0;j<mn*2;j++)seg[j]={-0x3f3f3f3f,-0x3f3f3f3f,-0x3f3f3f3f,-0x3f3f3f3f};
        for(int j=0;j<nums.size();j++)tst[j].clear();
        for(int j=1;j<=q;j++){
            if(cur[j]+i<nums.size())tst[cur[j]+i].push_back(j);
        }
        for(int j=nums.size()-1;j>=0;j--){
            for(int k:u[j])up(k,1);
            for(int k:tst[j]){
                if(qu(l[k],r[k])>=w[k])cur[k]+=i;
            }
        }
    }
    for(int i=1;i<=q;i++)printf("%d\n",nums[cur[i]]);
}