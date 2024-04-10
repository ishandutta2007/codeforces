#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	cout << fixed << setprecision(15);
	int n, k;
	cin >> n >> k;
	vector<array<int, 2>> a(n);
	vector<double> dist, angle;
	for(auto &[x, y]: a){
		cin >> x >> y;
		dist.push_back(sqrt(1LL * x * x + 1LL * y * y));
		angle.push_back(atan2(y, x));
	}
	double low = 0, high = 2e5;
	const double pi = acos(-1);
	for(auto rep = 60; rep; -- rep){
		double r = (low + high) / 2;
		static vector<pair<double, int>> delta;
		delta.clear();
		for(auto i = 0; i < n; ++ i){
			if(dist[i] < 2 * r){
				double theta = acos(dist[i] / (2.0 * r));
				delta.push_back({angle[i] - theta, 1});
				delta.push_back({angle[i] + theta, -1});
				delta.push_back({angle[i] + 2 * pi - theta, 1});
				delta.push_back({angle[i] + 2 * pi + theta, -1});
			}
		}
		sort(delta.begin(), delta.end());
		int cur = 0;
		bool ok = false;
		for(auto [angle, d]: delta){
			cur += d;
			if(cur >= k){
				ok = true;
				break;
			}
		}
		if(ok){
			high = r;
		}
		else{
			low = r;
		}
	}
	cout << (low + high) / 2 << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////