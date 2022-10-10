#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<ll> a(n);
	ll res = 0;
	for(auto &x: a){
		cin >> x;
		res += x;
	}
	vector<ll> sum(n);
	sum.back() = a.back();
	for(int i = n - 2; i >= 0; i --){
		sum[i] = sum[i + 1] + a[i];
	}
	sort(sum.begin() + 1, sum.end());
	k --;
	while(k --){
		res += sum.back();
		sum.pop_back();
	}
	cout << res << "\n";
	return 0;
}