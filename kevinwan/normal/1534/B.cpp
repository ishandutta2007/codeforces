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

ll h[mn];

int main(){
    int tcc;
    scanf("%d",&tcc);
    while(tcc--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%lld",h+i);
        h[0]=h[n+1]=0;
        ll ans=0;
        for(int i=1;i<=n+1;i++){
            ans+=abs(h[i]-h[i-1]);
        }
        for(int i=1;i<=n;i++){
            if(h[i]>h[i-1]&&h[i]>h[i+1])
                ans-=h[i]-max(h[i-1],h[i+1]);
        }
        printf("%lld\n",ans);
    }
}