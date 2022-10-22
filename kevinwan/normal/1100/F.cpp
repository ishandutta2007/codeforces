#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef __int128 lll;
const ll mod=998244353;
const int mn=5e5+10;
int a[mn];
int seg[mn*2][20];
int add(int bas[20],int x){
    for(int i=19;i>=0;i--){
        if(!x)return 0;
        if((x>>i)&1){
            if(bas[i])x^=bas[i];
            else{
                bas[i]=x;
                return 1;
            }
        }
    }
    return 0;
}
int ans[mn];
struct query{
    int l,r,ind;
};
int dd[mn][20],cum[20];
void hail(int l,int r,vector<query>v){
    if(!v.size())return;
    if(l==r){
        for(query q:v)ans[q.ind]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    vector<query>aa,b,c;
    for(query q:v){
        if(q.r<=mid)aa.push_back(q);
        else if(q.l>mid)b.push_back(q);
        else c.push_back(q);
    }
    hail(l,mid,aa);
    hail(mid+1,r,b);
    if(!c.size())return;
    memset(cum,0,sizeof(cum));
    for(int i=mid;i>=l;i--)add(cum,a[i]),memcpy(dd[i],cum,sizeof(cum));
    memset(cum,0,sizeof(cum));
    for(int i=mid+1;i<=r;i++)add(cum,a[i]),memcpy(dd[i],cum,sizeof(cum));
    for(query q:c){
        memcpy(cum,dd[q.l],sizeof(cum));
        for(int i=0;i<20;i++)if(dd[q.r][i])add(cum,dd[q.r][i]);
        int bes=0;
        for(int i=19;i>=0;i--)if(!((bes>>i)&1))bes^=cum[i];
        ans[q.ind]=bes;
    }
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)for(int j=i+mn;j;j>>=1)add(seg[j],a[i]);
    int q;
    cin>>q;
    vector<query>v;
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        v.push_back({l,r,i});
    }
    hail(1,n,v);
    for(int i=0;i<q;i++)printf("%d\n",ans[i]);
}