#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int mn=2e5+10;
pii p[mn];
vector<pii> u;
set<pii>s;
int anc[mn][18];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%d%d",&p[i].first,&p[i].second);
    sort(p,p+n);
    for(int i=0;i<n;i++)if(u.empty()||u[u.size()-1].second<p[i].second)u.push_back(p[i]);
    n=u.size();
    for(int i=0;i<n;i++)s.insert({u[i].first,i});
    for(int i=0;i<n;i++)anc[i][0]=(--s.upper_bound({u[i].second,0x3f3f3f3f}))->second;
    for(int i=1;i<18;i++)for(int j=0;j<n;j++)anc[j][i]=anc[anc[j][i-1]][i-1];
    while(m--){
        int l,r;
        scanf("%d%d",&l,&r);
        if(l<s.begin()->first){
            printf("-1\n");
            continue;
        }
        int cur=(--s.upper_bound({l,0x3f3f3f3f}))->second;
        int ans=1;
        for(int i=17;i>=0;i--){
            if(u[anc[cur][i]].second<r)ans+=1<<i,cur=anc[cur][i];
        }
        if(u[cur].second<r)ans++;
        if(ans>n)printf("-1\n");
        else printf("%d\n",ans);
    }
}