//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a, b;

string s;

int main(){
	fast_io;
	
	cin >> n >> s;
	
	for(ll i = 0; i < n / 2; i++){
		if(s[i] == '?'){
			b--;
		}
		else{
			a += s[i] - '0';
		}
	}
	for(ll i = n / 2; i < n; i++){
		if(s[i] == '?'){
			b++;
		}
		else{
			a -= s[i] - '0';
		}
	}
	if(2 * a == 9 * b){
		cout << "Bicarp";
	}
	else{
		cout << "Monocarp";
	}
	
	return 0;
}