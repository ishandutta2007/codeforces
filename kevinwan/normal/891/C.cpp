#include <bits/stdc++.h>
using namespace std;
mt19937 rng(time(0));
typedef long long ll;
typedef pair<int,int>pii;
const int mn=5e5+10;
const ll mod=1e9+7;
int p[mn],s[mn];
int f(int x){return x==p[x]?x:f(p[x]);}
stack<pii>mov;
void mer(int a,int b){
    a=f(a),b=f(b);
    if(a==b){
        mov.push({-1,-1});
        return;
    }
    if(s[a]<s[b])swap(a,b);
    p[b]=a;
    s[a]+=s[b];
    mov.push({a,b});
}
void bac(){
    int a=mov.top().first,b=mov.top().second;
    mov.pop();
    if(a==-1)return;
    p[b]=b;
    s[a]-=s[b];
}
pii ed[mn];
int c[mn];
vector<int>es[mn];
vector<pii>qs[mn];
int ans[mn];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    iota(p,p+mn,0);
    fill(s,s+mn,1);
    for(int i=0;i<m;i++)scanf("%d%d%d",&ed[i].first,&ed[i].second,c+i),es[c[i]].push_back(i);
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        int k;
        scanf("%d",&k);
        for(int j=0;j<k;j++){
            int x;
            scanf("%d",&x);
            x--;
            qs[c[x]].push_back({i,x});
        }
    }
    memset(ans,1,sizeof(ans));
    for(int i=1;i<mn;i++){
        sort(qs[i].begin(),qs[i].end());
        int beg=0;
        if(qs[i].size())
            for(int j=0;j<=qs[i].size();j++){
                if(j==qs[i].size()||qs[i][j].first!=qs[i][beg].first){
                    for(int k=beg;k<j;k++){
                        int a=ed[qs[i][k].second].first,b=ed[qs[i][k].second].second;
                        a=f(a),b=f(b);
                        if(a==b)ans[qs[i][k].first]=0;
                        mer(a,b);
                    }
                    for(int k=beg;k<j;k++)bac();
                    beg=j;
                }
            }
        for(int j:es[i])mer(ed[j].first,ed[j].second);
    }
    for(int i=0;i<q;i++)printf("%s\n",ans[i]?"YES":"NO");
}