#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, a[N];
map<int,int> mp;

long long ans;

struct segtree {
	int v[4*N], l;
	void init () {
		for(l=1;l<=n;l<<=1);
		for(int i=1;i<=n;i++) v[i+l] = a[i];
		for(int i=l;--i;) v[i] = v[2*i] | v[2*i+1];
	}
	int lb (int I) {
		int B = l + I;
		while(B&(B+1)) {
			if((a[I] & v[B]) != v[B]) break;
			else B = (B-1)/2;
		}
		if((B&(B+1)) == 0) return 0;
		while(B<l) {
			if((a[I] & v[2*B+1]) != v[2*B+1]) B = 2*B+1;
			else B = 2*B;
		}
		return B - l;
	}
	int rb (int I) {
		int B = l + I;
		while(B&(B-1)) {
			if((a[I] & v[B]) != v[B]) break;
			else B = (B+1)/2;
		}
		if((B&(B-1)) == 0) return n+1;
		while(B<l) {
			if((a[I] & v[2*B]) != v[2*B]) B = 2*B;
			else B = 2*B+1;
		}
		return B - l;
	}
} seg;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	seg.init();
	ans = 1ll * n * (n+1) / 2;
	for(int i=1;i<=n;i++) {
		ans -= 1ll * (i - max(seg.lb(i), mp[a[i]])) * (seg.rb(i) - i);
		mp[a[i]] = i;
	}
	printf("%lld\n",ans);
}