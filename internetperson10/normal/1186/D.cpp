#include <bits/stdc++.h>

using namespace std;

vector<long long int> nums;
vector<bool> isintern;

int main() {
	int n;
	long long int ans=0;
	cin >> n;
	for(int a=0; a<n; a++) {
		double k;
		cin >> k;
		if(k==floor(k)) isintern.push_back(true);
		else isintern.push_back(false);
		long long int x = floor(k);
		nums.push_back(x);
		ans+=(x);
	}
	//for(int a=0; a<n; a++) cout << nums[a] << ' ';
	//cout << '\n';
	//for(int a=0; a<n; a++) cout << isintern[a] << ' ';
	//cout << '\n';
	ans*=-1;
	for(int a=0; a<ans; a++) {
		if(isintern[a]) {
			ans++;
			cout << nums[a] << '\n';
			continue;
		}
		cout << nums[a]+1 << '\n';
	}
	for(int a=ans; a<n; a++) cout << nums[a] << '\n';
}