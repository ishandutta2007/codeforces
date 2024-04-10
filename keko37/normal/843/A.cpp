#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 100005;

int n, cnt;
int l[MAXN], s[MAXN];
pair <int, int> p[MAXN];
int bio[MAXN];
vector <int> v[MAXN];

void f (int pos) {
	if (bio[pos]) return;
	bio[pos]=1;
	v[cnt].push_back(pos+1);
	f(s[pos]);
}

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		scanf("%d", &l[i]);
		p[i]=make_pair(l[i], i);
	}
	sort(p, p+n);
	for (int i=0; i<n; i++) {
		s[p[i].second]=i;
	}
	for (int i=0; i<n; i++) {
		if (bio[i]==0) {
			cnt++;
			f(i);
		}
	}
	cout << cnt << endl;
	for (int i=1; i<=cnt; i++) {
		printf("%d ", v[i].size());
		for (int j=0; j<v[i].size(); j++) printf("%d ", v[i] [j]);
		cout << endl;
	}
	return 0;
}