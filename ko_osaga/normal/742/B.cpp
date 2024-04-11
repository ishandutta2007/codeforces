#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

int n, cnt[1<<17];

int main(){
	int t;
	cin >> n >> t;
	lint ret = 0;
	for(int i=1; i<=n; i++){
		int x;
		cin >> x;
		ret += cnt[x^t];
		cnt[x]++;
	}
	cout << ret;
}