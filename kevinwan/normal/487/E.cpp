#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef __int128 lll;
const ll mod=1e9+9;
const int mn=5e5+10;
int n,m,q;
vector<int>g[mn],gg[mn];
bool ap[mn],vis[mn],ins[mn];
int dep[mn],lo[mn],ct;
int seg[mn*2];
void upd(int a,int b){
    for(seg[a+=mn]=b,a>>=1;a;a>>=1)seg[a]=min(seg[a*2],seg[a*2+1]);
}
int qu(int a,int b){
    int ans=INT_MAX;
    for(a+=mn,b+=mn;a<=b;a>>=1,b>>=1){
        if(a&1)ans=min(ans,seg[a++]);
        if(!(b&1))ans=min(ans,seg[b--]);
    }
    return ans;
}
int bcc[mn];
stack<pii>sta;
vector<vector<pii>>idk;
void dfs1(int x,int p){
    vis[x]=ins[x]=1;
    dep[x]=lo[x]=dep[p]+1;
    int num=0;
    for(int y:g[x])if(y!=p&&(!vis[y]||ins[y])){
        sta.push({x,y});
        if(!vis[y]){
            num++;
            dfs1(y,x);
            lo[x]=min(lo[x],lo[y]);
            if(lo[y]>=dep[x]){
                ap[x]=1;
                bcc[x]=x;
                idk.push_back({});
                while(sta.top()!=make_pair(x,y))idk.back().push_back(sta.top()),sta.pop();
                idk.back().push_back(sta.top()),sta.pop();
            }
        }
        else lo[x]=min(lo[x],dep[y]);
    }
    if(!p)ap[x]=(num>=2);
    ins[x]=0;
}
int s[mn],par[mn],hd[mn];
void dfs3(int x,int p){
    par[x]=p;
    s[x]=1;
    for(int y:gg[x])if(y!=p){
        dfs3(y,x);
        s[x]+=s[y];
    }
}
int o[mn];
void dfs4(int x,int p,int h){
    o[x]=++ct;
    hd[x]=h;
    for(int y:gg[x])if(y!=p){
        if(s[y]*2>=s[x])dfs4(y,x,h);
    }
    for(int y:gg[x])if(y!=p){
        if(s[y]*2<s[x])dfs4(y,x,y);
    }
}
multiset<int>st[mn];
int v[mn];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)cin>>v[i];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ct=n;
    dfs1(1,0);
    for(vector<pii>&v:idk){
        ct++;
        for(pii p:v){
            int x=p.first;
            if(!ap[x])bcc[x]=ct;
            else if(gg[x].empty()||gg[x].back()!=ct)gg[x].push_back(ct),gg[ct].push_back(x);
            x=p.second;
            if(!ap[x])bcc[x]=ct;
            else if(gg[x].empty()||gg[x].back()!=ct)gg[x].push_back(ct),gg[ct].push_back(x);
        }
    }
    idk.clear();
    int r=ct;
    dfs3(r, 0);
    ct = 0;
    dfs4(r, 0, r);
    memset(seg,0x3f,sizeof(seg));
    v[0]=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        if(bcc[i]==i&&!par[bcc[i]])continue;
        if(bcc[i]==i){
            st[par[bcc[i]]].insert(v[i]);
            upd(o[par[bcc[i]]],*st[par[bcc[i]]].begin());
        }
        else {
            st[bcc[i]].insert(v[i]);
            upd(o[bcc[i]],*st[bcc[i]].begin());
        }
    }
    while(q--){
        string aa;
        int a,b;
        cin>>aa>>a>>b;
        if(aa=="C"){
            if(bcc[a]==a&&!par[bcc[a]])continue;
            if(bcc[a]==a)st[par[bcc[a]]].erase(st[par[bcc[a]]].find(v[a])),
            v[a]=b,
            st[par[bcc[a]]].insert(v[a]),
            upd(o[par[bcc[a]]],*st[par[bcc[a]]].begin());
            else st[bcc[a]].erase(st[bcc[a]].find(v[a])),
            v[a]=b,
            st[bcc[a]].insert(v[a]),
            upd(o[bcc[a]],*st[bcc[a]].begin());
        }
        else{
            if(a==b){
                printf("%d\n",v[a]);
                continue;
            }
            a=bcc[a],b=bcc[b];
            int ans=0x3f3f3f3f;
            while(hd[a]!=hd[b]){
                if(s[hd[a]]<s[hd[b]]){
                    ans=min(ans,qu(o[hd[a]],o[a]));
                    a=par[hd[a]];
                }
                else{
                    ans=min(ans,qu(o[hd[b]],o[b]));
                    b=par[hd[b]];
                }
            }
            if(s[a]<s[b])swap(a,b);
            ans=min(ans,qu(o[a],o[b]));
            if(a>n)ans=min(ans,v[par[a]]);
            else ans=min(ans,v[a]);
            printf("%d\n",ans);
        }
    }
}