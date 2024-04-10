#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;


#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n, m;
string s;
vector<char> ans;

int main(){
	fast_io;
	
	cin >> s;
	n = s.size();
	
	for(int i = 0; i < n; i++){
		if(!ans.empty() && s[i] == ans.back()){
			ans.pop_back();
		}
		else{
			ans.push_back(s[i]);
		}
	}
	
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i];
	}
	
	return 0;
	
}