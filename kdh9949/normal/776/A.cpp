#include <bits/stdc++.h>
using namespace std;

string a, b;
int n;

int main(){
	cin >> a >> b >> n;
	cout << a << ' ' << b << endl;
	for(int i = 0; i < n; i++){
		string c, d; cin >> c >> d;
		if(c == a) a = d;
		else b = d;
		cout << a << ' ' << b << endl;
	}
	return 0;
}