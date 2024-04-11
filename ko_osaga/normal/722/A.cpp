#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
typedef long long lint;

int v;
string s;

int main(){
	cin >> v >> s;
	int h = (s[0] - '0') * 10 + s[1] - '0';
	int m = (s[3] - '0') * 10 + s[4] - '0';
	int ret = 0;
	if(m >= 60){
		s[3] = '0';
		ret++;
	}
	if(h >= 24 && v == 24){
		s[0] = '0';
		ret++;
	}
	if(h == 0 && v == 12){
		s[0] = '1';
		ret++;
	}
	if(h > 12 && v == 12){
		s[0] = '0';
		if(s[1] == '0') s[0] = '1';
		ret++;
	}
	cout << s;
}