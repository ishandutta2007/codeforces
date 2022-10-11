//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll t, n;

int main(){
    fast_io;
    
    cin >> t;
    while(t--){
    	cin >> n;
    	for(ll i = 0; i < n; i++){
    		cout << "(";
    		for(ll j = 0; j < i; j++){
    			cout << "()";
			}
			cout << ")";
    		for(ll j = 0; j < n - i - 1; j++){
    			cout << "()";
			}
			cout << "\n";
		}
	}
 
    return 0;
}