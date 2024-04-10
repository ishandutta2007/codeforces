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
const int mn=610;
mt19937 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
auto begin_time=std::chrono::high_resolution_clock::now();
const ll mod=998244353;

void solve(){
    int n;
    cin>>n;
    int x;
    for(int i=0;i<n;i++)cin>>x;
    printf("%d\n",3*n);
    for(int i=1;i<=n;i+=2){
        printf("2 %d %d\n",i,i+1);
        printf("1 %d %d\n",i,i+1);
        printf("2 %d %d\n",i,i+1);
        printf("2 %d %d\n",i,i+1);
        printf("1 %d %d\n",i,i+1);
        printf("2 %d %d\n",i,i+1);
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int tc;
    cin>>tc;
    while(tc--){
        solve();
    }
}