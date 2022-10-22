#include <bits/stdc++.h>
#define emplace_back push_back

using namespace std;

int arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, oc=0, ec=0;
	cin >> n;
	for(int a=0; a<n; a++) {
		cin >> arr[a];
		if(arr[a]%2==1) oc++;
		else ec++;
	}
	if(oc==0 || ec==0) {
		for(int a=0; a<n; a++) cout << arr[a] << ' ';
		return 0;
	}
	sort(arr, arr+n);
	for(int a=0; a<n; a++) {
		cout << arr[a] << ' ';
	}
}