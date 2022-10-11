#include <bits/stdc++.h>
using namespace std;
int n, x, y, ans;
string s;
int main(){
	cin >> n >> x >> y;
	cin >> s;
	for (int i = n - 1; i >= n - x; i--){
		if (i == n - y - 1){
			if (s[i] == '0'){
				ans++;
			}
		}
		else if(s[i] == '1'){
			ans++;
		}
	}
	cout << ans;
	return 0;
}