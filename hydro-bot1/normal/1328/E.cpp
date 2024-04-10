// Hydro submission #62c6d62d8672efa577c024c0@1657198126085
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using pbset=tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
template<class T> using pbmultiset=tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update> ;
#define f(i,a,b) for(long long i=a;i<b;i++)
#define rf(i,a,b) for(long long i=a;i>=b;i--)
#define ll long long
#define mp make_pair
#define pb push_back
#define vll vector<long long>
#define vvl vector<vll>
#define pll pair<ll,ll>
#define vc vector
#define fi first
#define se second
#define lb lower_bound
#define POW(a,b) (ll)(pow(a,b)+0.5)
#define Ceil(a,b) (ll)((a+b-1)/b)
#define gcd __gcd
#define to_lowercase(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define to_uppercase(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
#define p_q priority_queue
#define pqmax priority_queue<ll>
#define pqmin priority_queue<ll,vector<ll>,greater<ll>>
#define all(x) x.begin(),x.end()
#define inc(x,start) iota(x.begin(),x.end(),start)
#define pi  M_PI
#define inf  LONG_LONG_MAX
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define IOS ios_base::sync_with_stdio(0)
#define tie cin.tie(NULL),cout.tie(NULL) 
#define endl '\n'
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x) 
#endif
template<class T> void _print(T t){ cerr << t;}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fi); cerr << ","; _print(p.se); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

const int mod = 1e9 + 7;

int LOG;
vector<vector<int>> up;
vector<int> depth;

void TreeAncestor(int n, vector<ll>& parent)
{
    LOG=0;
    while((1 << LOG) <= n) 
        LOG++;
    up = vector<vector<int>>(n, vector<int>(LOG));
    
    for(int v = 0; v < n; v++)
        up[v][0] = parent[v];

    for(int j = 1; j < LOG; j++) 
        for(int v = 0; v < n; v++)
        up[v][j] = up[ up[v][j-1] ][j-1];
    
}
int getKthAncestor(int node, int k) 
{
    if(depth[node] < k) 
        return -1;
    
    for(int j = LOG - 1; j >= 0; j--) 
    if(k >= (1 << j)) 
        {
            node = up[node][j];
            k -= 1 << j;
        }
    
    return node;
}
void dfs(int vertex,vector<ll> *adjlist,int curr_depth)
{
    depth[vertex]=curr_depth;
    for(auto i: adjlist[vertex])
     dfs(i,adjlist,curr_depth+1);

}
int lca(int a,int b)
{
  if(a==b)
   return a;
  if(depth[b]>depth[a])
   swap(a,b);
  if(depth[a]>depth[b])
  {
      int diff=depth[a]-depth[b];
      a=getKthAncestor(a,diff);
  }
  if(a==b)
   return a;
  for(int j=LOG-1;j>=0;j--)
   if(up[a][j]!=up[b][j])
   {
       a=up[a][j];
       b=up[b][j];
   }
   return up[a][0];
}
void dfs(long long vertex,ll pp,vector<long long>* AdjList,vll *adj_dir,vll &parent)
{ 
 
  for(auto i: AdjList[vertex])
    if(i!=pp)
      {
         parent[i]=vertex;
         adj_dir[vertex].pb(i);
         dfs(i,vertex,AdjList,adj_dir,parent);
      }
}
int main()
{  
   IOS;tie;
   ll n,m;
   cin>>n>>m;
   vll adj[n];
   f(i,0,n-1)
   {
       ll x,y;
       cin>>x>>y;
       x--,y--;
       adj[x].pb(y);
       adj[y].pb(x);
   }
   vll adj_dir[n];
   vll parent(n,-1);
   dfs(0,-1,adj,adj_dir,parent);
   parent[0]=0;
   depth=vector<int>(n);
   dfs(0,adj_dir,0);
   TreeAncestor(n,parent);  
   while(m--)
   {
     ll k;
     cin>>k;
     vc<pll> ind;
     f(i,0,k)
     {
         ll v;
         cin>>v;
         v--;
         ind.pb({depth[v],v});
     }
     sort(all(ind));
     bool pos=true;
     f(i,0,k-1)
      {
          ll an=lca(ind[i].se,ind[i+1].se);
          if(an==ind[i].se or an==parent[ind[i].se])
           continue;
           else
           {pos=false;break;}
      }
      if(pos)
       cout<<"YES"<<endl;
       else
        cout<<"NO"<<endl;
   }
    return 0;
}