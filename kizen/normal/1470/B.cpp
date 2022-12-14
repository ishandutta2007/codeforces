#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<long long> zeg((long long)1e6 + 4);
	for(long long i = 1; i <= 1000; ++i){
		zeg[i * i] = 1;
	}
	long long T;
	cin >> T;
	while(T--){
		long long N;
		cin >> N;
		vector<long long> a(N);
		for(long long i = 0; i < N; ++i){
			cin >> a[i];
		}
		for(long long i = 0; i < N; ++i){
			for(long long j = 1; j <= 100; ++j){
				while(1){
					if(a[i] % j == 0){
						long long val = a[i] / j;
						if(val > 1 && zeg[val]){
							a[i] = j;
						}
						else if(j > 1 && val % j == 0){
							a[i] /= j * j;
						}
						else{
							break;
						}
					}
					else{
						break;
					}
				}
			}
		}
		sort(a.begin(), a.end());
		long long mxz = 0, mxo = 0, cnt = 0;
		for(long long i = 0; i < N; ++i){
			++cnt;
			if(i == N - 1 || a[i] < a[i + 1]){
				mxz = max(mxz, cnt);
				if(cnt % 2 == 0 || a[i] == 1){
					mxo += cnt;
				}
				cnt = 0;
			}
		}
		long long Q; cin >> Q;
		while(Q--){
			long long w; cin >> w;
			if(!w){
				cout << mxz << '\n';
			}
			else{
				cout << max(mxo, mxz) << '\n';
			}
		}
	}
	return 0;
}