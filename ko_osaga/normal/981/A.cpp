#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
using lint = long long;
using pi = pair<lint, lint>;

string s;

bool ispal(string s){
	string t = s;
	reverse(t.begin(), t.end());
	return s == t;
}

int main(){
	cin >> s;
	int ans = 0;
	for(int i=0; i<s.size(); i++){
		for(int j=i; j<s.size(); j++){
			if(!ispal(s.substr(i, j-i+1))) ans = max(ans, j-i+1);
		}
	}
	cout << ans << endl;
}