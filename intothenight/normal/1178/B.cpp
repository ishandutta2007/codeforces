#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	vector<ll> temp{0};
	for(int i = 0; i < s.size(); i ++){
		if(s[i] == 'v'){
			temp.back() ++;
		}
		else{
			temp.push_back(0);
		}
	}
	vector<ll> sum(1);
	for(auto x: temp){
		if(x > 1){
			sum.push_back(sum.back() + x - 1);
		}
		else{
			sum.push_back(sum.back());
		}
	}
	ll res = 0;
	for(int i = 0, j = 0; i < s.size(); i ++){
		if(s[i] == 'o'){
			res += sum[j + 1] * (sum.back() - sum[j + 1]);
			j ++;
		}
	}
	cout << res;
	return 0;
}