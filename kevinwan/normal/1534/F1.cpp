#include <bits/stdc++.h>
using namespace std;
 
const double eps = 1e-9;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef __int128 lll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const int mn=4e5+10;
mt19937 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
auto begin_time=std::chrono::high_resolution_clock::now();
const ll mod=1e9+7;
string s[mn];
int n,m;
inline int id(int r,int c){return r*m+c;}
vi g[mn];
bool val[mn];

int sct,ct;
int scc[mn],l[mn],o[mn];
stack<int>st;
bool vis[mn],ins[mn];
void dfs(int x){
    vis[x]=ins[x]=1;
    st.push(x);
    l[x]=o[x]=ct++;
    for(int y:g[x]){
        if(!vis[y])dfs(y),l[x]=min(l[x],l[y]);
        else if(ins[y])l[x]=min(l[x],o[y]);
    }
    if(l[x]==o[x]){
        while(st.top()!=x)scc[st.top()]=sct,ins[st.top()]=0,st.pop();
        scc[st.top()]=sct,ins[st.top()]=0,st.pop();
        ++sct;
    }
}

vi scg[mn];
bool nr[mn];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)cin>>s[i];
    for(int i=0;i<m;i++){
        int cur=-1;
        for(int j=0;j<n;j++){
            //cerr<<j<<" "<<i<<endl;
            if(s[j][i]=='#'){
                val[id(j,i)]=1;
                if(cur!=-1)g[cur].push_back(id(j,i));
                cur=id(j,i);
            }
            //if(i==1)cerr<<cur<<endl;
            if(cur!=-1&&i&&s[j][i-1]=='#')g[cur].push_back(id(j,i-1));
            if(cur!=-1&&i+1<m&&s[j][i+1]=='#')g[cur].push_back(id(j,i+1));
        }
    }
    //for(int x:g[8])cerr<<x<<" ";
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        if(i+1<n&&s[i][j]=='#'&&s[i+1][j]=='#')g[id(i+1,j)].push_back(id(i,j));
    }
    for(int i=0;i<n*m;i++)if(!vis[i]&&val[i])dfs(i);
    for(int i=0;i<n*m;i++)if(val[i]){
        for(int j:g[i])if(scc[i]!=scc[j])scg[scc[i]].push_back(scc[j]),nr[scc[j]]=1;
    }
    
    int ans=0;
    for(int i=0;i<sct;i++)ans+=1-nr[i];
    printf("%d\n",ans);
}