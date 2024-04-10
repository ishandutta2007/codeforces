#include <bits/stdc++.h>
using namespace std;
int n, a, cnt[5], b, ans;
int main(){
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> a;
		cnt[a]++;
	}
	ans = 0;
	b = min(cnt[3], cnt[1]);
	cnt[1] -= b;
	b = cnt[2] / 2;
	ans += b;
	cnt[2] -= b * 2;
	
	ans += (cnt[1] - cnt[2] * 2 + 3) / 4;
	
	cout << cnt[4] + cnt[3] + cnt[2] + ans;
	return 0;
}