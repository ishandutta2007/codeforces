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
const int mn=2e5+10;

int a[mn];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int tc;
    cin>>tc;
    while(tc--){
        ll n;
        cin>>n;
        ll sq = sqrt(n/4)+.5;
        ll sq2=sqrt(n/2)+.5;
        if(sq*sq*4==n||sq2*sq2*2==n)printf("YES\n");
        else printf("NO\n");
    }
}