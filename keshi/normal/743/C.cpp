#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 100;
const long long mod = 1e9 + 7;
const long long inf = 1e18;

typedef long long ll;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n;

int main(){
	fast_io;
	
	cin >> n;
	
	if(n == 1){
		cout << -1;
		return 0;
	}
	
	cout << n << " " << n + 1 << " " << n * (n + 1);
	
	return 0;
}