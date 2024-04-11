#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<lint, int>;
const int MAXN = 100005;
const int mod = 1e9 + 7;

int n, m;
string s1, s2;

int main(){
	cin >> n >> m;
	cin >> s1 >> s2;
	int idx = -1;
	for(int i=0; i<n; i++){
		if(s1[i] == '*') idx = i;
	}
	if(idx == -1){
		puts(s1 == s2 ? "YES" : "NO");
		return 0;
	}
	int rem = m - (n - 1);
	if(rem < 0){
		puts("NO");
		return 0;
	}
	s1 = s1.substr(0, idx) + s2.substr(idx, rem) + s1.substr(idx + 1, n - idx - 1);
	puts(s1 == s2 ? "YES" : "NO");
	return 0;
}