#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int m, k;
	cin >> m >> k;
	vector<vector<int>> pos(k, vector<int>(m));
	vector<int> sum(k);
	vector<long long> sqsum(k);
	for(auto i = 0; i < k; ++ i){
		for(auto j = 0; j < m; ++ j){
			cin >> pos[i][j];
			sum[i] += pos[i][j];
			sqsum[i] += 1LL * pos[i][j] * pos[i][j];
		}
	}
	int vsum = -1;
	for(auto i = 0; i < k - 1; ++ i){
		for(auto j = i + 2; j < k - 1; ++ j){
			if(sum[i + 1] - sum[i] == sum[j + 1] - sum[j]){
				vsum = sum[i + 1] - sum[i];
				goto DONE;
			}
		}
	}
	DONE:;
	int moment = -1, delta = -1;
	for(auto i = 1; ; ++ i){
		if(sum[i] - sum[i - 1] != vsum){
			moment = i;
			delta = sum[i] - sum[i - 1] - vsum;
			break;
		}
	}
	long long vsqsum = -1;
	for(auto i = 0; ; ++ i){
		if(moment < i || i + 2 < moment){
			vsqsum = sqsum[i + 2] - 2 * sqsum[i + 1] + sqsum[i];
			break;
		}
	}
	for(auto j = 0; j < m; ++ j){
		sqsum[moment] -= 1LL * pos[moment][j] * pos[moment][j];
		sqsum[moment] += 1LL * (pos[moment][j] - delta) * (pos[moment][j] - delta);
		if(vsqsum == sqsum[moment + 1] - 2 * sqsum[moment] + sqsum[moment - 1]){
			cout << moment << " " << pos[moment][j] - delta << "\n";
			return 0;
		}
		sqsum[moment] -= 1LL * (pos[moment][j] - delta) * (pos[moment][j] - delta);
		sqsum[moment] += 1LL * pos[moment][j] * pos[moment][j];
	}
	assert(false);
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////