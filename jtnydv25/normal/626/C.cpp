#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	int lo = 1, hi = 1e9;

	while(lo < hi){
		int mid = (lo + hi) >> 1;
		int x = mid / 2, y = mid / 3, z = mid / 6;
		x = x - z, y = y - z;
		// x + k >= n
		// y + z - k >= m
		// k >= n - x
		// k <= y + z - m
		// k <= z
		if(max(0, n - x) <= min(z, y + z - m)){
			hi = mid;
		}
		else lo = mid + 1;
	}
	cout << lo;
}