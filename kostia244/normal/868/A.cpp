#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
int hv[256][256];
bool can(string s) {
	if(s.size()&1) return 0;
	for(int i = 1; i < s.size(); i+=2) if(!hv[s[i-1]][s[i]]) return 0;
	return 1;
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	string s;
	cin >> s;
	int n;
	cin >> n;
	char U, V;
	while(n--) {
		cin >> U >> V;
		hv[U][V] = 1;
	}
	int ok = can(s);
	for(char e = 'a'; e <= 'z'; e++)
		ok |= can(s + string(1, e));
	for(char e = 'a'; e <= 'z'; e++)
		ok |= can(string(1, e) + s);
	for(char x = 'a'; x <= 'z'; x++)
	for(char e = 'a'; e <= 'z'; e++)
		ok |= can(string(1, e) + s + string(1, x));
	cout << (ok?"YES":"NO") << endl;
}