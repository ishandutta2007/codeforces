#include <bits/stdc++.h>
using namespace std;

int main() {
	set<int> s;
	int n,i,x;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &x);
		if(x!=0)s.insert(x);
	}
	printf("%d", s.size());
	getchar(); getchar();
}