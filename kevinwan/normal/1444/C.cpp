#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
typedef vector<int> vi;
typedef vector<ll> vl;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const ll inf=0x3f3f3f3f3f3f3f3f;
const int mn=5e5+10;
const ll mod=998244353;

int p[mn],s[mn],dt[mn];
int col[mn];
bool ded[mn];
int f(int x){
    if(p[x]==x)return x;
    else return f(p[x]);
}
int gt(int x){
    if(p[x]==x)return 0;
    else return gt(p[x])^dt[x];
}
vector<pii>mv;
bool mer(int a,int b){
    int aa=f(a),bb=f(b);
    if(aa==bb){
        mv.push_back({0,0});
        return gt(a)==gt(b);
    }
    else{
        if(s[aa]<s[bb])swap(aa,bb);
        s[aa]+=s[bb];
        p[bb]=aa;
        dt[bb]=gt(b)^gt(a)^1;
        mv.push_back({aa,bb});
        return 0;
    }
}
void vesh(){
    pii pp=mv.back();
    mv.pop_back();
    if(pp.first==0)return;
    p[pp.second]=pp.second;
    s[pp.first]-=s[pp.second];
    dt[pp.second]=0;
}
int main(){
#ifdef LOCAL
    freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
freopen("error.txt","w",stderr);
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,m,k;
    cin>>n>>m>>k;
    iota(p,p+mn,0);
    for(int i=1;i<=n;i++){
        cin>>col[i];
    }
    vector<pii>ed;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        if(col[a]==col[b]){
            ded[col[a]]|=mer(a,b);
            continue;
        }
        if(col[a]>col[b])swap(a,b);
        ed.push_back({a,b});
    }

    ll numg=0;
    for(int i=1;i<=k;i++)numg+=!ded[i];
    numg=numg*(numg-1)/2;
    sort(ed.begin(),ed.end(),[](pii a,pii b){
        if(col[a.first]!=col[b.first])return col[a.first]<col[b.first];
        return col[a.second]<col[b.second];
    });
    mv.clear();
    pii lg={-1,-1};
    bool done=0;
    for(pii p:ed){
        pii ng={col[p.first],col[p.second]};
        if(ded[ng.first]||ded[ng.second])continue;
        if(lg!=ng){
            while(mv.size())vesh();
            done=0;
            lg=ng;
        }
        if(done)continue;
        done|=mer(p.first,p.second);
        if(done)numg--;
    }
    printf("%lld\n",numg);
}