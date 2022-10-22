#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
typedef vector<int> vi;
typedef vector<ll> vl;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const ll inf=0x3f3f3f3f3f3f3f3f;
const int mn=1010;
const ll mod=998244353;
typedef bitset<500010> bs;
bs dp[510];
bool sga[mn],sgb[mn];
int a[mn],b[mn];
bool solve2(int n,int a[mn],bool ans[mn]){
    dp[0]=dp[0].reset();
    dp[0][0]=1;
    for(int i=1;i<=n;i++)dp[i]=dp[i-1]|(dp[i-1]<<a[i-1]);
    int sa=0;
    for(int i=0;i<n;i++)sa+=a[i];
    if(sa&1)return 0;
    if(!dp[n][sa/2])return 0;
    for(int i=n,j=sa/2;i;i--){
        if(dp[i-1][j])ans[i-1]=0;
        else j-=a[i-1],ans[i-1]=1;
    }
    return 1;
}
deque<int>d[2][2];
int solve(){
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    cin>>m;
    for(int i=0;i<m;i++)cin>>b[i];
    if(n!=m){
        printf("No\n");
        return 0;
    }
    if(!solve2(n,a,sga)||!solve2(m,b,sgb)){
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    d[0][0]=d[0][1]=d[1][0]=d[1][1]=deque<int>();
    for(int i=0;i<n;i++)d[0][sga[i]].push_back(a[i]);
    for(int i=0;i<m;i++)d[1][sgb[i]].push_back(b[i]);
    for(int i=0;i<2;i++)for(int j=0;j<2;j++)sort(d[i][j].begin(),d[i][j].end());
    int x=0,y=0;
    bool sw=0;
    if(d[0][0].size()>d[1][0].size())swap(d[0],d[1]),sw=1;
    vector<pii>ans;
    for(int i=0;i<n;i++){
        if(d[0][0].size()){
            ans.push_back({x+=d[0][0].back(),y});
            d[0][0].pop_back();
            ans.push_back({x,y+=d[1][0].front()});
            d[1][0].pop_front();
        }
        else if(d[1][0].size()){
            ans.push_back({x-=d[0][1].front(),y});
            d[0][1].pop_front();
            ans.push_back({x,y+=d[1][0].back()});
            d[1][0].pop_back();
        }
        else{
            ans.push_back({x-=d[0][1].back(),y});
            d[0][1].pop_back();
            ans.push_back({x,y-=d[1][1].front()});
            d[1][1].pop_front();
        }
    }
    for(pii p:ans){
        if(sw)swap(p.first,p.second);
        printf("%d %d\n",p.first,p.second);
    }
    return 0;
}
int main(){
#ifdef LOCAL
    freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
freopen("error.txt","w",stderr);
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    int tc;
    cin>>tc;
    while(tc--){
        if(solve())return -1;
    }
    return 0;
}