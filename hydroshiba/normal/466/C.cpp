#include "bits/stdc++.h"
using namespace std;

const int maxn = 5e5 + 6;
long long arr[maxn], num[maxn];


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	long long sum = 0, cur = 0;

	for(int i = 1; i <= n; ++i){
		cin >> arr[i];
		sum += arr[i];
	}

	if(sum % 3 != 0) return cout << 0, 0;

	for(int i = 1; i <= n; ++i){
		cur += arr[i];
		num[i] += num[i - 1];
		if(cur == sum / 3) ++num[i];
	}

	long long ans = 0;
	cur = 0;
	for(int i = n; i > 0; --i){
		cur += arr[i];
		if(cur == sum / 3) ans += num[i - 2];
	}

	cout << ans;
}