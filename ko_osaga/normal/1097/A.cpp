#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;

string s[6];

int main(){
	for(int i=0; i<6; i++) cin >> s[i];
	bool ok = 0;
	for(int i=1; i<6; i++){
		if(s[i][0] == s[0][0]) ok = 1;
		if(s[i][1] == s[0][1]) ok = 1;
	}
	puts(ok ? "YES" : "NO");
}