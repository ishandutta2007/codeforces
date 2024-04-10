#include <bits/stdc++.h>

using namespace std;

long long ccw(pair<long long, long long> x, pair<long long, long long> y, pair<long long, long long> z){
	y.first -= x.first, y.second -= x.second;
	z.first -= x.first, z.second -= x.second;
	long long val = y.first * z.second - y.second * z.first;
	if(val > 0) return 1;
	if(val < 0) return -1;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long N;
	cin >> N;
	vector<pair<long long, long long>> a(N);
	for(long long i = 0; i < N; ++i){
		cin >> a[i].first >> a[i].second;
	}
	vector<long long> chk(N), ans(N);
	ans[0] = 0;
	chk[0] = 1;
	for(long long i = 1; i < N; ++i){
		long long pos = ans[i - 1];
		long long num = -1;
		for(long long j = 0; j < N; ++j){
			if(chk[j]){
				continue;
			}
			if(num == -1){
				num = j;
				continue;
			}
			if(ccw(a[num], a[j], a[pos]) > 0){
				pair<long long, long long> p = {a[num].first - a[num].second + a[pos].second, a[num].second + a[num].first - a[pos].first};
				if(ccw(a[num], a[j], p) >= 0){
					num = j;
				}
			}
			else if(ccw(a[num], a[j], a[pos]) < 0){
				pair<long long, long long> p = {a[num].first + a[num].second - a[pos].second, a[num].second - a[num].first + a[pos].first};
				if(ccw(a[num], a[j], p) <= 0){
					num = j;
				}
			}
			else{
				if(abs(a[num].first - a[pos].first) < abs(a[j].first - a[pos].first) || 
					abs(a[num].second - a[pos].second) < abs(a[j].second - a[pos].second)){
					num = j;
				}
			}
		}
		chk[num] = 1;
		ans[i] = num;
	}
	for(long long i = 0; i < N; ++i){
		cout << ans[i] + 1 << ' ';
	}
	return 0;
}