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

ll a,b,c,d;
ll res;

int main(){
    cin >> a >> b >> c >> d;
    ll act;
    for(ll i = 2*c; i >= 0; i--){
        act = max(0LL,min(i-b,b)-max(i-c,a)+1);
        res+= act * max(0LL,(min(d+1,i)-c));
    }
    cout << res << "\n";
    return 0;
}