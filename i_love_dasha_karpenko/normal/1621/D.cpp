#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
//#define endl '\n'
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gi(x) int(x-'0')

const int N = 507;
int A[N][N];
bool vis[N][N];
ll dist[N][N];
typedef pair<ll,pair<int,int> > pp;
priority_queue<pp,vector<pp>,greater<pp> > Q;
int n;
void Check(int x,int y,ll ds){
    if (x<1)
        x = (n<<1);
    if (x>(n<<1))
        x = 1;
    if (y<1)
        y = (n<<1);
    if (y>(n<<1))
        y = 1;

    ds+=A[x][y];
    if (!vis[x][y] || dist[x][y]>ds){
        dist[x][y] = ds;
        vis[x][y] = 1;
        Q.push(mp(ds,mp(x,y)));
    }
}
ll F(int x,int y){
    return dist[x][y]-A[x][y];
}
void solve() {

    cin>>n;
    ll res = 0;

    for(int i = 1;i<=(n<<1);++i)
        for(int j = 1;j<=(n<<1);++j){
            vis[i][j] = 0;
            cin>>A[i][j];
            if (i>n && j>n)
                res+=A[i][j];
        }


    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=n;++j){
            vis[i][j] = 1;
            dist[i][j] = 0;
            Q.push(mp(0,mp(i,j)));
        }
    }

    while(!Q.empty()){
        int x = Q.top().second.first,y = Q.top().second.second;
        bool flag = dist[x][y]==Q.top().first;
        Q.pop();
        if (!flag || (x>n && y>n))
            continue;

        Check(x+1,y,dist[x][y]);
        Check(x-1,y,dist[x][y]);
        Check(x,y+1,dist[x][y]);
        Check(x,y-1,dist[x][y]);
    }
    ll min_add = min({F(n+1,n+1),F(n+1,n<<1),F(n<<1,n+1),F(n<<1,n<<1)});
    cout<<res+min_add<<endl;
}
int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;

    while(t--)
        solve();
}