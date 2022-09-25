//author: Hexun
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	vector<bool> v(n, false);
	for(int i = 0, j = 0; j < (n - 11) / 2 and i < n; i += 1)
		if(s[i] != '8'){
			v[i] = true;
			j += 1;
		}
	for(int i = 0, j = 0; j < (n - 11) / 2 and i < n; i += 1)
		if(s[i] == '8' and not v[i]){
			v[i] = true;
			j += 1;
		}
	for(int i = 0; i < n; i += 1)
		if(not v[i]){
			cout << (s[i] == '8' ? "YES" : "NO");
			return 0;
		}
	return 0;
}