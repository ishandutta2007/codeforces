// Hydro submission #61794e3842369d1fc173e36f@1635339833143
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define prt(ns,n) for(int i=0;i<n;i++)printf("%d%c",ns[i],i==n-1?'\n':' ');
#define for1(i,n) for(int i=0;i<n;i++)
#define for2(i,n) for(int i=1;i<=n;i++)
#define all(t) t.begin(),t.end()
#define PQ priority_queue
#define pii pair<int,int>
#define pll pair<ll,ll>
#define dormir_11 ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'

using namespace std;
const  int mod = 1e9+7;
const ll Linf=0x3f3f3f3f3f3f3f3f;
const int inf=0x3f3f3f3f;
const long double PI = 3.14159265358979323;
const double eps = 1e-8;
const int dir[4][2] = { {1,0},{0,-1},{0,1},{-1,0} };
const char dirs[4]={'D','L','R','U'};
const int moth[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
inline int gcd(int a, int b){return a%b==0? b: gcd(b, a%b);}
inline ll fast_powr(ll  a,ll b){ ll ret=1%mod;for(;b;b>>=1,a=(ll)a*a%mod)if(b&1)ret=(ll)ret*a%mod;return ret; }
inline ll mul(ll a,ll b,ll p){ll ret=0;for(;b;b>>=1,a=a*2%p)if(b&1)ret=(ret+a)%p;return ret;}
inline bool cmp(int a,int b){return a>b;}
inline void YorN(bool flag){cout<<(flag?"Yes":"No")<<endl;}



const int MAX=2e5+5;

vector<vector<pair<int,bool>>>eg;
int col[MAX];
bool ok;
int c[2];

void dfs(int &v){
    c[col[v]]++;
    for(auto u:eg[v]){
        if(col[u.fi]==-1){
            col[u.fi]=(u.se?col[v]:(!col[v]));
            dfs(u.fi);
        }else if((u.se&&col[u.fi]!=col[v])||(!u.se&&col[u.fi]==col[v])){
            ok=false;
            return ;
        }
    }
}

void solve() {
    ok=true;
    int n,m;
    cin>>n>>m;
    eg.assign(n+5,vector<pair<int ,bool>>());
    for(int i=1;i<=n;i++)eg[i].clear(),col[i]=-1;
    for1(i,m){
        int u,v,k;string s;
        cin>>u>>v>>s;
        if(s[0]=='i')k=0;
        else k=1;
        eg[u].push_back({v,k});
        eg[v].push_back({u,k});
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(col[i]!=-1)continue;
        col[i]=0;
        c[0]=c[1]=0;
        dfs(i);
        ans+=max(c[0],c[1]);
    }
    if(!ok)ans=-1;
    cout<<ans<<endl;
}



int main(){
//
//

    int _;scanf("%d",&_);
    while(_--){
        solve();
    }

//    solve();


    return 0;
}


/*

 * 
 * 
 * 
 * 


 5
 5 a
 bbabb

 */