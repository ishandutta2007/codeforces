#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 2000005;

int main(){
	string s; cin >> s;
	int n = s.size();
	bool good = 0;
	for(int i=0; i<n/2; i++){
		if(s[0] != s[i]) good = 1;
		if(s[0] != s[n-1-i]) good = 1;
	}
	if(good == 0){
		puts("Impossible");
		return 0;
	}
	for(int i=1; i<n-1; i++){
		string l = s.substr(0, i);
		string r = s.substr(i, n - i);
		string v = r + l;
		string w = v;
		reverse(w.begin(), w.end());
		if(v == w && v != s){
			puts("1");
			return 0;
		}
	}
	puts("2");
}