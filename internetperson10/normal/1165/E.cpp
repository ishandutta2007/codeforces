#include <bits/stdc++.h>

using namespace std;

const long long int MOD = 998244353;

long long int arr[200001];
vector<long long int> brr;

int main() {
	long long int n, ans=0;
	cin >> n;
	for(long long int a=0; a<n; a++) {
		cin >> arr[a];
		arr[a]*=((n-a)*(a+1));
	}
	for(int b=0; b<n; b++) {
		long long int c;
		cin >> c;
		brr.emplace_back(c);
	}
	sort(arr, arr+n);
	sort(brr.rbegin(), brr.rend());
	for(int a=0; a<n; a++) {
		ans+=((arr[a]%MOD)*(brr[a]%MOD));
		ans%=MOD;
	}
	cout << ans << '\n';
}