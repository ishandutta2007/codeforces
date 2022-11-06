#include <bits/stdc++.h>
using namespace std;
#define int long long
int cnt(string a, string b){
	int rem = 0;
	for(int i = 0; i<a.size(); i++){
		if(a[i]!=b[i])rem++;
	}
	return rem;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		if(n%7==0){
			cout << n << "\n";
			continue;
		}
		string s2 = to_string(n);
		for(int i = 1; i<1000; i++){
			string s = to_string(i);
			if(s2.length()==s.length()&&cnt(s,s2)<=1&&i%7==0){
				cout << i << "\n";
				break;
			}
		}
	}
	return 0;
}