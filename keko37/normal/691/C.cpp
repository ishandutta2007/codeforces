#include<iostream>
#include<algorithm>

using namespace std;

int n, ok=1, imat, cnt;
string s, a, b;

int main () {
	cin >> s;
	n=s.size();
	for (int i=0; i<n; i++) {
		if (s[i]=='.') {
			imat=1;
			break;
		}
	}
	for (int i=0; s[i]!='.' && i<n; i++) {
		if (!ok) {
			a+=s[i];
		} else {
			if (s[i]!='0') {
				a+=s[i];
				ok=0;
			}
		}
	}
	ok=1;
	for (int i=n-1; s[i]!='.' && i>=0; i--) {
		if (!ok) {
			b+=s[i];
		} else {
			if (s[i]!='0') {
				b+=s[i];
				ok=0;
			}
		}
	}
	reverse(b.begin(), b.end());
	if (!imat) b="";
	if (a!="") {
		int as=a.size();
		if (as==1) {
			if (b=="") {
				cout << a;
			} else {
				cout << a << "." << b;
			}
		} else {
			cout << a[0];
			cnt=0;
			for (int i=1; i<as; i++) if (a[i]!='0') cnt++;
			if (b=="") {
				if (cnt!=0) {
					cout << ".";
					for (int i=as-1; i>=1; i--) {
						if (a[i]!='0') {
							for (int j=1; j<=i; j++) cout << a[j];
							cout << "E" << as-1;
							break;
						}
					}
				} else {
					cout << "E" << as-1;
				}
			} else {
				cout << ".";
				for (int i=1; i<as; i++) cout << a[i];
				cout << b << "E" << as-1;
			}
		}
	} else {
		int bs=b.size();
		for (int i=0; i<bs; i++) {
			if (b[i]!='0') {
				cout << b[i];
				if (i!=bs-1) cout << ".";	
				for (int j=i+1; j<bs; j++) cout << b[j];
				cout << "E" << -(i+1);
				break;
			}
		}
	}
	return 0;
}