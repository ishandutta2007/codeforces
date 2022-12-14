#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	vector<pair<int, int>> a(n);
	int fx, fy, ans = 0;
	for(int i = 0; i < n; ++i){
		int x, y; cin >> x >> y;
		ans += y;
		if(!i){
			fx = x, fy = x + y;
		}
		a[i] = {x, x + y};
	}
	sort(a.begin(), a.end(), [&](pair<int, int>&x, pair<int, int>&y){return x.second < y.second;});
	int num;
	for(int i = 0; i < n; ++i){
		if(a[i] == make_pair(fx, fy)){
			num = i;
			break;
		}
	}
	vector<pair<int, int>> jump;
	for(int i = 1; i < n; ++i){
		if(a[i].first > a[i - 1].second){
			jump.push_back({a[i - 1].second, a[i].first});
		}
		while((int)jump.size() && a[i].first < jump.back().second){
			if(a[i].first <= jump.back().first){
				jump.pop_back();
			}
			else{
				jump.back().second = a[i].first;
				break;
			}
		}
	}
	for(auto&i:jump) ans += i.second - i.first;
	cout << ans;
	return 0;
}