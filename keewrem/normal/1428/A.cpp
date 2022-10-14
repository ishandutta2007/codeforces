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
ll x,y,xx,yy;

int main(){
    cin >> T;
    while(T--){
        cin >> x >> y >> xx >> yy;
        ll ans = abs(xx-x)+abs(yy-y)+2;
        if(x==xx || y==yy)ans-=2;
        cout << ans << "\n";
    }
    return 0;
}