#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int L = (1<<19), N = 200005;

int n, b[N];
ll a[N];

struct segtree {
	ll v[2*L];
	void upd (int P, int V) {
		P += L;
		while(P) {
			v[P] += V;
			P /= 2;
		}
	}
	int kth (ll K) {
		int P = 1;
		while(P < L) {
			if(v[2*P] < K) {
				K -= v[2*P];
				P = 2*P+1;
			}
			else P = 2*P;
		}
		return P - L;
	}
} seg;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		seg.upd(i, i);
	}
	for(int i=n;i>=1;i--) {
		int I = seg.kth(a[i] + 1);
		b[i] = I;
		seg.upd(I, -I);
	}
	for(int i=1;i<=n;i++) {
		printf("%d ",b[i]);
	}
	puts("");
}