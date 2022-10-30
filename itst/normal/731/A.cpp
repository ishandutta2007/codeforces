#include<bits/stdc++.h>
using namespace std;

inline int abs(int a){
	return a < 0 ? -a : a;
}

int main(){
	string s;
	cin >> s;
	s = "a" + s;
	int ans = 0;
	for(int i = 0 ; i < s.size() - 1 ; i++)
		ans += min(abs(s[i + 1] - s[i]) , 26 - abs(s[i + 1] - s[i]));
	cout << ans;
	return 0;
}