#include <bits/stdc++.h>
using namespace std;
map <string,bool> m;
int main(){
	int n;
	string s;
	cin >> n;
	while (n--){
		cin >> s;
		if (m[s]){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
			m[s]=1;
		}
	}
	return 0;
}