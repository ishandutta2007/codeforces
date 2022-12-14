#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long T;
	cin >> T;
	while(T--){
		long long N; cin >> N;
		vector<long long> a(N), val(N);
		long long zcan = 1, mn = (long long)1e9;
		for(long long i = 0; i < N; ++i){
			cin >> a[i];
			val[i] = a[i];
			if(i){
				val[i] -= val[i - 1];
			}
			if(val[i] < 0){
				zcan = 0;
				mn = min(mn, i);
			}
		}
		if(zcan && val[N - 1] == 0){
			cout << "YES\n";
			continue;
		}
		vector<long long> low(2, (long long)1e18);
		for(long long i = N - 1; i >= mn + 1; --i){
			low[i % 2] = min(low[i % 2], val[i]);
		}
		long long did = 0;
		for(long long i = min(N - 1, mn + 1); i >= 1; --i){
			low[i % 2] = min(low[i % 2], val[i]);
			if(low[0] - (a[i] - a[i - 1]) * (i % 2 ? -2 : 2) >= 0){
				if(low[1] - (a[i] - a[i - 1]) * (i % 2 ? 2 : -2) >= 0){
					if(val[i - 1] - a[i - 1] + a[i] >= 0){
						if(val[N - 1] - (a[i] - a[i - 1]) * ((N - 1 - i) % 2 ? -2 : 2) == 0){
							cout << "YES\n";
							did = 1;
							break;
						}
					}
				}
			}
		}
		if(!did){
			cout << "NO\n";
		}
	}
	return 0;
}