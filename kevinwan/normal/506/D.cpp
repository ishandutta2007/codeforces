#include<bits/stdc++.h>
using namespace std;
mt19937 rng(time(0));
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const ll mod=1e9+7;
const int mn=2e5+10;
unordered_map<int,int>m[mn];
map<pii,int>hail;
map<int,int>rn[mn];
int p[mn],r[mn];
int f(int x){
    return x==p[x]?x:(p[x]=f(p[x]));
}
void mrg(int a,int b){
    a=f(a),b=f(b);
    if(r[a]<r[b])swap(a,b);
    if(r[a]==r[b])r[a]++;
    p[b]=a;
}
int ct;
int main(){
    int n,k;
    iota(p,p+mn,0);
    scanf("%d%d",&n,&k);
    for(int i=0;i<k;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int c1=0,c2=0;
        if(rn[a].count(c))c1=rn[a][c];
        if(rn[b].count(c))c2=rn[b][c];
        rn[a][c]=rn[b][c]=++ct;
        if(c1)mrg(c1,ct);
        if(c2)mrg(c2,ct);
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int a,b;
        scanf("%d%d",&a,&b);
        if(a>b)swap(a,b);
        if(rn[a].size()>rn[b].size())swap(a,b);
        auto it=hail.find({a,b});
        if(it!=hail.end()){
            printf("%d\n",it->second);
            continue;
        }
        int ans=0;
        for(pii c:rn[a]){
            if(rn[b].count(c.first)&&f(rn[b][c.first])==f(c.second))ans++;
        }
        printf("%d\n",hail[{a,b}]=ans);
    }
}