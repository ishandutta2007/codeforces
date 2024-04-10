#include <bits/stdc++.h>
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

int main() {
	lol n, m, k;
	cin >> n >> m >> k;

	vector<lol> arr(m);
	for(lol &i : arr) cin >> i;

	lol l = 1, r = k;
	lol ans = 0;

	int pos = 0;

	while(pos < m){
		int num = 0;

		while(l <= arr[pos] && arr[pos] <= r){
			++num;
			++pos;
		}

		if(!num){
            if(pos >= m) break;

			l = r + 1;
			lol step = n / k;

            for(step; step > 0; step /= 2){
                while(l + (step * k) <= arr[pos]) l += step * k;
            }

            r = l + k - 1;
		}
		else{
			r += num;
			++ans;
		}
	}

	cout << ans;
}