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


int a[mn],p[mn];
bool u[mn];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i],p[i]=u[i]=0;
        int ans=0;
        for(int i=1;i<=n;i++)if(!u[a[i]]){
            ++ans;
            p[i]=a[i];
            u[a[i]]=1;
        }
        set<int>f,t;
        for(int i=1;i<=n;i++){
            if(!p[i])f.insert(i);
            if(!u[i])t.insert(i);
        }
        int c=0;
        while(f.size()){
            auto it=f.begin(),jt=t.begin();
            if(*it==*jt&&t.size()>1)++jt;
            p[*it]=*jt;
            if(*it==*jt)c=*it;
            f.erase(it),t.erase(jt);
        }
        if(c){
            for(int i=1;i<=n;i++)if(a[i]==a[c]){
                swap(p[i],p[c]);
                break;
            }
        }
        printf("%d\n",ans);
        for(int i=1;i<=n;i++)printf("%d ",p[i]);
        printf("\n");
    }
}