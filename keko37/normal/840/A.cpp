#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

typedef pair <int, int> par;

const int MAXN = 200005;

int n;
int a[MAXN], b[MAXN], sol[MAXN];
par l[MAXN];

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i=0; i<n; i++) {
		scanf("%d", &b[i]);
		l[i]=make_pair(b[i], i);
	}
	sort(l, l+n);
	sort(a, a+n);
	reverse(a, a+n);
	for (int i=0; i<n; i++) {
		sol[l[i].second]=a[i];
	}
	for (int i=0; i<n; i++) {
		printf("%d ", sol[i]);
	}
	return 0;
}