#include <bits/stdc++.h>
using namespace std;
 
#define ucin ios::sync_with_stdio(0), cin.tie(0)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;
 
const int N = 5e5 + 10;
int n, c[N];
bool tag[N];
int p[N], pc;
void sieve(int n) {
	c[1] = 1;
	for(int i = 2; i <= n; i ++) {
		if(!tag[i]) p[++ pc] = i, c[i] = i;
		for(int j = 1; j <= pc && i * p[j] <= n; j ++) {
			tag[i * p[j]] = 1;
			if(i % p[j] == 0) {
				c[i * p[j]] = p[j];
				break ;
			}
			c[i * p[j]] = p[j];
		}
	}
}
int main() {
	scanf("%d", &n); sieve(n);
	for(int i = 1; i <= n; i ++) c[i] = i / c[i];
	sort(c + 1, c + n + 1);
	for(int i = 2; i <= n; i ++)
		printf("%d ", c[i]);
	return 0;
}