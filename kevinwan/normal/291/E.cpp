#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mn=4e5+10;
mt19937 rng(time(0));
const ll m=rng()>>2;
struct ht{
    const static ll p=1e9+7,q=1e9+9;
    ll a,b;
     ht operator+(const ht &ot)const {return {(a+ot.a)%p,(b+ot.b)%q};}
     ht operator-(const ht &ot)const {return {(a-ot.a+p)%p,(b-ot.b+q)%q};}
     ht operator*(const ht &ot)const {return {(a*ot.a)%p,(b*ot.b)%q};}
     bool operator==(const ht &ot)const {return a==ot.a&&b==ot.b;}
     bool operator!=(const ht &ot)const {return a!=ot.a||b!=ot.b;}
    ht(){a=b=0;}
    ht(ll x){a=b=x;}
    ht(ll x,ll y){a=x,b=y;}
};
vector<int> g[mn];
vector<int>v[mn];
ht po[mn],pre[mn],tar;
int dep[mn],vd[mn];
ll ans;
int l;
void dfs(int x){
    vd[dep[x]]=x;
    int anc=dep[x]-l;
    if(anc>=0){
        int p=vd[anc];
        ht val=pre[x]-pre[p]*po[l];
        if(val==tar)ans++;
    }
    for(int i=0;i<g[x].size();i++){
        int y=g[x][i];
        int d=v[x][i];
        pre[y]=pre[x]*m+v[x][i];
        dep[y]=dep[x]+1;
        dfs(y);
    }
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,i,j;
    cin>>n;
    po[0]=1;
    int cur=n+1;
    for(i=2;i<=n;i++){
        int x;
        string s;
        cin>>x>>s;
        if(s.size()==1){
            g[x].push_back(i);
            v[x].push_back(s[0]);
        }
        else{
            g[x].push_back(cur);
            v[x].push_back(s[0]);
            cur++;
            for(j=1;j<s.size()-1;j++){
                g[cur-1].push_back(cur);
                v[cur-1].push_back(s[j]);
                cur++;
            }
            g[cur-1].push_back(i);
            v[cur-1].push_back(s[s.size()-1]);
            cur++;
        }
    }
    for(i=1;i<=cur;i++)po[i]=po[i-1]*m;
    string s;
    cin>>s;
    l=s.size();
    for(char c:s)tar=tar*m+c;
    dfs(1);
    printf("%lld",ans);
}