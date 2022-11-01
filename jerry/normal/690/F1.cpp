#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(int i=(a);i<(b);i++)
#define MOD 1000000007
#define MT make_tuple
#define PB push_back
typedef long long ll;

int N, deg[10100];
ll tot;

int main (){ 
	scanf("%d", &N);
	fo(i, 0, N-1) {
		int a,b ; scanf("%d %d", &a, &b);
		a--, b--;
		tot += deg[a] + deg[b];
		deg[a]++, deg[b]++;
	}
	printf("%lld\n", tot);
	return 0;
}