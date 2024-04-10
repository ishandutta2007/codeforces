#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

int main() {
	bool is=false;
	int n;
	cin >> n;
	for(int a=0; a<2*n; a++) {
		int c;
		cin >> c;
		if(arr.size()>0) {
			if(arr[arr.size()-1]!=c) is=true;
		}
		arr.push_back(c);
	}
	if(!is) {
		cout << "-1";
		return 0;
	}
	sort(arr.begin(), arr.end());
	for(int a=0; a<2*n; a++) {
		cout << arr[a] << ' ';
	}
}