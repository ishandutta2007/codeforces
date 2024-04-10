#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 998244353;
int main() {
	int y, r, b;
	scanf("%d%d%d", &y, &b, &r);
	int sm = min(y, min(b - 1, r - 2));
	printf("%d", sm * 3 + 3);
}