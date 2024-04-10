#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	array<int, 5> cnt{};
	int tot = 0;
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		tot += x;
		++ cnt[x];
	}
	if(tot == 0){
		cout << "0\n";
		return 0;
	}
	if(tot == 1 || tot == 2 || tot == 5){
		cout << "-1\n";
		return 0;
	}
	int res = min(cnt[1], cnt[2]);
	cnt[1] -= res, cnt[2] -= res, cnt[3] += res;
	if(cnt[1]){
		res += cnt[1] / 3 * 2;
		cnt[3] += cnt[1] / 3;
		cnt[1] %= 3;
		if(cnt[1] <= cnt[3]){
			res += cnt[1];
			cnt[3] -= cnt[1];
			cnt[4] += cnt[1];
			cnt[1] = 0;
		}
		else if(cnt[1] == 1){
			res += 2;
			cnt[3] = 1;
			cnt[1] = 0;
			cnt[4] -= 2;
			assert(cnt[4] >= 0);
		}
		else if(cnt[1] == 2){
			res += 2;
			cnt[3] = 1;
			cnt[1] = 0;
			cnt[4] -= 1;
			assert(cnt[4] >= 0);
		}
	}
	else if(cnt[2]){
		res += cnt[2] / 3 * 2;
		cnt[3] += cnt[2] / 3 * 2;
		cnt[2] %= 3;
		if(cnt[2] == 2){
			res += 2;
			cnt[2] = 0;
			cnt[4] += 1;
		}
		else if(cnt[2] == 1){
			if(cnt[4]){
				++ res;
				-- cnt[2];
				++ cnt[3];
				-- cnt[4];
			}
			else{
				res += 2;
				cnt[2] = 0;
				cnt[3] -= 2;
				cnt[4] += 2;
				assert(cnt[4] >= 0);
			}
		}
	}
	cout << res << "\n";
	return 0;
}

/*
7
1 1 0 2 1 1 1

0 1 2 3 4
1 5 1

0 1 2 3 4
1 4 0 1

0 1 2 3 4
1 4 0 1
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////