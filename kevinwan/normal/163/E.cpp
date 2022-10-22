#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef __int128 lll;
const ll mod=998244353;
const int mn=1e6+10;
struct nd{
    map<char,int>c;
    int suf;
    nd():suf(0){};
};
vector<nd>v={nd()};
int nnd(){
    v.push_back(nd());
    return v.size()-1;
}
int add(int x,string&s,int i){
    if(i==s.size())return x;
    if(!v[x].c.count(s[i]))v[x].c[s[i]]=nnd();
    return add(v[x].c[s[i]],s,i+1);
}
vector<vector<int>>g;
void init(int r){
    v[r].suf=r;
    queue<int>q;
    q.push(r);
    while(q.size()){
        int x=q.front();
        q.pop();
        for(pii p:v[x].c)if(!v[p.second].suf){
            int y=p.second;
            char c=p.first;
            q.push(y);
            if(x==r){
                v[y].suf=r;
                g[r].push_back(y);
                continue;
            }
            int t=v[x].suf;
            for(;t!=r&&!v[t].c.count(c);t=v[t].suf);
            if(v[t].c.count(c))v[y].suf=v[t].c[c];
            else v[y].suf=t;
            g[v[y].suf].push_back(y);
        }
    }
}
int nxt(int x,char c){
    for(;v[x].suf!=x&&!v[x].c.count(c);x=v[x].suf);
    if(v[x].c.count(c))return v[x].c[c];
    return x;
}
int pos[mn];
int o[mn],s[mn],ct;
void dfs(int x){
    s[x]=1;
    o[x]=++ct;
    for(int y:g[x]){
        dfs(y);
        s[x]+=s[y];
    }
}
int bit[mn];
void up(int a,int b){for(;a<mn;a+=a&-a)bit[a]+=b;}
int qu(int a){int b=0;for(;a;a-=a&-a)b+=bit[a];return b;}
bool in[mn];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,k;
    cin>>n>>k;
    int r=nnd();
    for(int i=1;i<=k;i++){
        string s;
        cin>>s;
        pos[i]=add(r,s,0);
    }
    g.resize(v.size());
    init(r);
    dfs(r);
    for(int i=1;i<=k;i++)up(o[pos[i]],1),up(o[pos[i]]+s[pos[i]],-1);
    memset(in,1,sizeof(in));
    while(n--){
        char c;
        cin>>c;
        if(c=='?'){
            string s;
            cin>>s;
            int t=r;
            ll ans=0;
            for(char c:s){
                t=nxt(t,c);
                ans+=qu(o[t]);
            }
            printf("%lld\n",ans);
        }
        else if(c=='+'){
            int x;
            cin>>x;
            if(in[x])continue;
            in[x]=1;
            up(o[pos[x]],1),up(o[pos[x]]+s[pos[x]],-1);
        }
        else{
            int x;
            cin>>x;
            if(!in[x])continue;
            in[x]=0;
            up(o[pos[x]],-1),up(o[pos[x]]+s[pos[x]],1);
        }
    }
}