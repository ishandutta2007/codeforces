#include<bits/stdc++.h>
using namespace std;
mt19937 rng(time(0));
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const ll mod=1e9+7;
const int mn=2e3+10;
int p[mn],s[mn],bs[mn],bp[mn];
vector<pii>ans;
bool vis[mn];
inline int nxt(int i,int n){return ++i==n?0:i;}
inline int pre(int i,int n){return --i==-1?n-1:i;}
void hail(vector<int>v){
    if(v.size()==1)return;
    int sm=0;
    for(int i=1;i<v.size();i++){
        if(v[i]<v[sm])sm=i;
    }
    int pr=pre(sm,v.size());
    for(int i=0;i<v.size();i++){
        if(v[i]<v[pr]&&p[v[i]]>=v[pr]){
            ans.push_back({v[i],v[pr]});
            swap(p[v[i]],p[v[pr]]);
            vector<int>v1,v2;
            v1.push_back(v[i]);
            for(int j=p[v[i]];j!=v[i];j=p[j])v1.push_back(j);
            v2.push_back(v[pr]);
            for(int j=p[v[pr]];j!=v[pr];j=p[j])v2.push_back(j);
            hail(v1),hail(v2);
            return;
        }
    }
}
int main(){
    int n;
    //freopen("//Users//kevinwan//Desktop//wtf.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",p+i);
    for(int i=1;i<=n;i++)scanf("%d",s+i),bs[s[i]]=i;
    for(int i=1;i<=n;i++)p[i]=bs[p[i]];
    for(int i=1;i<=n;i++)bp[p[i]]=i;
    for(int i=1;i<=n;i++)if(!vis[i]){
        vector<int>v;
        v.push_back(i);
        for(int j=p[i];j!=i;j=p[j])v.push_back(j);
        hail(v);
        for(int x:v)vis[x]=1;
        v.clear();
    }
    int sc=0;
    for(pii p:ans)sc+=abs(p.first-p.second);
    printf("%d\n%d\n",sc,ans.size());
    for(pii p:ans)printf("%d %d\n",p.first,p.second);
}