#include <bits/stdc++.h>
using namespace std;
#define ll long long
int t, n;
string s;
int main(){
	cin >> t;
	bool f;
	while (t--){
		cin >> n >> s;
		if (n < 11){
			cout << "NO";
		}
		else{
			f = 0;
			for (int i=0; i <= n - 11; i++){
				if (s[i]=='8'){
					f = 1;
				}
			}
			if (f){
				cout << "YES";
			}
			else{
				cout << "NO";
			}
		}
		cout << endl;
	}
	return 0;
}