#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI acosl(-1)
#define double long double
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int h,m,s,t1,t2;
	cin >> h >> m >> s >> t1 >> t2;
	vector<pair<double,int>>arr;
	if(m!=0||s!=0){
		double v = h/12.0;
		v+=1.0/24;
		if(v>=1)v-=1;
		arr.push_back({v,0});
	}
	else{
		double v = h/12.0;
		if(v>=1)v-=1;
		arr.push_back({v,0});
	}
	if(s!=0){
		double v = m/60.0;
		v+=0.01;
		if(v>=1)v-=1;
		arr.push_back({v,0});
	}
	else{
		double v = m/60.0;
		if(v>=1)v-=1;
		arr.push_back({v,0});
	}
	if(true){
		double v = s/60.0;
		if(v>=1)v-=1;
		arr.push_back({v,0});
		v = t1/12.0;
		if(v>=1)v-=1;
		arr.push_back({v,1});
		v = t2/12.0;
		if(v>=1)v-=1;
		arr.push_back({v,1});
	}
	sort(arr.begin(),arr.end());
	bool f = false;
	for(int i = 0; i<4; i++){
		if(arr[i].second==1&&arr[i+1].second==1)f = true;
	}
	if(arr[0].second==1&&arr[4].second==1)f = true;
	if(f)cout << "YES\n";
	else cout << "NO\n";
	return 0;
}