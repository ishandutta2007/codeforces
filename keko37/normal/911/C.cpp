#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>

using namespace std;

const int MAXN = 1505;

int k1, k2, k3;
int l[MAXN*MAXN];
set <int> s;

int main () {
	cin >> k1 >> k2 >> k3;
	for (int i=1; i<MAXN*MAXN; i+=k1) {
		l[i]=1;
	}
	for (int i=2; i<MAXN*MAXN; i+=k2) {
		l[i]=1;
	}
	for (int i=1; i<MAXN*MAXN; i++) {
		if (!l[i]) s.insert(i%k3);
	}
	if (s.size()<=1) {
		cout << "YES";
		return 0;
	}
	swap(k2, k3);
	memset(l, 0, sizeof l);
	s.clear();
	for (int i=1; i<MAXN*MAXN; i+=k1) {
		l[i]=1;
	}
	for (int i=2; i<MAXN*MAXN; i+=k2) {
		l[i]=1;
	}
	for (int i=1; i<MAXN*MAXN; i++) {
		if (!l[i]) s.insert(i%k3);
	}
	if (s.size()<=1) cout << "YES"; else cout << "NO";
	return 0;
}