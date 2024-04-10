#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, p, k;
	cin >> n >> p >> k;
	vector<int> a(n);
	for(auto &x: a){
		cin >> x;
	}
	vector<int> val(n);
	for(int index = 0; index < n; index ++){
		long long res = a[index];
		res = (res * res) % p;
		res = (res * res) % p;
		res = (res - (long long) k * a[index]) % p;
		if(res < 0){
			res += p;
		}
		val[index] = res;
	};
	sort(val.begin(), val.end());
	long long res = 0, cnt = 1;
	for(int i = 0; i <= n - 1; i ++){
		if(i == n - 1 || val[i] != val[i + 1]){
			res += cnt * (cnt - 1) / 2;
			cnt = 1;
		}
		else{
			cnt ++;
		}
	}
	cout << res << "\n";
	return 0;
}