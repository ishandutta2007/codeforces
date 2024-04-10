#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define PI acosl(-1);
bool comp(pair<int,int>a, pair<int,int>b){
	double v1 = atan2l(a.second,a.first)*180/PI;
	double v2 = atan2l(b.second,b.first)*180/PI;
	return v1<v2;
}
double angl(pair<int,int>a){
	return atan2l(a.second,a.first)*180/PI;
}
double fix(double x){
	x+=720;
	while(x>360)x-=360;
	return x;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	map<pair<int,int>,int>hm;
	vector<pair<int,int>>arr(n);
	for(int i = 0; i<n; i++){
		int x,y;
		cin >> x >> y;
		arr[i] = {x,y};
		hm[arr[i]] = i+1;
	}
	sort(arr.begin(),arr.end(),comp);
	double mn = min(fix(angl(arr[0])-angl(arr[n-1])),abs(fix(angl(arr[0])-angl(arr[n-1]))-360));
	pair<int,int>ans = {0,n-1};
	for(int i = 0; i<n-1; i++){
		//cout << arr[i].first << " " << arr[i].second << "\n";
		double val = min(fix(angl(arr[i])-angl(arr[i+1])),abs(fix(angl(arr[i])-angl(arr[i+1]))-360));
		//cout << val << "\n";
		if(val<mn){
			mn = val;
			ans = {i,i+1};
		}
	}
	cout << hm[arr[ans.first]] << " " << hm[arr[ans.second]] << "\n";
	//cout << mn << "\n";
	return 0;
}