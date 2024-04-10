#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<string> s(3);
	for(auto &x: s){
		cin >> x;
	}
	sort(s.begin(), s.end(), [](string s1, string s2){
		if(s1[1] != s2[1]){
			return s1[1] < s2[1];
		}
		else{
			return s1[0] < s2[0];
		}
	});
	if(s[0] == s[1] && s[1] == s[2] || s[0][1] == s[1][1] && s[1][1] == s[2][1] && s[2][0] - s[1][0] == 1 && s[1][0] - s[0][0] == 1){
		cout << 0;
	}
	else if(s[0][1] == s[1][1] && (s[1][0] - s[0][0] == 2 || s[1][0] - s[0][0] == 1 || s[1][0] == s[0][0]) || s[1][1] == s[2][1] && (s[2][0] - s[1][0] == 2 || s[2][0] - s[1][0] == 1 || s[2][0] == s[1][0])){
		cout << 1;
	}
	else{
		cout << 2;
	}
	return 0;
}