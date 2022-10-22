#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int mn=300;
ll x[mn],y[mn];
bool comp(pii a,pii b){
    return atan2(y[a.second]-y[a.first],x[a.second]-x[a.first])<atan2(y[b.second]-y[b.first],x[b.second]-x[b.first]);
}
ll dp[mn][mn][6];
vector<pii>ed;
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%lld%lld",x+i,y+i);
    for(i=0;i<n;i++)for(j=i+1;j<n;j++)ed.push_back({i,j}),ed.push_back({j,i});
    sort(ed.begin(),ed.end(),comp);
    for(i=0;i<n;i++)dp[i][i][0]=1;
    for(pii e:ed){
        for(i=0;i<n;i++){
            for(j=1;j<6;j++){
                dp[i][e.second][j]+=dp[i][e.first][j-1];
            }
        }
    }
    ll ans=0;
    for(i=0;i<n;i++)ans+=dp[i][i][5];
    printf("%lld",ans);
}