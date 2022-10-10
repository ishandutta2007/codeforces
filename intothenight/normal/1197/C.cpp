#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(auto &x: a){
		cin >> x;
	}
	vector<int> d(n);
	adjacent_difference(a.begin(), a.end(), d.begin());
	sort(d.begin() + 1, d.end(), greater<int>());
	cout << a.back() - a.front() - accumulate(d.begin() + 1, d.begin() + k, 0);
	return 0;
}