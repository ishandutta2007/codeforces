#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, arr[101010];
bool cmp (int &a, int &b) {
	return a>b;
}
int main() {
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr+n, cmp);

	if (arr[0]>=arr[1]+arr[2]) {
		printf("NO");
		return 0;
	}

	printf("YES\n");

	for (int i=0; i<n; i+=2)
		printf("%d ", arr[i]);

	for (int i=n-1; i>=0; i--) {
        if (i%2==0) continue;
		printf("%d ", arr[i]);
	}
}