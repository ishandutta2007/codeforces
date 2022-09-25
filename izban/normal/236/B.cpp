#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 20;
const int inf = 1000000007;
const int mod = 1000000007;

int a, b, c;
ll ans;
int k[maxn], lp[maxn];
vector<int> pr;

void eratosfen() {
	k[1] = 1;
	for (int i = 2; i < maxn; i++) {
		if (!lp[i]) {
			ll cur = i;
			for (int j = 1; cur < maxn; j++) {
				lp[cur] = i;
				k[cur] = j + 1;
				cur *= i;
			}
			pr.push_back(i);
		}
		for (int j = 0; j < pr.size() && pr[j] < lp[i] && 1LL * i * pr[j] < maxn; j++) {
			ll cur = pr[j];
			for (int o = 1; 1LL * i * cur < maxn; o++, cur *= pr[j])
				lp[i * cur] = pr[j], k[i * cur] = k[i] * (o + 1);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    eratosfen();
	cin >> a >> b >> c;
	for (int A = 1; A <= a; A++)
		for (int B = 1; B <= b; B++)
			for (int C = 1; C <= c; C++)
				ans += k[A * B * C];
	cout << ans << endl;

	return 0;
}