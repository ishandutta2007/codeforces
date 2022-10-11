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

ll a, b, c, ans;


int main(){
	fast_io;
	
	cin >> a >> b;
	if(a > b){
		swap(a, b);
	}
	c = min(a, b - a);
	ans += c;
	a -= c;
	b -= c * 2;
	if(a == 0){
		cout << ans;
		return 0;
	}
	c = a / 3;
	ans += c * 2;
	a %= 3;
	if(a == 2){
		ans++;
	}
	cout << ans;
	
	return 0;
}