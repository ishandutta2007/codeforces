#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	int sq = sqrt(n);
	vector<int> on;
	for(int i = 1; i < n; ++i){
		if(i % sq){
			on.push_back(i);
		}
	}
	vector<int> chk(n + 1);
	for(int k = 0; k < 10000; ++k){
		int cnt = sq, now = 0;
		for(int i = 0; i < (int)on.size(); ++i){
			now += !chk[on[i]];
		}
		if(now < sq){
			break;
		}
		cout << sq << ' ';
		for(int i = 0; i < (int)on.size(); ++i){
			if(!chk[on[i]] && cnt){
				chk[on[i]] = 1;
				cout << on[i] << ' ';
				--cnt;
			}
		}
		cout << '\n';
		cout.flush();
		int x; cin >> x;
		for(int i = 0; i < sq; ++i){
			int pos = (x + i - 1) % n + 1;
			chk[pos] = 0;
		}
	}
	cout << 0 << '\n';
	cout.flush();
	return 0;
}