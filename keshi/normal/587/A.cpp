#include <bits/stdc++.h>
using namespace std;
#define fast_io  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int n, cnt[1001000], a, ans;
int main(){
	fast_io;
	cin >> n;
	while(n--){
		cin >> a;
		cnt[a]++;
	}
	for(int i = 0; i < 1000100; i++){
		cnt[i + 1] += cnt[i] / 2;
		ans += cnt[i] % 2;
	}
	cout << ans;
	return 0;
}