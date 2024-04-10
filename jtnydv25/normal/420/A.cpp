#include <bits/stdc++.h>
using namespace std;
string valid = "AHIMOTUVWXY";
int main(){
	string s;
	cin >> s;
	int n = s.length();
	for(int i = 0; i < s.length(); i++){
		if(s[i] != s[n - 1 - i]){
			cout << "NO";
			return 0;
		}
		bool x = 0;
		for(int j = 0; j < valid.size(); j++)
			if(s[i] == valid[j])
				x = 1;
		if(!x){
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}