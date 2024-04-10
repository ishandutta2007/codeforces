#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	int s = 0;
	for(auto &x: a){
		cin >> x;
		s += x;
	}
	vector<int> res{1};
	int temp = a[0];
	for(int i = 1; i < n; i ++){
		if(a[0] >= a[i] << 1){
			res.push_back(i + 1);
			temp += a[i];
		}
	}
	if(s / 2 < temp){
		cout << res.size() << "\n";
		for(auto x: res){
			cout << x << " ";
		}
	}
	else{
		cout << 0;
	}
	return 0;
}