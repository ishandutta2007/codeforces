#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long t;
	cin >> t;
	while(t--){
		long long n; cin >> n;
		vector<long long> a(n), to(n);
		for(long long i = 0; i < n; ++i){
			cin >> a[i];
		}
		auto upd = [&](){
			long long lst = -1;
			for(long long i = n - 1; i >= 0; --i){
				if(a[i] == 1){
					if(lst == -1){
						lst = i + 1;
					}
					to[i] = lst;
				}
				else{
					lst = -1;
				}
			}
		};
		upd();
		long long ans = 0;
		for(long long i = 0; i < n; ++i){
			if(a[i] >= 5005){
				ans += a[i] - 5005;
				a[i] = 5005;
			}
			while(a[i] > 1){
				++ans;
				long long pos = i;
				while(pos < n){
					if(a[pos] == 1){
						pos = to[pos];
					}
					else{
						--a[pos];
						if(a[pos] == 1){
							upd();
						}
						pos += a[pos] + 1;
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}