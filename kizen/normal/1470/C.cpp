#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, k;
	cin >> N >> k;
	int pos = 0, l, r;
	for(int i = 0; i < 1000; ++i){
		l = pos, r = (pos + i) % N;
		cout << "? " << l + 1 << '\n'; cout.flush();
		int lv; cin >> lv;
		cout << "? " << r + 1 << '\n'; cout.flush();
		int rv; cin >> rv;
		if(lv < rv && lv <= k && rv >= k){
			while(l != r){
				int mid;
				if(l < r){
					mid = (l + r) / 2;
				}
				else{
					mid = (l + r + N) / 2 % N;
				}
				cout << "? " << mid + 1 << '\n'; cout.flush();
				int val; cin >> val;
				if(val < k){
					l = (mid + 1) % N;
				}
				else if(val > k){
					r = (mid + N - 1) % N;
				}
				else{
					cout << "! " << mid + 1 << '\n'; cout.flush();
					return 0;
				}
			}
		}
		else{
			pos = (r + 1) % N;
		}
	}
	assert(0);
	return 0;
}