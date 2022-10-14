#include<iostream>

using namespace std;

string a, b, sol;
int par, cnt;

int main () {
	cin >> a >> b;
	int sl=a.size();
	for (int i=0; i<sl; i++) {
		if (a[i]==b[i]) {
			sol+='1';
		} else {
			if (par==0) {
				if (a[i]=='0') sol+='1'; else sol+='0';
			} else {
				if (b[i]=='0') sol+='1'; else sol+='0';
			}
			cnt++;
			par=!par;
		}
	}
	if (cnt%2==0) cout << sol; else cout << "impossible";
	return 0;
}