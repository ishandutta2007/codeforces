#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,k;
	cin >> n >> k;
	vector<int>arr(n);
	for(int i = 0; i<n; i++){
		cin >> arr[i];
	}
	int total = arr[n-1]-arr[0];
	vector<int>dif(n-1);
	for(int i = 0; i<n-1; i++){
		dif[i] = arr[i+1]-arr[i];
	}
	sort(dif.begin(), dif.end());
	reverse(dif.begin(), dif.end());
	for(int i = 0; i<k-1; i++){
		total-=dif[i];
	}
	cout << total << "\n";
	return 0;
}