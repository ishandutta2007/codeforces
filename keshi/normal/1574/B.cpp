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

ll t, a, b, c, x, y;

int main(){
    fast_io;
    
    cin >> t;
    while(t--){
    	cin >> a >> b >> c;
    	cin >> x;
    	y = a + b + c - x;
    	if(y < 3 || y > min({a + b + c, 2 * (a + b) + 1, 2 * (b + c) + 1, 2 * (c + a) + 1})){
    		cout << "NO\n";
		}
		else{
			cout << "YES\n";
		}
	}
 
    return 0;
}