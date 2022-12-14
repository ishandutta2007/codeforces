#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long T;
	cin >> T;
	const long long MOD = 683038320161ll, gop = 77279;
	while(T--){
		long long N, k;
		cin >> N >> k;
		string s;
		cin >> s;
		long long gk = 1;
		for(long long i = 0; i < k; ++i){
			gk = (gk * gop) % MOD;
		}
		long long sum = 0;
		vector<long long> srt(N - k + 1);
		for(long long i = 0; i < N; ++i){
			sum = (sum * gop) % MOD;
			sum += (s[i] == '0');
			if(i >= k){
				sum = (sum - (s[i - k] == '0') * gk + MOD) % MOD;
			}
			if(i >= k - 1){
				srt[i - k + 1] = sum;
			}
		}
		sort(srt.begin(), srt.end());
		for(long long i = 0; ; ++i){
			if(k <= 20 && i >= (1 << k)){
				cout << "NO\n";
				break;
			}
			long long val = 0, gap = 1;
			for(int j = 0; j < 21; ++j){
				val += ((i & (1 << j)) > 0) * gap; val %= MOD;
				gap *= gop; gap %= MOD;
			}
			long long pos = lower_bound(srt.begin(), srt.end(), val) - srt.begin();
			if(pos < (long long)srt.size() && srt[pos] == val){
				continue;
			}
			cout << "YES\n";
			for(long long j = k - 1; j >= 0; --j){
				if(j >= 23) cout << "0";
				else cout << ((i & (1 << j)) > 0);
			}
			cout << '\n';
			break;
		}
	}
	return 0;
}