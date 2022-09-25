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
	for(int i = 0; i + 1 < n; i += 1)
		if(s[i] > s[i + 1]){
			cout << "YES\n" << i + 1 << " " << i + 2;
			return 0;
		}
	cout << "NO";
	return 0;
}