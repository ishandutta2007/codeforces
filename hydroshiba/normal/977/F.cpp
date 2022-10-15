#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#include "bits/stdc++.h"
using namespace std;

const int maxn = 2e5 + 6;

//Thanks, neal!
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int n, arr[maxn], dp[maxn];
gp_hash_table<int, int, custom_hash> val;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for(int i = 0; i < n; ++i) cin >> arr[i];

	int ans = 0, pos = 0;
	for(int i = 0; i < n; ++i){
		dp[i] = max(dp[i], val[arr[i] - 1] + 1);
		if(dp[i] > ans){
			ans = dp[i];
			pos = i;
		}
		val[arr[i]] = max(val[arr[i]], dp[i]);
	}

	cout << ans << '\n';

	stack<int> s;
	s.push(pos + 1);
	int cur = arr[pos];

	for(int i = pos; i >= 0; --i) if(arr[i] == cur - 1){
		cur = arr[i];
		s.push(i + 1);
	}

	while(!s.empty()) cout << s.top() << ' ', s.pop();
}