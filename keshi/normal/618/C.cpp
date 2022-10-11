#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;

#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

ll n, j;

pair< pair<long double, long double>, ll > a[MAXN];

pll p[MAXN];

int main(){
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> p[i].x >> p[i].y;
	}
	
	for(ll i = 1; i < n; i++){
		a[i].y = i;
		a[i].x.y = (p[i].y - p[0].y) * (p[i].y - p[0].y) + (p[i].x - p[0].x) * (p[i].x - p[0].x);
		a[i].x.x = atan2(p[i].y - p[0].y, p[i].x - p[0].x);
	}
	
	sort(a + 1, a + n);
	a[0].y = a[n - 1].y;
	a[0].x.x = a[n - 1].x.x;
	a[0].x.y = a[n - 1].x.y;
	
	j = 1;
	
	for(ll i = 2; i < n; i++){
		if((p[a[1].y].x - p[0].x) * (p[a[i].y].y - p[0].y) != (p[a[i].y].x - p[0].x) * (p[a[1].y].y - p[0].y)){
			cout << 1 << ' ' << a[1].y + 1 << ' ' << a[i].y + 1 << endl;
			return 0;
		}
	}
	
	
	return 0;
}