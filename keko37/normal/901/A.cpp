#include<iostream>
#include<cstdio>

using namespace std;

const int MAXN = 200005;

int h, ok=1, pos, curr;
int l[MAXN];

int main () {
	cin >> h;
	for (int i=0; i<=h; i++) {
		scanf("%d", &l[i]);
	}
	if (l[0]!=1) ok=0;
	for (int i=0; i<h; i++) {
		if (l[i]>1 && l[i+1]>1) {
			ok=0;
			pos=i;
		}
	}
	if (ok) {
		cout << "perfect";
		return 0;
	}
	cout << "ambiguous" << endl;
	cout << "0 ";
	curr=1;
	for (int i=1; i<=h; i++) {
		for (int j=1; j<=l[i]; j++) {
			cout << curr << " ";
		}
		curr+=l[i];
	}
	cout << endl << "0 ";
	curr=1;
	for (int i=1; i<=h; i++) {
		for (int j=1; j<=l[i]; j++) {
			if (pos+1==i && j==1) {
				cout << curr-1 << " ";
			} else {
				cout << curr << " ";
			}
		}
		curr+=l[i];
	}
	return 0;
}