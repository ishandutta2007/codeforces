#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
set <int> s;
int main(){
	int n, k, a, b, c, d; sd(n); sd(k); sd(a); sd(b); sd(c); sd(d);
	if(n == 4){
		printf("-1");
		return 0;
	}
	int mn = n + 1;
	if(k < mn){
		printf("-1");
		return 0;
	}
	for(int i = 1; i <= n; i++) s.insert(i);
	s.erase(a); s.erase(b); s.erase(c); s.erase(d);
	printf("%d %d ", a, c);
	int v1 = *s.begin(), v2 = *s.rbegin();
	for(int x : s) printf("%d ", x);
	printf("%d %d ", d, b);
	printf("\n");
	printf("%d %d ", c, a);
	for(int x : s) printf("%d ", x);
	printf("%d %d", b, d);
}