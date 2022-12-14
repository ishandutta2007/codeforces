#include <bits/stdc++.h>
#define int long long
using namespace std;

void out(int x, int y){
	cout << "? " << x << ' ' << y << '\n';
	cout.flush();
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, t; cin >> n >> t;
	int k; cin >> k;
	int low = 1, high = n;
	while(low < high){
		int mid = (low + high) >> 1;
		out(1, mid);
		int val; cin >> val;
		if(mid - val >= k){
			high = mid;
		}
		else{
			low = mid + 1;
		}
	}
	cout << "! " << low << '\n';
	cout.flush();
	return 0;
}