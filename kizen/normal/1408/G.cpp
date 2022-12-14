#include <bits/stdc++.h>

using namespace std;

struct Dsu{
    long long n;
    vector<long long> pr, rk;
    Dsu(long long N):n(N){
        pr.resize(n), rk.resize(n);
        for(long long i = 0; i < n; ++i) pr[i] = i, rk[i] = 1;
    }
    inline long long get(long long x){
        return x == pr[x] ? x : pr[x] = get(pr[x]);
    }
    inline bool unite(long long x, long long y, vector<vector<long long>>&dp, vector<long long>&cnt){
        x = get(x), y = get(y);
        if(x != y){
            if(rk[x] < rk[y]) swap(x, y);
            vector<long long> now((long long)dp.size() + 1);
			long long mod = 998244353;
            for(long long i = 1; i <= rk[x]; ++i){
            	for(long long j = 1; j <= rk[y]; ++j){
            		now[i + j] = (now[i + j] + dp[x][i] * dp[y][j]) % mod;
            	}
            }
            dp[x] = now;
            pr[y] = x, rk[x] += rk[y];
            cnt[x] += cnt[y] + 1;
            if(cnt[x] == rk[x] * (rk[x] - 1) / 2){
            	dp[x][1] = 1;
            }
            return true;
        }
        return false;
    }
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long n;
	cin >> n;
	vector<pair<long long, long long>> srt(n * (n - 1) / 2);
	for(long long i = 0; i < n; ++i){
		for(long long j = 0; j < n; ++j){
			long long v; cin >> v; --v;
			if(i < j){
				srt[v] = {i, j};
			}
		}
	}
	vector<vector<long long>> dp(n, vector<long long>(n + 1));
	for(int i = 0; i < n; ++i){
		dp[i][1] = 1;
	}
	vector<long long> cnt(n);
	Dsu gr(n + 4);
	for(long long k = 0; k < n * (n - 1) / 2; ++k){
		long long x = srt[k].first, y = srt[k].second;
		if(gr.get(x) == gr.get(y)){
			++cnt[gr.get(x)];
			int r = gr.rk[gr.get(x)];
			if(cnt[gr.get(x)] == r * (r - 1) / 2){
				dp[gr.get(x)][1] = 1;
			}
			continue;
		}
		gr.unite(x, y, dp, cnt);
	}
	for(long long i = 1; i <= n; ++i){
		cout << dp[gr.get(0)][i] << ' ';
	}
	return 0;
}