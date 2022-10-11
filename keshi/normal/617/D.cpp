#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second

ll x, y, ans;
pll a[3];
map<ll, int> mx, my;

int main(){
	fast_io;
	for(int i = 0; i < 3; i++){
		cin >> x >> y;
		a[i].X = x;
		a[i].Y = y;
		mx[x]++;
		my[y]++;
	}
	ans = min(mx.size(), my.size());
	if(ans == 2){
		if(mx.size() == 2){
			for(int i = 0; i < 3; i++){
				swap(a[i].X, a[i].Y);
			}
			sort(a, a + 3);
			if(mx[a[1].Y] == 1 && my[a[1].X] == 1){
				ans = 3;
			}
		}
		else if(my.size() == 2){
			sort(a, a + 3);
			if(mx[a[1].X] == 1 && my[a[1].Y] == 1){
				ans = 3;
			}
		}
	}
	cout << ans;
	return 0;
}