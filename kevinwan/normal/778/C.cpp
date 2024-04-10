#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const ll mod=998244353;
const int mn=3e5+10;
struct nd{
    int c[26];
    int s;
    nd():c{0},s(0){};
};
vector<nd>v;
int nnd(){
    v.push_back(nd());
    return v.size()-1;
}
int n;
vector<int>h;
void add(int x,int t){
    for(int i=0;i<26;i++)if(v[t].c[i]){
        if(!v[x].c[i])v[x].c[i]=nnd(),h.push_back(x);
        add(v[x].c[i],v[t].c[i]);
    }
}
int ga[mn];

void dfs(int x,int dep){
    v[x].s=1;
    int mo=-1;
    for(int i=0;i<26;i++)if(v[x].c[i]){
        dfs(v[x].c[i],dep+1);
        v[x].s+=v[v[x].c[i]].s;
        if(mo==-1||v[v[x].c[i]].s>v[mo].s)mo=v[x].c[i];
    }
    if(mo==-1)return;
    for(int i=0;i<26;i++){
        int y=v[x].c[i];
        if(y&&y!=mo){
            add(mo,y);
        }
    }
    ga[dep]+=v[x].s-(v[mo].s+(int)v.size()-(n+1));
    v.resize(n+1);
    for(int y:h)if(y<=n){
        for(int i=0;i<26;i++)if(v[y].c[i]>n)v[y].c[i]=0;
    }
    h.clear();
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n;
    v.resize(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;
        char c;
        cin>>a>>b>>c,c-='a';
        v[a].c[c]=b;
    }
    dfs(1,0);
    int bes=0;
    for(int i=1;i<=n;i++)if(ga[i]>ga[bes])bes=i;
    printf("%d\n%d",n-ga[bes],bes+1);
}