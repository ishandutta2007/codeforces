#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define N 1000005

using namespace std;

typedef long long ll;

int a[N], b[N];
ll sa[N], sb[N];
int n;
pair<int,int> s[N];

pair<int,int> residue(ll x) {
	int i = lower_bound(sa, sa+n+1, x+1) - sa;
	i--;
	return make_pair(x-sa[i],i);
}

bool rev;

void go(int al, int ar, int bl, int br) {
	if (al > ar) swap(al,ar);
	if (bl > br) swap(bl,br);
	if (rev) {
		swap(al,bl);
		swap(ar,br);
	}

	printf("%d\n", ar-al);
	FO(i,al,ar) printf("%d ", i+1);
	printf("\n");

	printf("%d\n", br-bl);
	FO(i,bl,br) printf("%d ", i+1);
	printf("\n");
}

int main() {
	scanf("%d", &n);
	FO(i,0,n) scanf("%d", a+i);
	FO(i,0,n) scanf("%d", b+i);
	FO(i,0,n) {
		sa[i+1] = sa[i] + a[i];
		sb[i+1] = sb[i] + b[i];
	}
	if (sa[n] < sb[n]) {
		rev = true;
		FO(i,0,n+1) swap(a[i],b[i]), swap(sa[i],sb[i]);
	}
	FO(i,1,n+1) {
		auto p = residue(sb[i]);
		if (p.first == 0) {
			go(0,p.second,0,i);
			return 0;
		} else {
			if (s[p.first].second) {
				go(s[p.first].first,p.second, s[p.first].second,i);
				return 0;
			}
			s[p.first] = make_pair(p.second, i);
		}
	}
}