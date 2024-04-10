#include<bits/stdc++.h>
#define mid (l+r>>1)
using namespace std;
const int mn=1e6+10;
int l[mn],r[mn],k[mn],val[mn];
int seg[mn*3],v[mn*3],laz[mn*3];
void init(int x,int l,int r){
    if(l==r)seg[x]=v[x]=val[l];
    else init(x*2,l,mid),init(x*2+1,mid+1,r),seg[x]=v[x]=v[x*2]+v[x*2+1];
}
void prop(int x){
    if(laz[x]==-1)return;
    if(x*2<mn*3)laz[x*2]=laz[x*2+1]=laz[x];
    if(laz[x])seg[x]=v[x];
    else seg[x]=0;
    laz[x]=-1;
}
void eval(int x){
    prop(x*2),prop(x*2+1);
    seg[x]=seg[x*2]+seg[x*2+1];
}
void upd(int x,int l,int r,int a,int b,int c){
    prop(x);
    if(l==a&&r==b)laz[x]=c;
    else{
        if(b<=mid)upd(x*2,l,mid,a,b,c);
        else if(a>mid)upd(x*2+1,mid+1,r,a,b,c);
        else upd(x*2,l,mid,a,mid,c),upd(x*2+1,mid+1,r,mid+1,b,c);
        eval(x);
    }
}
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    vector<int>nums;
    map<int,int>comp;
    for(int i=0;i<q;i++)scanf("%d%d%d",l+i,r+i,k+i),r[i]++,nums.push_back(l[i]),nums.push_back(r[i]);
    nums.push_back(1),nums.push_back(n+1);
    sort(nums.begin(),nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    for(int i=0;i<nums.size();i++){
        comp[nums[i]]=i;
        if(i!=nums.size()-1)val[i]=nums[i+1]-nums[i];
    }
    n=nums.size();
    init(1,0,n-1);
    memset(laz,-1,sizeof(laz));
    for(int i=0;i<q;i++){
        upd(1,0,n-1,comp[l[i]],comp[r[i]]-1,k[i]-1);
        prop(1);
        printf("%d\n",seg[1]);
    }
}