#include <bits/stdc++.h>

#define dbg(x) //cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) //do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 100100;
int n, k, b, d, a[N], s1[N], s2[N];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> d >> b;
	if(d == n - 1) {
		cout << 0;
		return 0;
	}
	int sum = 0;
	for(int i = 1; i <= n; i++)
		cin >> a[i], s1[i] = a[i], s2[i] = a[i];
	for(int i = 1; i<= n; i++)
		s1[i] += s1[i - 1];

	for(int i = n; i > 0; i--)
		s2[i] += s2[i + 1];
	// dbg_ok;
	int l = 1, r = n, ll = 1, rr = n, i = 1;
	int ansl = 0, ansr = 0;
	while(l + 1 < r) {
		ll = min(ll, r);
		rr = max(rr, l + 1);
		ll = max(l, ll);
		rr = min(r, rr);

		// left
		int limit = min(l + 1LL * d * i, 1LL * n);
		if(1LL * s1[limit] >= 1LL * (l - ansl) * b){
			if(ll == l) ll++;
			while(a[l] < b && 1LL * ll - l <= 1LL * d * i && ll <= r) {
				int x = min(b - a[l], a[ll]);
				a[l] += x;
				a[ll] -= x;
				if(!a[ll])
					ll++;	
				else break;
			}

			if(a[l] > b) {
				a[l + 1] += a[l] - b;
				a[l] = b;
			} else if(a[l] != b){
				ansl++;
				a[l + 1] += a[l];
				a[l] = 0;
			}
		}
		else {
			dbg("else");
			a[l + 1] += a[l];
			a[l] = 0;
			ansl++;
		}
		dbg(l);
		dbg(ll);
		dbg(r);
		/// right

		limit = max(1LL * r - 1LL * d * i, 1LL);

		if(1LL * s2[limit] >= 1LL * (1LL * n - r + 1 - ansr) * b) {
			if(rr == r) rr--;
			while(a[r] < b && 1LL * r - rr <= 1LL * d * i && rr > l) {
				int x = min(b - a[r], a[rr]);
				a[r]+= x;
				a[rr] -= x;
				if(!a[rr])
					rr--;
				else break;
			}
			if(a[r] > b) {
				a[r - 1] += a[r] - b;
				a[r] = b;
			} else if(a[r] != b) {
				ansr++;
				a[r - 1] += a[r];
				a[r] = 0;
			}
		} else {
			dbg("else");
			a[r - 1] += a[r];
			a[r] = 0;
			ansr++;
		}

		i++;
		l++;
		r--;
	}

	// ansl = 0, ansr = 0;
	// for(int j = 1; j < i; j++) {
	// 	ansl += (a[j] == 0);
	// 	ansr += (a[n - j + 1] == 0);
	// }
	dbg_v(a, n + 1);
	if(l == r) {
		if(a[l] < b) ansl++;
	} else {
		if(a[l] + a[r] < b) ansl++, ansr++;
		else if(a[l] + a[r] < 2 * b && ansl == ansr) ansl++; 
	}
	cout << max(ansl, ansr) << '\n';
}