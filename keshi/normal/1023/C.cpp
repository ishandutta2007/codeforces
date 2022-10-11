// In The Name of GOD
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 100;
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

ll n, k, o, c, ans;
string s;

int main(){
	fast_io;
	
	cin >> n >> k >> s;
	
	for(ll i = 0; i < n; i++){
		if(s[i] == '('){
			if(o * 2 < k){
				o++;
				c++;
				cout << '(';
			}
		}
		else{
			if(c > 0){
				c--;
				cout << ')';
			}
		}
	}
	
	
	return 0;
}