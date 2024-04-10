/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9+7;
const int N = 5e5+5;

vector< pair<int,int> > adj[N];
set<int> s;
int vis[N]={0};
int cnt;

struct cmp
{
   bool operator()(array<int, 3>& a, array<int, 3>& b)
   {
       return a[0]>b[0];
   }
};

priority_queue< array<int, 3> , vector< array<int, 3> >, cmp> q2;

/**Takes a&b as input and Returns : The power (a,b), (a^b)%mod **/
int Power(int $a,int $b)
{
    int $result=1; $a%=mod;
    while($b) {   if($b%2==1)  $result*=$a;     $a*=$a;     $a%=mod;     $result%=mod;    $b/=2; }
    return $result;
}

int parent[N];
int siz[N];

void make_set(int v)
{
    parent[v] = v;
    siz[v] = 1;
}

int find_set(int v)
{
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

bool union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a == b) return true;
 
    if (siz[a] < siz[b]) swap(a, b);
    parent[b] = a;
    siz[a] += siz[b];
    return false;
}

void dfs(int v)
{
    if(vis[v]==1) return;
    vis[v]=1;
    cnt++;
    
    for(auto x: adj[v])
    {
        int u=x.first;
        dfs(u);
    }
}

void solve()
{
    int n,m;
    cin>>n>>m;

    
    for(int i=1;i<=n;i++)
    {
        int l,x,y;
        cin>>l;
        if(l==1) { cin>>x; y=m+1; }
        else cin>>x>>y;
        adj[x].push_back( {y,i} );
        adj[y].push_back( {x,i} );
        q2.push( {i,x,y} );
    }

    int ans=1;
    for(int i=1;i<=m+1;i++)
    {
        make_set(i);
        cnt=0;
        dfs(i);
        if(cnt>0) cnt--;
        ans*=Power(2,cnt);
        ans%=mod;
    }
    
    while(!q2.empty())
    {
        auto cur = q2.top();
        q2.pop();
        
        int ind=cur[0];
        int u=cur[1];
        int v=cur[2];
        
        if(union_sets(u,v)) continue;
        s.insert(ind);
    }
    
    cout<<ans<<" ";
    cout<<s.size()<<endl;
    
    for(auto i : s)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}