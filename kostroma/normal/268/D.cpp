#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <set>
#include <map>
#include <cassert>
#include <memory.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();
void precalc();
#define FILENAME "change me please"
int main(){
	string s = FILENAME;
#ifdef room210
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//cout<<FILENAME<<endl;
	//assert (s != "change me please");
	clock_t start = clock();
#else
	//freopen(FILENAME ".in", "r", stdin);
	//freopen(FILENAME".out", "w", stdout);
#endif
	//cout.sync_with_stdio(0);
	int t = 1;
	//precalc();
	//cout << "done!\n";
	//cin >> t;
	//gen();
	while (t--)
		solve();
#ifdef room210
	cout<<"\n\n\n"<<(clock() - start) / 1.0 / CLOCKS_PER_SEC<<"\n\n\n";
#endif
	return 0;
}

#define int li

int n, H;
int mod = 1e9 + 9;
int dp[2][2][32][32][32];

void solve(){
	cin >> n >> H;
	dp[0][0][0][0][0] = 1;
	int w = 0;
	for (int i = 0; i < n; ++i) {
		int v[4];
		for (int j = 0; j < 2; ++j)
			for (v[1] = 0; v[1] <= 31; ++v[1])
				for (v[2] = v[1]; v[2] <= 31; ++v[2]) 
					for (v[3] = v[2]; v[3] <= 31; ++v[3])
						dp[w ^ 1][j][v[1]][v[2]][v[3]] = 0;
		v[0] = 0;
		for (v[1] = 0; v[1] <= 31; ++v[1])
			for (v[2] = v[1]; v[2] <= 31; ++v[2]) 
				for (v[3] = v[2]; v[3] <= 31; ++v[3]){
					int h[4];
					for (int j = 0; j < 4; ++j) 
						if (v[j] < H){
							h[j] = 0;
							for (int w = 0; w < 4; ++w)
								if (w != j) {
									h[w] = v[w] + 1;
									if (h[w] > H)
										h[w] = 31;
								}
							sort(h, h + 4);
							dp[w ^ 1][0][h[1]][h[2]][h[3]] += dp[w][0][v[1]][v[2]][v[3]];
							dp[w ^ 1][0][h[1]][h[2]][h[3]] %= mod;
						}
						else {
							h[j] = 0;
							for (int w = 0; w < 4; ++w)
								if (w != j) {
									h[w] = v[w] + 1;
									if (h[w] > H)
										h[w] = 31;
								}
							sort(h, h + 4);
							dp[w ^ 1][1][h[1]][h[2]][h[3]] += dp[w][0][v[1]][v[2]][v[3]];
							dp[w ^ 1][1][h[1]][h[2]][h[3]] %= mod;
						}
				}


		v[0] = 31;
		for (v[1] = 0; v[1] <= 31; ++v[1])
			for (v[2] = v[1]; v[2] <= 31; ++v[2]) 
				for (v[3] = v[2]; v[3] <= 31; ++v[3]){
					int h[4];
					for (int j = 0; j < 4; ++j) 
						if (v[j] < H){
							h[j] = 0;
							for (int w = 0; w < 4; ++w)
								if (w != j) {
									h[w] = v[w] + 1;
									if (h[w] > H)
										h[w] = 31;
								}
							sort(h, h + 4);
							dp[w ^ 1][0][h[1]][h[2]][h[3]] += dp[w][1][v[1]][v[2]][v[3]];
							dp[w ^ 1][0][h[1]][h[2]][h[3]] %= mod;
						}
						else {
							h[j] = 0;
							for (int w = 0; w < 4; ++w)
								if (w != j) {
									h[w] = v[w] + 1;
									if (h[w] > H)
										h[w] = 31;
								}
							sort(h, h + 4);
							dp[w ^ 1][1][h[1]][h[2]][h[3]] += dp[w][1][v[1]][v[2]][v[3]];
							dp[w ^ 1][1][h[1]][h[2]][h[3]] %= mod;
						}
				}
		w ^= 1;
	}
	int ans = 0;
	int v[4];
	for (v[1] = 0; v[1] <= 31; ++v[1])
		for (v[2] = v[1]; v[2] <= 31; ++v[2]) 
			for (v[3] = v[2]; v[3] <= 31; ++v[3]) {
				if (v[1] < H || v[2] < H || v[3] < H)
					ans += dp[w][1][v[1]][v[2]][v[3]];
				ans += dp[w][0][v[1]][v[2]][v[3]];
				ans %= mod;
			}
	cout << ans;	
}