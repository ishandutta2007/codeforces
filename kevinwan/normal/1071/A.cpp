#include<bits/stdc++.h>
using namespace std;
bool u[100000];
vector<int> aa, bb;
int main() {
	long long n, m,ind=1;
	scanf("%lld%lld", &n, &m);
	int ans = sqrt((n + m) * 2 + 0.25) - 0.5;
	for (int i = ans; i; i--) {
		if (n >= i)aa.push_back(i),n-=i;
		else bb.push_back(i);
	}
	printf("%d\n", aa.size());
	for (int x : aa)printf("%d ", x);
	printf("\n%d\n", bb.size());
	for (int x : bb)printf("%d ", x);
}