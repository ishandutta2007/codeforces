//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a[maxn];

int main(){
	fast_io;
	
	cin >> n;
	
	if(n % 2 == 0){
		cout << "NO";
		return 0;
	}
	
	for(ll i = 0; i < n; i++){
		if(i % 2){
			a[i] = 2 * i + 2;
			a[i + n] = 2 * i + 1;
		}
		else{
			a[i] = 2 * i + 1;
			a[i + n] = 2 * i + 2;
		}
	}
	
	cout << "YES" << endl;
	
	for(ll i = 0; i < 2 * n; i++){
		cout << a[i] << " ";
	}
	
	return 0;
}