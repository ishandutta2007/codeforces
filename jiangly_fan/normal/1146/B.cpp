#include<bits/stdc++.h>
using LL = long long;
using namespace std;
constexpr int maxn = 120000;
void no(){
	cout << ":(";
	exit(0);
}
int main(){
	ios::sync_with_stdio(false);
	string s, t;
	cin >> t;
	for(char c : t) if(c != 'a') s.push_back(c);
	if(s.size() & 1) no();
	for(int i = 0; i < s.size() / 2; i += 1)
		if(s[i] != s[i + s.size() / 2]) no();
	int a = 0;
	for(int i = 0; i < t.size() - s.size() / 2; i += 1) if(t[i] == 'a') a += 1;
	if(a != t.size() - s.size()) no();
	for(int i = 0; i < t.size() - s.size() / 2; i += 1) cout << t[i];
}