#include <bits/stdc++.h>
using namespace std;
#define int long long
int sq = 1000;
int base = (int)1e9;
bool comp(pair<int,int>x, pair<int,int>y){
	pair<int,int>a = x;
	a.second/=base;
	pair<int,int>b = y;
	b.second/=base;
	if(a.first/sq!=b.first/sq){
		return a.first<b.first;
	}
	if((a.first/sq)%2==1){
		if(a.second/sq!=b.second/sq){
			return a.second > b.second;
		}
		else{
			return a<b;
		}
	}
	else{
		if(a.second/sq!=b.second/sq){
			return a.second < b.second;
		}
		else{
			return a<b;
		}
	}
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<int,int>>arr(n);
	for(int i = 0; i<n; i++){
		int x,y;
		cin >> x >> y;
		arr[i] = {x,y*(int)1e9+i};
	}
	//cerr << "nae\n";
	sort(arr.begin(),arr.end(),comp);
	//cerr << "nae\n";
	for(int i = 0; i<n; i++){
		cout << arr[i].second%base+1 << " ";
	}
	cout << "\n";
	return 0;
}