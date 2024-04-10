#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const int mn=2e5+10;
int p[mn],s[mn];
struct ed{int a,b,c,i;bool operator<(const ed&ot)const{return c<ot.c;}};
ed e[mn];
int ans[mn];
stack<pii>pst;
int f(int x){return x==p[x]?x:f(p[x]);}
void mrg(int a,int b){
    a=f(a),b=f(b);
    if(a==b){
        pst.push({0,0});
        return;
    }
    if(s[b]>s[a])swap(a,b);
    s[a]+=s[b];
    p[b]=a;
    pst.push({a,b});
}
void bac(){
    int a=pst.top().first,b=pst.top().second;
    pst.pop();
    if(!a)return;
    p[b]=b;
    s[a]-=s[b];
}
vector<ed>v;
void solve(int l,int r){
    int mid=(l+r)>>1;
    if(l==r){
        if(f(v[l].a)!=f(v[l].b))ans[v[l].i]=2;
    }
    else{
        for(int i=mid+1;i<=r;i++)mrg(v[i].a,v[i].b);
        solve(l,mid);
        for(int i=mid+1;i<=r;i++)bac();
        for(int i=l;i<=mid;i++)mrg(v[i].a,v[i].b);
        solve(mid+1,r);
        for(int i=l;i<=mid;i++)bac();
    }
}
void solve(){
    for(ed e:v){
        if(f(e.a)!=f(e.b))ans[e.i]=1;
    }
    solve(0,v.size()-1);
    for(int i=0;i<v.size();i++)mrg(v[i].a,v[i].b);
    v.clear();
}
int main(){
    int n,m,a,b;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c),e[i].i=i;
    for(int i=1;i<=n;i++)p[i]=i,s[i]=1;
    sort(e,e+m);
    for(int i=0;i<m;i++){
        if(i&&e[i].c!=e[i-1].c)solve();
        v.push_back(e[i]);
    }
    solve();
    for(int i=0;i<m;i++){
        if(ans[i]==0)printf("none\n");
        else if(ans[i]==1)printf("at least one\n");
        else printf("any\n");
    }
}