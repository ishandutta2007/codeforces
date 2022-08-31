#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...) // remove in interactive
#define endl '\n'
#endif
int I, J, K;
int a[1005];
ll query(int l, int r){
	#ifdef LOCAL
	ll ret = 0;
	for(int i = l; i <= r; i++){
		for(int j = i + 1; j <= r; j++) if(a[i] > a[j]) ret++;
	}
	return ret;
	#endif
	cout << "? " << l << " " << r<< endl;
	fflush(stdout);
	ll x; cin >> x;
	return x;
}
void rev(int l, int r){
	for(int i = l; l + r - i > i; i++) swap(a[i], a[l + r - i]);
}

ll fsqrt(ll v){
	if(v < 0) return -1;
	ll t = max(0LL, (ll)sqrtl(v) - 10);
	while(t * t <= v) t++;
	return t - 1;
}

int get(ll R){
	// x ^2 - x - 2 * R = 0;
	// 1 + 8 * R;
	ll D = 1 + 8 * R;
	ll t = fsqrt(D);
	if(t * t != D) return -1;
	if(t % 2 != 1) return -1;
	return (1 + t) / 2;
}
map<int, int>  mp;

int get2(ll V, int s){
	ll R = 2 * V + s - s * 1LL * s;
	// 2 * p^ 2 - 2 * p * s - R = 0
	ll D = s * 1LL * s + 2 * R;
	ll t = fsqrt(D);
	assert(t != -1);
	assert(t <= s && (s + t) % 2 == 0);
	return (s + t ) / 2;
}

int getI(int L, int R){
	while(L < R){
		int mid = (L + R + 1) / 2;
		if(query(1, mid) == 0) L = mid;
		else R = mid - 1;
	}
	return L;
}

int getK(int L, int R, ll T){
	while(L < R){
		int mid = (L + R) / 2;
		if(query(1, mid) == T) R = mid;
		else L = mid + 1;
	}
	return L;
}
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		#ifdef LOCAL
		cin >> I >> J >> K;
		iota(a + 1, a + n + 1,1);
		rev(I, J - 1);
		rev(J, K);
		#endif
		ll T = query(1, n);
		int lo = 1, hi = n;
		int i = -1, k = -1;
		while(lo < hi){
			int mid = (lo + hi) >> 1;
			ll V = query(1, mid);
			if(V == 0){
				lo = mid;
				continue;
			}
			if(V == T){
				hi = mid;
				continue;
			}

			int h = get(V);
			i = -1;
			if(h != -1){
				i = mid - h + 1;
				if(query(1, i) != 0) i = -1;
			}
			if(i != -1){
				// got i
				k = getK(lo, hi, T);
				break;
			}
			V = query(mid, n);
			h = get(V);
			assert(h != -1);
			k = mid + h - 1;
			i = getI(lo, hi);
			break;
		}

		int s = k - i + 1;
		int L = get2(T, s);
		int l = s - L;
		if(query(1, i + L - 1) == (L * 1LL * (L - 1)) / 2){
			cout << "! " << i << " " << i + L << " " << k << endl;
		} else{
			cout << "! " << i << " " << i + l << " " << k << endl;
		}
		fflush(stdout);
	}
}