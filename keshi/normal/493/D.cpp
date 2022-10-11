//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 510;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n;

int main(){
	fast_io;
	
	cin >> n;
	
	if(n % 2){
		cout << "black";
	}
	else{
		cout << "white\n1 2";
	}
	
	return 0;
}