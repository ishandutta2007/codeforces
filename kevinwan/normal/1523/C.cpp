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

void prln(vi&v){
    printf("%d",v[0]);
    for(int i=1;i<v.size();i++)printf(".%d",v[i]);
    printf("\n");
}

void solve(){
    int n;
    cin>>n;
    vi v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x==1)v.push_back(1);
        else{
            while(v.back()!=x-1)v.pop_back();
            ++v.back();
        }
        prln(v);
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