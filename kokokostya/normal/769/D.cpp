#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:16777216")

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>	
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <algorithm>
#include <stack>
#include <complex>

using namespace std;

const int MX = 10001;
const int VAL = (1 << 14) + 10;

int main() {
	//freopen("integral.in", "r", stdin);
	//freopen("integral.out", "w", stdout);
	iostream::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	bool dp[VAL];
	for (int i = 0; i < VAL; i++){
		int now = i;
		int cnt = 0;
		while (now){
			if (now & 1)
				cnt++;
			now >>= 1;
		}
		if (cnt == k)
			dp[i] = 1;
		else
			dp[i] = 0;
	}
	vector<int> a(n);
	int am[MX];
	for (int i = 0; i < MX; i++)
		am[i] = 0;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		am[a[i]]++;
	}
	long long ans = 0;
	if (k == 0){
		for (int i = 0; i < MX; i++){
			ans += (am[i] * 1ll * (am[i] - 1)) / 2;
		}
	}
	else{
		for (int i = 0; i < MX; i++){
			for (int j = i + 1; j < MX; j++){
				if (dp[i ^ j]){
					ans += am[i] * 1ll * am[j];
				}
			}
		}
	}
	cout << ans;
	return 0;
}