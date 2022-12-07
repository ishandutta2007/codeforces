#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

ll l, r, ans[10];
int k, an = 0;

void build() {
    if (k == 1) ans[an++] = l;
    else if (k == 2) {
	if (r - l + 1 == 2) {
	    if (l < (l^r)) ans[an++] = l;
	    else {ans[an++] = l; ans[an++] = r;}
	}
	else {
	    if (l%2) l++;
	    ans[an++] = l; ans[an++] = l + 1;
	}
    }
    else if (k == 3) {
	ll p = 1;
	while (p <= l) p *= 2;
	p /= 2;
	if (3 * p <= r) {
	    ans[an++] = l;
	    ans[an++] = l + p;
	    ans[an++] = 3 * p;
	}
	else {
	    if (l%2) l++;
	    ans[an++] = l;
	    ans[an++] = l + 1;
	}
    }
    else if (k == 4) {
	if (r - l + 1 > 4) {
	    if (l % 2) l++;
	    for (an = 0; an < 4; an++)
		ans[an] = l + an;
	}
	else {
	    ll Min = l;
	    ans[an++] = l;
	    for (int i = 1; i < 16; i++) {
		ll sum = 0;
		for (int j = 0; j < 4; j++) {
		    if (i&(1<<j)) sum ^= (l + j);
		}
		if (sum < Min) {
		    Min = sum;
		    an = 0;
		    for (int j = 0; j < 4; j++) {
			if (i&(1<<j))
			    ans[an++] = (l + j);
		    }
		}
	    }
	}
    }
    else {
	if (l % 2) l++;
	for (an = 0; an < 4; an++)
	    ans[an] = l + an;
    }
}

int main() {
    scanf("%lld%lld%d", &l, &r, &k);
    build();
    ll sum = 0;
    for (int i = 0; i < an; i++)
	sum ^= ans[i];
    printf("%lld\n", sum);
    printf("%d\n", an);
    for (int i = 0; i < an - 1; i++)
	printf("%lld ", ans[i]);
    printf("%lld\n", ans[an - 1]);
    return 0;
}