#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

typedef pair<int, int> pii;
typedef long long ll;
typedef double db;

int a[4];

int main() {
	int x; scanf("%d", &x);
	a[0] = a[1] = a[2] = a[3] = -1;
	for(int i = 0; i <= 2; i ++) {
		a[(x + i) % 4] = i;
	}
	if(~ a[1]) printf("%d A\n", a[1]);
	else if(~ a[3]) printf("%d B\n", a[3]);
	else if(~ a[2]) printf("%d C\n", a[2]);
	else if(~ a[0]) printf("%d D\n", a[0]);
	return 0;
}