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
ll N;

int main(){
    cin >> T;
    ll a,b,x,y;
    while(T--){
        cin >> a >> b >> x >> y >> N;
        ll k = min(a-x,N), kk = min(b-y,N);
        cout << min((a-k)*max(y,b-N+k),(b-kk)*max(x,a-N+kk))<<"\n";
    }
    return 0;
}