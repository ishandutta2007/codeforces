#include <bits/stdc++.h>
using namespace std;
string s;
char m;
bool k;
int main(){
	cin >> s;
	m = '0';
	for (int i=0; i<s.size(); i++){
		m = max(m, s[i]);
	}
	cout << m << endl;
	for (char i = '0'; i < m; i++){
		k = 0;
		for (int j = 0; j < s.size(); j++){
			if (s[j] > i){
				cout << 1;
				k = 1;
			}
			else if (k){
				cout << 0;
			}
		}
		cout << ' ';
	}
	return 0;
}