#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define file_io freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

string s;
ll n, ans, sum;


int main(){
	fast_io;
	
	cin >> s;
	n = s.size();
	ans = 1;
	for(ll i = 0; i < n; i++){
		if('0' <= s[i] && s[i] <= '9'){
			sum = s[i] - '0';
		}
		else if('A' <= s[i] && s[i] <= 'Z'){
			sum = s[i] - 'A' + 10;
		}
		else if('a' <= s[i] && s[i] <= 'z'){
			sum = s[i] - 'a' + 36;
		}
		else if(s[i] == '-'){
			sum = 62;
		}
		else if(s[i] == '_'){
			sum = 63;
		}
		for(ll j = 0; j < 6; j++){
			if(sum % 2 == 0){
				ans = (ans * 3) % MOD;
			}
			sum /= 2;
		}
	}
	
	cout << ans;
	
	return 0;
}