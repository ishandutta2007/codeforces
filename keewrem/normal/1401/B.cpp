#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int T;
ll a,b,c,aa,bb,cc;

int main(){
    cin >> T;
    while(T--){
        cin >> a >> b >> c >> aa >> bb >> cc;
        ll ans = 0;
        ll k = min(c,bb);
        ans += 2*k;
        c-=k; bb-=k;
        ans-=2*max(0LL,cc-a-c);
        cout << ans << "\n";
    }
    return 0;
}