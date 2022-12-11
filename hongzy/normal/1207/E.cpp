#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define fs first
#define sc second
#define ucin() ios :: sync_with_stdio(0)

typedef map<int, int> mii;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const int N = 1e5 + 10;

int a[110], b[110];

int main() {
	for(int i = 1; i <= 100; i ++) a[i] = b[i] = i, b[i] <<= 7;
	printf("?");
	for(int i = 1; i <= 100; i ++) printf(" %d", a[i]);
	printf("\n"); fflush(stdout);
	int x; scanf("%d", &x);
	printf("?");
	for(int i = 1; i <= 100; i ++) printf(" %d", b[i]);
	printf("\n"); fflush(stdout);
	int y; scanf("%d", &y);
	int ans = 0;
	for(int i = 0; i < 14; i ++) {
		if(i < 7) ans |= (y & (1 << i));
		else ans |= (x & (1 << i));
	}
	printf("! %d\n", ans);
	fflush(stdout);
	return 0;
}