#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int n;
	cin >> n;
	vector<pair<int,int>> a;
	vector<pair<int,int>> b;
	for(int i = 0;i < n;i++){
		int x, y;
		cin >> x >> y;
		if(x > y){
			a.push_back({x, i});
		}
		else{
			b.push_back({y, i});
		}
	}
	sort(a.begin(),a.end());
	sort(b.rbegin(),b.rend());
	if(a.size() > b.size()){
		cout << a.size() << endl;
		for(int i = 0;i < a.size();i++){
			cout << a[i].second + 1 << " ";
		}
	}
	else{
		cout << b.size() << endl;
		for(int i = 0;i < b.size();i++){
			cout << b[i].second + 1 << " ";
		}
	}
	
}