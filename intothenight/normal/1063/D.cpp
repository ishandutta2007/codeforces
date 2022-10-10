#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
mt19937 rng(steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(steady_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
ll euclid(ll a, ll b, ll &x, ll &y){
	if(b){
		ll d = euclid(b, a % b, y, x);
		return y -= a / b * x, d;
	}
	return x = 1, y = 0, a;
}
array<ll, 6> solve_linear_diophantine(ll a, ll b, ll c, ll xlow, ll xhigh, ll ylow, ll yhigh){
	ll x, y, g = euclid(abs(a), abs(b), x, y);
	array<ll, 6> no_sol{0, 0, 0, 0, 0, g};
	if(c % g) return no_sol;
	x *= c / g, y *= c / g;
	if(a < 0) x = -x;
	if(b < 0) y = -y;
	a /= g, b /= g, c /= g;
	auto shift = [&](ll &x, ll &y, ll a, ll b, ll cnt){ x += cnt * b, y -= cnt * a; };
	int sign_a = a > 0 ? 1 : -1, sign_b = b > 0 ? 1 : -1;

	shift(x, y, a, b, (xlow - x) / b);
	if(x < xlow) shift(x, y, a, b, sign_b);
	if(x > xhigh) return no_sol;
	ll lx1 = x;
	
	shift(x, y, a, b, (xhigh - x) / b);
	if(x > xhigh) shift(x, y, a, b, -sign_b);
	ll rx1 = x;

	shift(x, y, a, b, -(ylow - y) / a);
	if(y < ylow) shift(x, y, a, b, -sign_a);
	if(y > yhigh) return no_sol;
	ll lx2 = x;

	shift(x, y, a, b, -(yhigh - y) / a);
	if(y > yhigh) shift(x, y, a, b, sign_a);
	ll rx2 = x;

	if(lx2 > rx2) swap(lx2, rx2);
	ll lx = max(lx1, lx2), rx = min(rx1, rx2);
	if(lx > rx) return no_sol;
	return {(rx - lx) / abs(b) + 1, lx, (c - lx * a) / b, rx, (c - rx * a) / b, g};
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	long long n, l, r, k;
	cin >> n >> l >> r >> k;
	auto kill = [](){
		cout << -1;
		exit(0);
	};
	long long L = (r - l + 1 + n) % n;
	if(!L){
		L += n;
	}
	if(k < L){
		kill();
	}
	long long res = -1;
	if(n <= 10000){
		for(long long x = 0; x <= L; ++ x){
			for(long long y = 0; y <= n - L; ++ y){
				if(k - L >= x && (k - L - x) % (x + y + n) == 0){
					ctmax(res, x + y);
				}
			}
		}
		for(long long x = 1; x <= L; ++ x){
			for(long long y = 0; y <= n - L; ++ y){
				if(k - L + 1 >= x && (k - L + 1 - x) % (x + y + n) == 0){
					ctmax(res, x + y);
				}
			}
		}
	}
	else{
		if(k - L <= L){
			ctmax(res, k - L + n - L);
		}
		if(k - L + 1 <= L){
			ctmax(res, k - L + 1 + n - L);
		}
		for(long long m = 1; m * n <= k - L + 1; ++ m){
			if(m * n <= k - L){
				long long c = k - L - m * n;
				auto [_, lx, ly, rx, ry, __] = solve_linear_diophantine(m + 1, m, c, 0, L, 0, n - L);
				if(_) ctmax(res, max(lx + ly, rx + ry));
			}
			long long c = k - L + 1 - m * n;
			auto [_, lx, ly, rx, ry, __] = solve_linear_diophantine(m + 1, m, c, 1, L, 0, n - L);
			if(_) ctmax(res, max(lx + ly, rx + ry));
		}
	}
	cout << res;
	return 0;
}

/*
7 * 7199999 + 6 * 1 = 50399999
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////