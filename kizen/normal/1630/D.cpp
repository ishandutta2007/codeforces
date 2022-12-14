#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		for(int i = 0; i < n; ++i){
			cin >> a[i];
		}
		vector<int> b(m);
		for(int i = 0; i < m; ++i){
			cin >> b[i];
		}
		for(int i = 1; i < m; ++i){
			b[0] = __gcd(b[0], b[i]);
		}
		int zsum = 0, osum = 0;
		for(int i = 0; i < b[0]; ++i){
			vector<int> srt;
			int sum = 0;
			for(int j = i; j < n; j += b[0]){
				srt.push_back(a[j]);
				sum += a[j];
			}
			sort(srt.begin(), srt.end());
			int zadd = sum;
			int now = sum;
			for(int j = 0; j + 1 < (int)srt.size(); j += 2){
				now -= (srt[j] + srt[j + 1]) * 2;
				ma(zadd, now);
			}
			int oadd = sum - srt[0] * 2;
			now = sum - srt[0] * 2;
			for(int j = 1; j + 1 < (int)srt.size(); j += 2){
				now -= (srt[j] + srt[j + 1]) * 2;
				ma(oadd, now);
			}
			zsum += zadd, osum += oadd;
		}
		cout << max(zsum, osum) << '\n';
	}
	return 0;
}