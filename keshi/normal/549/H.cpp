//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 2e5 + 100;
const ld eps = 1e-4;
const ll mod = 1e9 + 7;
const ld inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ld p[2][2], a[2][2], b[2][2], ans;

bool solve(ld x){
	a[0][0] = p[0][0] - x;
	a[0][1] = p[0][0] + x;
	a[1][0] = p[0][1] - x;
	a[1][1] = p[0][1] + x;
	b[0][0] = p[1][0] - x;
	b[0][1] = p[1][0] + x;
	b[1][0] = p[1][1] - x;
	b[1][1] = p[1][1] + x;
	if(abs(a[1][0]) > eps && b[0][0] <= a[0][1] * b[1][0] / a[1][0] && a[0][1] * b[1][0] / a[1][0] <= b[0][1]) return 1;
	if(abs(a[0][1]) > eps && b[1][0] <= a[1][0] * b[0][0] / a[0][1] && a[1][0] * b[0][0] / a[0][1] <= b[1][1]) return 1;
	if(abs(a[1][1]) > eps && b[0][0] <= a[0][0] * b[1][0] / a[1][1] && a[0][0] * b[1][0] / a[1][1] <= b[0][1]) return 1;
	if(abs(a[0][0]) > eps && b[1][0] <= a[1][1] * b[0][0] / a[0][0] && a[1][1] * b[0][0] / a[0][0] <= b[1][1]) return 1;
	swap(a, b);
	if(abs(a[1][0]) > eps && b[0][0] <= a[0][1] * b[1][0] / a[1][0] && a[0][1] * b[1][0] / a[1][0] <= b[0][1]) return 1;
	if(abs(a[0][1]) > eps && b[1][0] <= a[1][0] * b[0][0] / a[0][1] && a[1][0] * b[0][0] / a[0][1] <= b[1][1]) return 1;
	if(abs(a[1][1]) > eps && b[0][0] <= a[0][0] * b[1][0] / a[1][1] && a[0][0] * b[1][0] / a[1][1] <= b[0][1]) return 1;
	if(abs(a[0][0]) > eps && b[1][0] <= a[1][1] * b[0][0] / a[0][0] && a[1][1] * b[0][0] / a[0][0] <= b[1][1]) return 1;
	return 0;
}

int main(){
	fast_io;
	
	cout << setprecision(10) << fixed;
	
	cin >> p[1][0] >> p[1][1] >> p[0][0] >> p[0][1];
	
	if(p[0][0] * p[1][1] == p[0][1] * p[1][0]){
		cout << 0;
		return 0;
	}
	
	ld l = 0, r = inf, mid;
	
	for(ll i = 0; i < 100; i++){
		mid = (l + r) / 2;
		if(solve(mid)) r = mid;
		else l = mid;
	}
	
	ans = r;
	
	p[0][0] *= -1;
	p[1][0] *= -1;
	
	l = 0, r = inf;
	
	for(ll i = 0; i < 100; i++){
		mid = (l + r) / 2;
		if(solve(mid)) r = mid;
		else l = mid;
	}
	
	cout << min(ans, r);
	
	return 0;
}