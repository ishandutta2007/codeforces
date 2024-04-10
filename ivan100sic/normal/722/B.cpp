#include "bits/stdc++.h"
using namespace std;

int n;
int a[1000];
string s;

int main(){
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	getline(cin, s);
	bool ok = true;
	for (int i=0; i<n; i++){
		getline(cin, s);
		int v = 0;
		for (char x : s){
			if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'y'){
				v++;
			}
		}
		if (v != a[i]) ok = false;
	}
	cout << (ok ? "YES" : "NO") << endl;


	return 0;
}