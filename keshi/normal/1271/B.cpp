//In the name of GOD
//Hello Yellow
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, w, b;

char c;

string s;

vector<ll> ans;

int main(){
	fast_io;
	
	cin >> n >> s;
	
	for(ll i = 0; i < n; i++){
		if(s[i] == 'W'){
			w++;
		}
		else{
			b++;
		}
	}
	
	if(n % 2 != w % 2 && n % 2 != b % 2){
		cout << -1;
		return 0;
	}
	
	if(n % 2 == w % 2){
		c = 'W';
	}
	else{
		c = 'B';
	}
	
	for(ll i = 0; i < n - 1; i++){
		if(s[i] != c){
			ans.pb(i);
			if(s[i] == 'W'){
				s[i] = 'B';
			}
			else{
				s[i] = 'W';
			}
			if(s[i + 1] == 'W'){
				s[i + 1] = 'B';
			}
			else{
				s[i + 1] = 'W';
			}
		}
	}
	
	cout << ans.size() << endl;
	
	for(ll i = 0; i < ans.size(); i++){
		cout << ans[i] + 1 << " ";
	}
	
	return 0;
}