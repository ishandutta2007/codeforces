#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int s, b;
	cin >> s >> b;
	vector<int> a(s);
	for(auto &x: a){
		cin >> x;
	}
	vector<pii> rs(b);
	for(int i = 0; i < b; i ++){
		cin >> rs[i].first >> rs[i].second;
	}
	sort(rs.begin(), rs.end());
	vector<int> sum(b);
	sum[0] = rs[0].second;
	for(int i = 1; i < b; i ++){
		sum[i] = sum[i - 1] + rs[i].second;
	}
	for(auto x: a){
		auto it = upper_bound(rs.begin(), rs.end(), pii(x, 100000)) - rs.begin() - 1;
		if(it < 0){
			cout << "0 ";
		}
		else{
			cout << sum[it] << " ";
		}
	}
	return 0;
}