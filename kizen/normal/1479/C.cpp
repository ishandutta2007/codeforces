#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int l, r;
	cin >> l >> r;
	int x = 22;
	vector<vector<int>> way(33, vector<int>(33, -1));
	for(int i = 2; i <= x; ++i){
		way[1][i] = 1;
	}
	for(int i = 2; i <= x; ++i){
		for(int j = i + 1; j <= x; ++j){
			way[i][j] = (1 << (i - 2));
		}
	}
	vector<int> cnt(33);
	for(int i = 2; i <= x; ++i){
		cnt[i] = (1 << (i - 2));
	}
	while(l <= r){
		int p = x;
		while(cnt[p] > (r - l + 1)){
			--p;
		}
		if(cnt[p] < r){
			way[p][32] = r - cnt[p];
		}
		else{
			for(int i = 2; i < p; ++i){
				way[i][32] = (1 << (i - 2));
			}
			way[1][32] = 1;
		}
		r -= cnt[p];
	}
	int w = 0;
	for(int i = 1; i <= 32; ++i){
		for(int j = i; j <= 32; ++j){
			w += (way[i][j] != -1);
		}
	}
	cout << "YES\n" << 32 << ' ' << w << '\n';
	for(int i = 1; i <= 32; ++i){
		for(int j = i; j <= 32; ++j){
			if(way[i][j] != -1){
				cout << i << ' ' << j << ' ' << way[i][j] << '\n';
			}
		}
	}
	return 0;
}