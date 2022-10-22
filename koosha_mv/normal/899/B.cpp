#include <bits/stdc++.h>
 
using namespace std;
int n, x;
string a = "181010110101181010110101181010110101191010110101181010110101181010110101", b = "";
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		b += (char) x % 10 + 48;
	}
	a.find(b) == -1 ? printf("No") : printf("Yes");
	return 0;
}