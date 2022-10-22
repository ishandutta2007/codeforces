#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
int m,n,tot[510000],cnt;
pii num[510000]; bool vis[510000];
vector<int> vec[510000];
priority_queue<ppi,vector<ppi>,greater<ppi> > que;
string s,x,y;
map<string,int> mp;
void build(){
    for (int i=1;i<=cnt;i++) que.push(ppi(num[i],i));
    while (!que.empty()){
        int u=que.top().second; que.pop();
        if (vis[u]) continue; vis[u]=true;
        for (int v:vec[u])
            if (num[v]>num[u]){
                num[v]=num[u];
                que.push(ppi(num[v],v));
            }
    }
}
int calcR(string &s){ return count(s.begin(),s.end(),'r');}
int calc(string &s){
    transform(s.begin(),s.end(),s.begin(),::tolower);
    if (mp.find(s)==mp.end()){
        mp[s]=++cnt;
        num[cnt]=pii(calcR(s),s.length());
    }
    return mp[s];
}
int main(){
    cin>>m;
    for (int i=1;i<=m;i++){
        cin>>s;
        tot[calc(s)]++;
    }
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>x>>y;
        vec[calc(y)].push_back(calc(x));
    }
    build(); ll ans=0,len=0;
    for (int i=1;i<=cnt;i++) ans+=1ll*num[i].first*tot[i],len+=1ll*num[i].second*tot[i];
    cout<<ans<<' '<<len<<endl;
    return 0;
}