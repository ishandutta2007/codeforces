#include<iostream>

using namespace std;

int n;
char l[105] [105];
char p[105] [105];
int sol;

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> l[i] [j];
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			for (int k=0; k<n; k++) {
				p[j] [k]=l[j] [k];
			}
		}
		for (int j=0; j<n; j++) {
			if (p[i] [j]=='0') {
				for (int k=0; k<n; k++) {
					if (p[k] [j]=='1') p[k] [j]='0'; else p[k] [j]='1';
				}
			}
		}
		int ct=0;
		for (int j=0; j<n; j++) {
			int br=0;
			for (int k=0; k<n; k++) {
				if (p[j] [k]=='1') br++;
			}
			if (br==n) ct++;
		}
		if (ct>sol) sol=ct;
	}
	cout << sol;
	return 0;
}