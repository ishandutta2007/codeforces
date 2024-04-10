#include<iostream>
#include<cstdio>
#include<vector>
#include<set>

using namespace std;

const int MAXN = 100005;

int n, m, a, b, cnt;
int l[MAXN], sol[MAXN];
vector <int> v[MAXN];

set <int> s;

void f (int cvor) {
	sol[cvor]=cnt;
	cnt--;
	s.erase(-cvor);
	for (int i=0; i<v[cvor].size(); i++) {
		int sus=v[cvor] [i];
		l[sus]--;
		if (l[sus]==0) s.insert(-sus);
	}
}

int main () {
	cin >> n >> m;
	cnt=n;
	for (int i=0; i<m; i++) {
		scanf("%d%d", &a, &b);
		v[b].push_back(a);
		l[a]++;
	}
	for (int i=1; i<=n; i++) {
		if (l[i]==0) {
			s.insert(-i);
		}
	}
	for (int i=0; i<n; i++) {
		f(-(*s.begin()));
	}
	for (int i=1; i<=n; i++) {
		printf("%d ", sol[i]);
	}
	return 0;
}