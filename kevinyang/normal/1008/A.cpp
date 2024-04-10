#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	bool f = true;
	int n = s.length();
	s = s+"b";
	for(int i = 0; i<n; i++){
		if(s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u'&&s[i]!='n'){
			if(s[i+1]!='a'&&s[i+1]!='e'&&s[i+1]!='i'&&s[i+1]!='o'&&s[i+1]!='u'){
				f = false;
			}
		}
	}
	if(f){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
	return 0;
}