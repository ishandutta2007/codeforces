#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<int> v;
int main() {
	int n, s,i,j,x,q,p;
	q = p = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &s);
		for (j = 0; j < s; j++) {
			scanf("%d", &x);
			if (j<s/2)q += x;
			else if (j * 2 == s-1)v.push_back(x);
			else p += x;
		}
	}
	sort(v.begin(), v.end());
	for (i = 0; i < v.size(); i++) {
		if (i % 2 == 0)q += v[v.size() - 1 - i];
		else p += v[v.size() - 1 - i];
	}
	printf("%d %d", q, p);
}