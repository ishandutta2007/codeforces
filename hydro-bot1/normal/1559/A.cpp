// Hydro submission #6330160e602142f9026a280c@1664095759019
#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;
int a[N];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		
		int &num = a[1];
		for (int i = 2; i <= n; i++) {
			num &= a[i];
		}
		printf("%d\n", num);
	} 
	return 0;
}