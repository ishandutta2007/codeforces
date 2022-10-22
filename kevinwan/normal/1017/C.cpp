#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string a, b;
int main() {
	int n,s;
	scanf("%d", &n);
	s = sqrt(n-1)+1;
	int i, j;
	for (i = 0; i <=s+2; i++) {
		for (j = s - 1; j >= 0; j--) {
			if (i*s + j < n)printf("%d ", i*s + j + 1);
		}
	}
	getchar(); getchar();
}