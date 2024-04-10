#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pb push_back

string s, a;
int main(){
	int n;
	cin >> s >> n;
	string ans = "NO";
	bool p = 0, q = 0;
	for(int i = 1; i <= n; i++){
		cin >> a;
		if(a[1] == s[0]) p = 1;
		if(a[0] == s[1]) q = 1;
		if(a == s) ans = "YES";
		if(p && q) ans = "YES";
	}
	cout << ans;
}