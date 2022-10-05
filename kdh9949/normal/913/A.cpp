#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define X first
#define Y second

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	if(n > 30) printf("%d\n", m);
	else printf("%d\n", m % (1 << n));
}