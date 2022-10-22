#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
typedef long long ll;
typedef long double ld;
typedef pair<int,int>pii;
typedef pair<int,ll>pil;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;
typedef pair<ld,ld>pld;
const int mn=3e5+10;
const ll mod=1e9+7;
string s;
int c[mn][26],dep[mn],ct;
priority_queue<int>*pq[mn];
void ad(int x,int i){
    dep[x]=i;
    if(i==s.size()){
        if(!pq[x])pq[x]=new priority_queue<int>();
        pq[x]->push(0x3f3f3f3f);
        return;
    }
    if(!c[x][s[i]-'a'])c[x][s[i]-'a']=++ct;
    ad(c[x][s[i]-'a'],i+1);
}
void dfs(int x){
    int mo=-1;
    if(!pq[x])pq[x]=new priority_queue<int>();
    for(int i=0;i<26;i++)if(c[x][i]){
        dfs(c[x][i]);
        if(mo==-1||pq[c[x][i]]->size()>pq[mo]->size())mo=c[x][i];
    }
    if(mo!=-1){
        while(pq[x]->size()){
            int u=pq[x]->top();
            pq[x]->pop();
            pq[mo]->push(u);
        }
        pq[x]=pq[mo];
    }
    for(int i=0;i<26;i++)if(c[x][i]){
        int y=c[x][i];
        if(y!=mo)while(pq[y]->size()){
            int u=pq[y]->top();
            pq[y]->pop();
            pq[x]->push(u);
        }
    }
    if(dep[x]) {
        pq[x]->pop();
        pq[x]->push(dep[x]);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        cin>>s;
        ad(0,0);
    }
    dfs(0);
    int ans=0;
    while(pq[0]->size()){
        int u=pq[0]->top();
        pq[0]->pop();
        ans+=u;
    }
    printf("%d",ans);
}