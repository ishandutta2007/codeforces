#include <bits/stdc++.h>

using namespace std;


int main() {
	long long n, t, mn = 1000000023;
	long long s, sum = 0;
	cin >> n >> s;
	for(int i = 0; i < n; i++) {
		cin >> t;
		sum += t;
		mn = min(mn, t);
	}
	if(sum < s)
		cout << -1;
	else if(sum - (n * mn) >= s)
		cout << mn;
	else {
		sum = s - (sum - (n * mn));
		printf("%d", int(mn - ceil((double)sum/(double)n)));
	}
}