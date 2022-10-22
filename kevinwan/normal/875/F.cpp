#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const ll mod=1e9+7;
const int mn=5e5+10;
const int siz=2000;
int p[mn],r[mn];
int f(int x){return p[x]==x?x:(p[x]=f(p[x]));}
struct edge{
    int a,b,c;
};
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    vector<edge>v;
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        v.push_back({a,b,c});
    }
    ll ans=0;
    iota(p,p+mn,0);
    sort(v.begin(),v.end(),[](edge a,edge b){return a.c>b.c;});
    for(edge e:v){
        int a=f(e.a),b=f(e.b);
        if(r[a]&&r[b])continue;
        int nr=r[a]||r[b]||(a==b);
        p[a]=b;
        r[b]=nr;
        ans+=e.c;
    }
    printf("%lld\n",ans);
}