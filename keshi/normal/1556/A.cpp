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

ll t, a, b;

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> a >> b;
		if((a + b) & 1){
			cout << "-1\n";
			continue;
		}
		if(a == 0 && b == 0){
			cout << "0\n";
			continue;
		}
		if(a == b){
			cout << "1\n";
		}
		else cout << "2\n";
	}
	
	return 0;
}