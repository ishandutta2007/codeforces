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
const int mn=3e5+10;
const ll mod=1e9+7;

vector<int>g[mn];
bool don[mn];

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
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)g[i].clear(),don[i]=0;
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<int>ans;
        queue<int>q;
        q.push(1);
        while(q.size()){
            int x=q.front();
            q.pop();
            if(don[x])continue;
            ans.push_back(x);
            don[x]=1;
            for(int y:g[x])if(!don[y]){
                don[y]=1;
                for(int z:g[y])if(!don[z]){
                    q.push(z);
                }
            }
        }
        bool gud=1;
        for(int i=1;i<=n;i++)if(!don[i])gud=0;
        if(!gud)printf("NO\n");
        else {
            printf("YES\n%d\n",ans.size());
            for(int x:ans)printf("%d ",x);
            printf("\n");
        }
    }
}