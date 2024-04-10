// In The Name of GOD
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define file_io freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F second
#define S first

ll n, p[MAXN];
long double PI, ans;

int main(){
	fast_io;
	PI = acos(-1);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> p[i];
	}
	sort(p, p + n, greater<ll>());
	for(int i = 0; i < n; i++){
		if(i % 2){
			ans -= p[i] * p[i];
		}
		else{
			ans += p[i] * p[i];
		}
	}
	cout << ans * PI;
	return 0;
}