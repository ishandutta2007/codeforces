#include <bits/stdc++.h>
using namespace std;
int n;
bool f(vector<int> a, int d){
	for(int i = 1;i < a.size();i++){
		if(a[i] - a[i - 1] != d){
			return false;
		}
	}
	return true;
}

pair<bool,int> check(vector<pair<int,int>> &a, int d) {
	vector<int> b;
	vector<int> c,c1;
	for(int i = 0;i < n;i++){
		if(i > 0){
			b.push_back(a[i].first);
		}
		if(i < n - 1){
			c.push_back(a[i].first);
		}
		if(i != 1){
			c1.push_back(a[i].first);
		}
	}
	if(f(b,d)){
		return {true,a[0].second};
	}
	if(f(c,d)){
		return {true,a[n - 1].second};
	}
	if(f(c1,d)){
		return {true,a[1].second};
	}
	int x = -1,y = -1;;
	for(int i = 1;i < n;i++){
		if(a[i].first - a[i - 1].first != d){
			x = i;
			y = i - 1;
			break;
		}
	}
	if(x == -1){
		return{true,1};
	}
	vector<int> b1,b2;
	for(int i = 0;i < n;i++){
		if(i != x){
			b1.push_back(a[i].first);
		}
		if(i != y){
			b2.push_back(a[i].first);
		}
	}
	if(f(b1,d)){
		return {true,a[x].second};
	}
	if(f(b2,d)){
		return {true,a[y].second};
	}
	return{false,-1};
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector<pair<int,int>> a(n);
	for(int i = 0;i < n;i++){
		cin >> a[i].first;
		a[i].second = i + 1;
	}
	sort(a.begin(),a.end());
	if(n <= 3) {
		cout << 1;
		return 0;
	}
	int d = a[1].first - a[0].first;
	if(check(a, d).first){
		cout << check(a, d).second;
		return 0;
	}
	d = a[2].first - a[0].first;
	if(check(a, d).first){
		cout << check(a, d).second;
		return 0;
	}
	d = a[2].first - a[1].first;
	if(check(a, d).first){
		cout << check(a, d).second;
		return 0;
	}
	
	cout << -1;
}