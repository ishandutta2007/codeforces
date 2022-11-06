#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int v = count(s.begin(),s.end(),'z');
	n-=4*v;
	n/=3;
	for(int i = 0; i<n; i++){
		cout << "1 ";
	}
	for(int i = 0; i<v; i++){
		cout << "0 ";
	}
	cout << "\n";
	return 0;
}