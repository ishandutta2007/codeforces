#include<iostream>

using namespace std;

const int MAXN = 205;

int t, n, k;
int l[MAXN], novi[MAXN];

bool ok () {
	for (int i=1; i<=n; i++) {
		if (l[i]==0) return 0;
	}
	return 1;
}

void idi () {
	for (int i=1; i<=n; i++) {
		novi[i]=0;
	}
	for (int i=1; i<=n; i++) {
		if (l[i]==1) {
			if (i>0) novi[i-1]=1;
			if (i<n) novi[i+1]=1;
		}
	}
	for (int i=1; i<=n; i++) {
		l[i]|=novi[i];
	}
}

int main () {
	cin >> t;
	for (int tc=0; tc<t; tc++) {
		cin >> n >> k;
		for (int i=1; i<=n; i++) {
			l[i]=0;
		}
		for (int i=0; i<k; i++) {
			int x;
			cin >> x;
			l[x]=1;
		}
		int sol=1;
		while (!ok()) {
			idi();
			sol++;
		}
		cout << sol << endl;
	}
	return 0;
}