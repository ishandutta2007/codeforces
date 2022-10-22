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


int a[mn],m[mn];
int sol[mn],du[mn];
int hailveshy2(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],m[i]=sol[i]=du[i]=0;
    for(int i=1;i<=n;i++)m[a[i]]++;
    for(int i=1;i<=n;i++){
        if(m[i]*2>n+1){
            printf("-1\n");
            return 0;
        }
    }
    vector<pii>v;
    int l=1;
    for(int i=1;i<=n;i++){
        if(a[i]==a[i-1]){
            v.push_back({a[l],a[i-1]});
            l=i;
        }
    }
    v.push_back({a[l],a[n]});
    for(pii p:v){
        if(p.first==p.second)sol[p.first]++;
        else du[p.first]++,du[p.second]++;
    }
    int ans=v.size();
    for(int i=1;i<=n;i++){
        int sc=sol[i]*2-int(v.size())+du[i];
        if(sc>1)ans=max(ans,int(v.size())+sc-1);
    }
    printf("%d\n",ans-1);
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
        hailveshy2();
    }
}