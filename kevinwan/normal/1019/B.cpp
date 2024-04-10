#include <algorithm>
#include<vector>
#include <functional>
#include <queue>
#include <iostream>
#define mid (l+r)/2
using namespace std;
//typedef long long ll;
int n;
int ask(int x) {
	int a,b;
	cout << "? " << x << endl;
	cin >> a;
	cout << "? " << x+n/2 << endl;
	cin >> b;
	return a - b;
}
int main() {
	scanf("%d", &n);
	if (n % 4 != 0) {
		printf("! -1"); return 0;
	}
	int l = 1, r = n / 2,ll=ask(l),rr=ask(r);
	if (ll == 0) { printf("! %d", l); return 0; }
	if (rr == 0) { printf("! %d", r); return 0; }
	while (r-l>=2) {
		int mm = ask(mid);
		if (mm == 0) { printf("! %d",mid); return 0; }
		if (ll > 0 && mm > 0 || ll < 0 && mm < 0)l = mid, ll = mm;
		else r = mid, rr = mm;
	}
	if (ask(l) == 0)printf("! %d",l);
	else if (ask(r) == 0)printf("! %d", r);
}