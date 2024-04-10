#include "bits/stdc++.h"
using namespace std;

void solve(){
	string s;
	cin >> s;

	int num[3];
	for(int i = 0; i < 3; ++i) num[i] = 0;
	for(char c : s) ++num[c - 'A'];

	while(num[0] + num[1] + num[2]){
		if(num[0] && num[2] && !num[1]){
			cout << "NO\n";
			return;
		}

		if(!num[0] && !num[1] && num[2]){
			cout << "NO\n";
			return;
		}

		if(num[0] && !num[1] && !num[2]){
			cout << "NO\n";
			return;
		}

		if(!num[0] && num[1] && !num[2]){
			cout << "NO\n";
			return;
		}

		if(!num[2]) --num[0], --num[1];
		else --num[1], --num[2];
	}

	cout << "YES\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	while(t--) solve();
}