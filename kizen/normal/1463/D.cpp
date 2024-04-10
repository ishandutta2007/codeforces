#include <bits/stdc++.h>

using namespace std;

using LL = long long;
const int MOD = (int)1e9 + 7;
const int NS = (int)4e5 + 4;
int T, N;
int a[NS];
int cnt[NS][3];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while(T--){
		cin >> N;
		cnt[0][1] = cnt[0][2] = cnt[N * 2 + 1][1] = cnt[N * 2 + 1][2] = 0;
		for(int i = 1; i <= N * 2; ++i){
			cnt[i][1] = cnt[i][2] = 1;
		}
		for(int i = 1; i <= N; ++i){
			cin >> a[i];
			--cnt[a[i]][1], --cnt[a[i]][2];
		}
		for(int i = 1; i <= N * 2; ++i){
			cnt[i][1] += cnt[i - 1][1];
		}
		for(int i = N * 2; i >= 1; --i){
			cnt[i][2] += cnt[i + 1][2];
		}
		int l = 0, low = MOD;
		for(int i = 1; i <= N; ++i){
			low = min(low, i + cnt[a[i]][2] - 1);
			if(low < i){
				break;
			}
			l = i;
		}
		int r = N + 1, big = -MOD;
		for(int i = N; i >= 1; --i){
			big = max(big, i - cnt[a[i]][1] + 1);
			if(i < big){
				break;
			}
			r = i;
		}
		cout << max(0, l - r + 2) << '\n';
	}
	return 0;
}