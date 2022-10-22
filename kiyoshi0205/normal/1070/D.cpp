#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define endl "\n"
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll i,n, k,ans=0,res;
    cin >> n >> k;
    vector<ll> a(n+1,0);
    for(i = 0; i < n; i++) {
        cin >> a[i];
    }
    i=0;
    while(i<n){
        ans+=a[i]/k;
        a[i]%=k;
        if(a[i]){
            ans++;
          a[i+1]=max(0LL,a[i+1]-k+a[i]);
        }
        i++;
    }
        cout<<ans << endl;
}