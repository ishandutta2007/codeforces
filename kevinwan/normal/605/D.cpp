#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef pair<int,int>pii;
const int mn=2e5+10;
const ll mod=1e9+7;
struct card{int a,b,c,d;bool operator<(const card&o)const{return b<o.b;}};
card cs[mn];
bool vis[mn];
int bac[mn];
queue<int>q;
struct comp{bool operator()(const int&a,const int&b)const{return cs[a].b<cs[b].b;}};
multiset<int,comp>seg[mn*2];
void upd(int a,int i){
    for(a+=mn;a;a>>=1)seg[a].insert(i);
}
int v;
void hail(int x,int b){
    while(seg[x].size()&&cs[*seg[x].begin()].b<=b){
        int t=*seg[x].begin();
        seg[x].erase(seg[x].begin());
        if(!vis[t])vis[t]=1,q.push(t),bac[t]=v;
    }
}
void qu(int l,int r,int b){
    for(l+=mn,r+=mn;l<=r;l++,r--,l>>=1,r>>=1){
        if(l&1)hail(l,b);
        if(!(r&1))hail(r,b);
    }
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin>>n;
    vector<int>nums;
    for(int i=0;i<n;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        cs[i]={a,b,c,d};
        nums.push_back(a);
        nums.push_back(c);
    }
    nums.push_back(0);
    sort(nums.begin(),nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    for(int i=0;i<n;i++){
        cs[i].a=lower_bound(nums.begin(),nums.end(),cs[i].a)-nums.begin();
        cs[i].c=lower_bound(nums.begin(),nums.end(),cs[i].c)-nums.begin();
    }
    for(int i=0;i<n;i++)upd(cs[i].a,i);
    memset(bac,-1,sizeof(bac));
    v=-1;
    qu(0,0,0);
    while(q.size()){
        int x=q.front();
        v=x;
        q.pop();
        qu(0,cs[x].c,cs[x].d);
    }
    if(!vis[n-1])printf("-1");
    else{
        vector<int>v;
        for(int i=n-1;i>=0;i=bac[i])v.push_back(i);
        reverse(v.begin(),v.end());
        printf("%d\n",v.size());
        for(int x:v)printf("%d ",x+1);
    }
}