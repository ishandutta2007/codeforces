#include <bits/stdc++.h>
#define int long long
using namespace std;

main() {
	int n, t;
	string s;
	cin >> n >> t;
	cin >> s;
	int l = 0;
	int maxi = 0;
	int tek = 0;
	for (int r = 0; r < n; r++){
		if (r != 0){
			if (s[r-1] != 'a'){
				tek--;
			}
		}
		while(l < n && (tek < t || s[l] == 'a')){
			if (s[l] != 'a'){
				tek++;
			}
			l++;
		}
		maxi = max(maxi, l - r);
	}
	
	l = 0;
	tek = 0;
	for (int r = 0; r < n; r++){
		if (r != 0){
			if (s[r-1] != 'b'){
				tek--;
			}
		}
		while(l < n && (tek < t || s[l] == 'b')){
			if (s[l] != 'b'){
				tek++;
			}
			l++;
		}
		maxi = max(maxi, l - r);
	}
	cout << maxi;
}