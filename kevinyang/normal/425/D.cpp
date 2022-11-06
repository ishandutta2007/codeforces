#include <bits/stdc++.h>
using namespace std;
#define int long long
const int base = (int)1e5+5;
int f(int a, int b){
	return a*base+b;
}
int sq = 320;
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<int,int>>arr(n);
	for(int i = 0; i<n; i++){
		int x,y;
		cin >> x >> y;
		arr[i] = {x,y};
	}
	sort(arr.begin(),arr.end());
	int cur = 0;
	int ans = 0;
	unordered_set<int>s;
	unordered_set<int>s3;
	//s.rehash(n);
	vector<pair<int,int>>arr2;
	for(int i = 0; i<100005; i++){
		int x = i;
		vector<int>a;
		while(cur<n&&arr[cur].first==i){
			a.push_back({arr[cur].second});
			cur++;
		}
		sort(a.begin(),a.end());
		if(a.size()<sq){
			for(int i = 0; i<a.size(); i++){
				for(int j = i+1; j<a.size(); j++){
					int dif = a[j]-a[i];
					if(s.count(f(x-dif,a[i]))&&s.count(f(x-dif,a[j]))){
						ans++;
					}
				}
			}
		}
		else{
			for(int i = 0; i<a.size(); i++){
				arr2.push_back({a[i],x});
				s3.insert(f(x,a[i]));
			}
		}
		for(int i = 0; i<a.size(); i++){
			s.insert(f(x,a[i]));
		}
	}
	cur = n-1;
	for(int i = 100005; i>=0; i--){
		int x = i;
		vector<int>a;
		while(cur>=0&&arr[cur].first==i){
			a.push_back({arr[cur].second});
			cur--;
		}
		sort(a.begin(),a.end());
		if(a.size()<sq){
			for(int i = 0; i<a.size(); i++){
				for(int j = i+1; j<a.size(); j++){
					int dif = a[j]-a[i];
					if(s3.count(f(x+dif,a[i]))&&s3.count(f(x+dif,a[j]))){
						ans++;
					}
				}
			}
		}
	}
	unordered_set<int>s2;
	cur = 0;
	sort(arr2.begin(),arr2.end());
	for(int i = 0; i<100005; i++){
		int x = i;
		vector<int>a;
		while(cur<arr2.size()&&arr2[cur].first==i){
			a.push_back({arr2[cur].second});
			cur++;
		}
		sort(a.begin(),a.end());
		if(true){
			for(int i = 0; i<a.size(); i++){
				for(int j = i+1; j<a.size(); j++){
					int dif = a[j]-a[i];
					if(s2.count(f(x-dif,a[i]))&&s2.count(f(x-dif,a[j]))){
						ans++;
					}
				}
			}
		}
		for(int i = 0; i<a.size(); i++){
			s2.insert(f(x,a[i]));
		}
	}
	cout << ans << "\n";
	return 0;
}