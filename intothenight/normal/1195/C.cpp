#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n;
	vector<vector<ll>> h(2, vector<ll>(n)), d(h);
	for(auto &x: h){
		for(auto &y: x){
			cin >> y;
		}
	}
	d[0][0] = h[0][0], d[1][0] = h[1][0];
	for(int j = 1; j < n; j ++){
		d[0][j] = max(d[0][j - 1], d[1][j - 1] + h[0][j]);
		d[1][j] = max(d[1][j - 1], d[0][j - 1] + h[1][j]);
	}
	cout << max(d[0].back(), d[1].back());
	return 0;
}