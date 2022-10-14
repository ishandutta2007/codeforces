#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 5005;

int k, n;
int l[30], moze[MAXN];
string s[MAXN], a, b;

bool ok () {
	for (int i=0; i<k; i++) {
		int cnt=0, x=-1, y=0;
		for (int j=0; j<n; j++) {
			if (s[i] [j]!=a[j]) {
				cnt++;
				if (x==-1) x=j; else y=j;
			}
		}
		if (!(cnt==0 && moze[i] || cnt==2 && s[i] [x]==a[y] && s[i] [y]==a[x])) return 0;
	}
	return 1;
}

int main () {
	cin >> k >> n;
	for (int i=0; i<k; i++) {
		cin >> s[i];
		for (int j=0; j<26; j++) {
			l[j]=0;
		}
		for (int j=0; j<n; j++) {
			l[s[i] [j]-'a']++;
		}
		for (int j=0; j<26; j++) {
			if (l[j]>1) moze[i]=1;
		}
	}
	bool naso=0;
	for (int i=0; i<k; i++) {
		for (int j=i+1; j<k; j++) {
			if (s[i]!=s[j]) {
				a=s[i];
				b=s[j];
				naso=1;
				break;
			}
		}
		if (naso) break;
	}
	if (!naso) {
		a=s[0];
		swap(a[0], a[1]);
		cout << a;
		return 0;
	}
	int cnt=0;
	for (int i=0; i<n; i++) {
		if (a[i]==b[i]) continue;
		cnt++;
		if (cnt>4) {
			cout << -1;
			return 0;
		}
		for (int j=0; j<n; j++) {
			swap(a[i], a[j]);
			if (ok()) {
				cout << a;
				return 0;
			}
			swap(a[i], a[j]);
		}
	}
	cout << -1;
	return 0;
}