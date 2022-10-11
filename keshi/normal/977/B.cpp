#include <bits/stdc++.h>
using namespace std;
map < pair<char, char>, int> m;
int ans, n;
string s, r;
int main(){
	cin >> n >> s;
	for(int i = 0; i < n - 1; i++){
		m[{s[i], s[i + 1]}]++;
		if(m[{s[i], s[i + 1]}] > ans){
			r = s[i];
			r += s[i + 1];
			ans = m[{s[i], s[i + 1]}];
		}
	}
	cout << r;
	return 0;
}