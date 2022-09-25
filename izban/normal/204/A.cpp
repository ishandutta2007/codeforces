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


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

int gcd(int a, int b) {
	while (b) b^=a^=b^=a%=b;
	return a;
}

const int maxn=100100;

ll ans;

bool check(ll x) {
	int last=x%10LL;
	while (x>=10LL) x/=10LL;
	int perv=x;
	return last==perv;
}

map<ll,bool> check1;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll l,r;
	cin >> l >> r;
	ll L=l, R=r;
	while (L%10!=0) L++;
	while (R%10!=0) R--;

	if (L<=R) ans+=(R-L)/10;
	for (ll i=l; i<=L; i++) if (l<=i && i<=r) { ans+=check(i); check1[i]=true; }
	for (ll i=r; i>=R; i--) if (l<=i && i<=r && !check1[i]) ans+=check(i);

	cout << ans;

	return 0;
}