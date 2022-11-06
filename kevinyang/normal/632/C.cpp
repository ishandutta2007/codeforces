#include <bits/stdc++.h>
using namespace std;
#define int long long
bool comp(string a, string b){
	if(a.length()<b.length()){
		while(a.length()<b.length()){
			a = a+a;
		}
	}
	else{
		while(b.length()<a.length()){
			b = b+b;
		}
	}
	a = a+a;
	b = b+b;
	return a<b;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<string>arr(n);
	for(int i = 0; i<n; i++){
		cin >> arr[i];
	}
	sort(arr.begin(),arr.end(),comp);
	for(string nxt: arr){
		cout << nxt;
	}
	cout << "\n";
	return 0;
}