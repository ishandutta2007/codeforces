#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mn=19;
vector<int> g[mn];
ll ans=0;
ll num[mn][1<<mn];
void solve(int x){
    int i,j;
    for(i=0;i<=x;i++)for(j=0;j<1<<(x+1);j++)num[i][j]=0;
    queue<pii>q;
    for(int y:g[x]){
        if(y>x)continue;
        q.push({y,1<<y});
        num[y][1<<y]=1;
    }
    while(q.size()){
        int c=q.front().first,m=q.front().second;
        q.pop();
        for(int y:g[c]){
            if(y>x)continue;
            if((m>>y)&1)continue;
            if(!num[y][m|(1<<y)])q.push({y,m|(1<<y)});
            num[y][m|(1<<y)]+=num[c][m];
        }
    }
    for(i=0;i<1<<(x+1);i++)if(__builtin_popcount(i)>=3)ans+=num[x][i];
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,m,i,a,b;
    cin>>n>>m;
    for(i=0;i<m;i++){
        cin>>a>>b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    for(i=n-1;i>=0;i--)solve(i);
    printf("%lld",ans/2);
}