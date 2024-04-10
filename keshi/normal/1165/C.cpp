#include <bits/stdc++.h>
using namespace std;
int n, ans;
string s;
int main(){
	cin >> n >> s;
	for (int i = 0; i < s.size() - 1; i += 2){
		if(s[i] == s[i + 1]){
			ans++;
			s.erase(i + 1, 1);
			i -= 2;
		}
	}
	if (s.size()%2){
		s.erase(s.size() - 1, 1);
		ans++;
	}
	cout << ans << endl << s;
	return 0;
}