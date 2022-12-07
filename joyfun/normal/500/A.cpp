#include <cstdio>
#include <cstdlib>

const int N = 30005;

int n, t, a[N];

int main() {
	scanf("%d%d", &n, &t);
	for (int i = 1; i <= n - 1; i++)
		scanf("%d", &a[i]);
	int bo = 0;
	for (int i = 1; i <= t;) {
		if (i == t) {
			bo = 1;
			break;
  		}
		i += a[i];
 	}
 	printf("%s\n", bo ? "YES" : "NO");	
	return 0;
}