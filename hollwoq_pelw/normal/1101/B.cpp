#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int n=s.length(), l1=-1, l2=-1, r1=-1, r2=-1;
	for (int i = 0; i < n; i++){
	    if (l1 == -1){
	        if (s[i] == '[') l1 = i;
	    }else{
	        if (l2 == -1 && s[i] == ':') l2 = i;
	    }
	    if (r1 == -1){
	        if (s[n-i-1] == ']') r1 = n-i-1;
	    }else{
	        if (r2 == -1 && s[n-i-1] == ':') r2 = n-i-1;
	    }
	}
	//cout << l1 << ' ' << l2 << ' ' << r2 << ' ' << r1;
	if (l2 == -1 || r2 == -1 || l2 >= r2) return cout << -1, 0;
	int ans = 4;
	for (int i = l2+1; i < r2; i++){
	    if (s[i] == '|') ans ++;
	}
	cout << ans;
}