#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef __int128 lll;
const ll mod=998244353;
const int mn=3e5+10;
string s;
string t[mn];
ll ans=0;
struct nd{
    map<char,int>c;
    int suf;
    ll v;
    nd():suf(0),v(0){};
};
vector<nd>v={nd()};
int nnd(){
    v.push_back(nd());
    return v.size()-1;
}
int r1,r2;
void add(int x,string&s,int i){
    if(i==s.size()){
        v[x].v++;
        return;
    }
    if(!v[x].c.count(s[i]))v[x].c[s[i]]=nnd();
    add(v[x].c[s[i]],s,i+1);
}
void init(int r){
    queue<int>q;
    q.push(r);
    v[r].suf=r;
    while(q.size()){
        int x=q.front();
        q.pop();
        for(pii p:v[x].c)if(!v[p.second].suf){
            int y=p.second;
            char c=p.first;
            q.push(y);
            if(x==r){
                v[y].suf=r;
                continue;
            }
            int t=v[x].suf;
            for(;t!=r&&!v[t].c.count(c);t=v[t].suf);
            if(v[t].c.count(c))v[y].suf=v[t].c[c];
            else v[y].suf=r;
            v[y].v+=v[v[y].suf].v;
        }
    }
}
int nxt(int x,char c){
    int t=x;
    for(;v[t].suf!=t&&!v[t].c.count(c);t=v[t].suf);
    if(v[t].c.count(c))return v[t].c[c];
    else return t;
}
ll aa[mn],bb[mn];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin>>s;
    n=s.size();
    int m;
    cin>>m;
    r1=nnd(),r2=nnd();
    for(int i=0;i<m;i++){
        cin>>t[i],add(r1,t[i],0);
        reverse(t[i].begin(),t[i].end());
        add(r2,t[i],0);
    }
    init(r1);
    init(r2);
    int cur=r1;
    for(int i=0;i<n;i++){
        cur=nxt(cur,s[i]);
        aa[i]=v[cur].v;
    }
    cur=r2;
    for(int i=n-1;i>=0;i--){
        cur=nxt(cur,s[i]);
        bb[i]=v[cur].v;
    }
    for(int i=0;i+1<n;i++)ans+=aa[i]*bb[i+1];
    printf("%lld",ans);
}