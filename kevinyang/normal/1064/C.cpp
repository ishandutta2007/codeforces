#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<char>arr(n);
	for(int i = 0; i<n; i++){
		arr[i] = s[i];
	}
	sort(arr.begin(),arr.end());
	for(int i = 0; i<n; i++){
		cout << arr[i];
	}
	return 0;
}