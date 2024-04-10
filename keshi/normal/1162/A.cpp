#include <bits/stdc++.h>
using namespace std;
int n, m, l, r, x, h, H[100];
long long ans;

int main(){
	cin >> n >> h >> m;
	fill(H, H + 100, h);
	while (m--){
		cin >> l >> r >> x;
		for(; l <= r; l++){
			H[l] = min(H[l], x);
		}
	}
	for(int i = 1; i <= n; i++){
		ans += H[i] * H[i];
	}
	cout << ans;
}