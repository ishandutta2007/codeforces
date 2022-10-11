//In the name of GOD
//Global Round just dont make me blue :)
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

ll q, n, c, e;

bool f;

string s;

int main(){
	fast_io;
	
	cin >> q;
	
	for(ll i = 0; i < q; i++){
		cin >> s;
		n = s.size();
		f = 0;
		c = 0;
		e = 0;
		for(ll j = 0; j < n; j++){
			if(s[j] == '0'){
				f = 1;
			}
			if((s[j] - '0') % 2 == 0){
				c++;
			}
			e += (s[j] - '0');
		}
		if(f && c >= 2 && (e % 3) == 0){
			cout << "red\n";
		}
		else{
			cout << "cyan\n";
		}
	}
	
	return 0;
}