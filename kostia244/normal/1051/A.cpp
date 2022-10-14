#include<bits/stdc++.h>
using namespace std;
const int maxn = 1<<19, mod = 1e9 + 7;
int cur(char i) {
	if(i >= 'A' && i <= 'Z') return 0;
	else if(i >= 'a' && i <= 'z') return 1;
	return 2;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int t = 0;
		vector<int> c(3);
		for(auto &i : s) c[cur(i)]++;
		for(auto &i : s) {
			if(c[cur(i)] > 1 && c[0] == 0) {
				c[cur(i)]--, c[0]++, i = 'A';
			} else if(c[cur(i)] > 1 && c[1] == 0) {
				c[cur(i)]--, c[1]++, i = 'a';
			} else if(c[cur(i)] > 1 && c[2] == 0) {
				c[cur(i)]--, c[2]++, i = '0';
			} 
		}
		cout << s << '\n';
	}
}