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
ll a,b,x,y;

int main(){
    cin >> T;
    while(T--){
        ll res =  0;
        cin >> x >> y >> a >> b;
        if(y >x)swap(x,y);
        res+=a*(x-y);
        res+=(y*min(2*a,b));
        cout << res << "\n";
    }
    return 0;
}