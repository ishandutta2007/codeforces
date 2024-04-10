#include <iostream>
#include <cstdio>
#include <vector>
#include <functional>
#include <queue>
 
using namespace std;
 
#define inf 99999999
#define dmax 411*411
#define pb push_back
#define x first
#define y second
 
 
int n, a, b, m, vi[411][411];
typedef pair<int, int> pi;
vector <pi> v[dmax];
int d[dmax];
bool use[dmax];
 
class compare
{
public:
    bool operator()(const int &a,const int &b)
    {
        return d[a]>d[b];
    }
};
 
priority_queue<int,vector<int>,compare>q;
 
void dijkstra(int x)
{
    for(int i=1; i<=n; i++)
        d[i]=inf;
 
    q.push(x);
    d[1]=0;
 
    while(!q.empty())
    {
        int a=q.top();
        q.pop();
 
        //if(a.x<=d[a.y] || a.y==1)
        for(int i=0; i<v[a].size(); i++)
        {
 
            pi h=v[a][i];
            if(d[h.y]>h.x+d[a])
            {
                d[h.y]=h.x+d[a];
 
                q.push(v[a][i].y);
//                heap.pb(v[a.y][i]);
//                push_heap(heap.begin(), heap.end());
            }
            }
    }
}
 

int main()
{
cin>>n>>m;

for(int i=1;i<=m;i++)
{
    cin>>a>>b;
    vi[a][b]=1;
    vi[b][a]=1;
}
int ok=0;
if(vi[1][n]==0){
    ok=1;
}

for(int i=1;i<=n;i++)
for(int j=1;j<=n;j++)
{
    if(vi[i][j]==ok)
    v[i].push_back({1, j});
}

dijkstra(1);
if(d[n]!=inf)
cout<<d[n]<<'\n';
else cout<<"-1\n";

    return 0;
}