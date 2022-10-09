#include "bits/stdc++.h"
using namespace std;

string s;

int main(){
	int n;
	cin >> n;
	cin >> s;
	int x = 0;
	for (int i=0; i<n; i++){
		if (s[i] == '<'){
			x++;
		} else {
			break;
		}
	}
	for (int i=n-1; i>=0; i--){
		if (s[i] == '>'){
			x++;
		} else {
			break;
		}
	}
	
	cout << x << endl;
	return 0;
}