#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 100;
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

ll n, t, ptr, ans;
pll p[MAXN];

int main(){
	fast_io;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> p[i].F >> p[i].S;
	}
	sort(p, p + n, greater<pll>());
	t = 1;
	while(t && ptr < n){
		t += p[ptr].S - 1;
		ans += p[ptr].F;
		ptr++;
	}
	cout << ans;
	return 0;
}