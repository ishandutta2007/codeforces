#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 1005;

int n;
string s[MAXN];

void Do(string str){
	bool HETTA[MAXN] = {};
	string ans;
	for(int i=0; i<2*n-2; i++){
		if(!HETTA[s[i].size()] && str.substr(0, s[i].size()) == s[i]){
			HETTA[s[i].size()] = 1;
			ans.push_back('P');
		}
		else if(str.substr(n - s[i].size(), s[i].size()) == s[i]){
			ans.push_back('S');
		}
		else return;
	}
	cout << ans << endl;
	exit(0);
}

int main(){
	cin >> n;
	string l, r;
	for(int i=0; i<2*n-2; i++){
		cin >> s[i];
		if(s[i].size() == n - 1){
			if(l.empty()) l = s[i];
			else r = s[i];
		}
	}
	Do(l + r.substr(n - 2, 1));
	Do(r + l.substr(n - 2, 1));
	assert(0);
}