#include <bits/stdc++.h>
using namespace std;
using real_t = long double;
using pi = pair<real_t, real_t>;
const int MAXN = 3005;
const real_t PI = acos(-1.0L);
const real_t eps = 1e-8L;

bool go[MAXN][MAXN];
int n, d;

complex<real_t> a[MAXN];

real_t norm(real_t x){
	return fmod(x + 4 * PI, 2 * PI);
}

// it is quite similar to NEERC 2015 northern kingdom trip

int main(){
	cin >> n >> d;
	for(int i=0; i<n; i++){
		int x, y;
		cin >> x >> y;
		a[i] = complex<real_t>(x, y);
	}
	for(int i=0; i<n; i++){
		pi rng(-1e9, 1e9);
		real_t rot;
		bool fucked = 0;
		for(int j=0; j<n; j++){
			if(i == j) continue;
			if(rng.first < -1e8){
				if(abs(a[j] - a[i]) <= d){
					continue;
				}
				rot = PI - arg(a[j] - a[i]);
			}
			auto dir = norm(arg(a[j] - a[i]) + rot);
			auto dist = abs(a[j] - a[i]);
			if(dist <= d) continue;
			auto ang = asin(d / dist);
			auto bound_l = norm(dir - ang);
			auto bound_r = norm(dir + ang);
			if(bound_l > bound_r){
				if(bound_l < rng.second){
					rng.first = max(rng.first, bound_l);
				}
				else{
					rng.second = min(rng.second, bound_r);
				}
			}
			else{
				rng.first = max(rng.first, bound_l);
				rng.second = min(rng.second, bound_r);
			}
			if(rng.first > rng.second ){
				fucked = 1;
				break;
			}
		}
		if(fucked) continue;
		for(int j = 0; j < n; j++){
			if(i == j) continue;
			if(rng.first < -1e8){
				auto dist = abs(a[j] - a[i]);
				assert(dist <= d);
				go[i][j] = 1;
				continue;
			}
			auto dir = norm(arg(a[j] - a[i]) + rot);
			if(rng.first <= dir && dir <= rng.second){
				go[i][j] = 1;
			}
		}
	}
	int ret = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			if(go[i][j] && go[j][i]) ret++;
		}
	}
	cout << ret << endl;
}