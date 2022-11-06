#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>arr(n);
	vector<int>arr2(n);
	for(int i = 0; i<n; i++){
		cin >> arr[i];
		arr2[i] = arr[i]*10000 + i;
	}
	sort(arr2.begin(), arr2.end());
	reverse(arr2.begin(), arr2.end());
	long long total = 0;
	vector<int>ans(n);
	for(int i = 0; i<n; i++){
		total+=i*(arr2[i]/10000) + 1;
		ans[i] = arr2[i]%10000;
	}
	cout << total << "\n";
	for(int i = 0; i<n; i++){
		cout << ans[i]+1 << " ";
	}
	return 0;
}