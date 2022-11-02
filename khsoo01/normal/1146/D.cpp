#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 100005;

ll x, a, b, ans;

bool vis[N];

ll val (ll A, ll B) {
	if(A < 0) return 0;
	ll C = 1;
	ll NA = (A % a < B ? (A/a-1)*a+B : A/a*a+B);
	C += A - NA;
	A = NA;
	if(A < 0) return 0;
	ll X = A / a + 1;
	return C * X + a * X * (X-1) / 2;
}

void solve (ll A, ll B) {
	if(vis[B]) {
		for(ll i=0;i<a;i++) {
			if(!vis[i]) ans -= val(x, i);
		}
		printf("%lld\n",ans);
		exit(0);
	}
	vis[B] = true;
	ans -= val(min(A-1, x), B);
	ll C = B;
	B -= b;
	while(B < 0) {
		B += a;
		C += a;
	}
	solve(max(A, C), B % a);
}

int main()
{
	scanf("%lld%lld%lld",&x,&a,&b);
	ans = (x+1) * (x+2) / 2;
	solve(0, 0);
}