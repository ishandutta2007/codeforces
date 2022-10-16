#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using pii = pair<int, int>;
#define dbg(x) cerr<<#x": "<<(x)<<'\n'
#define dbg_v(x, n) {cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<(x)[_]<<' ';cerr<<'\n';}
#define all(v) v.begin(), v.end()
#define ST_SIZE 1048600
#define QMAX 400010
#define NMAX 3010

ll f, t, t0, a1, t1, p1, a2, t2, p2;
ll INF;

ll ineq(ll u, ll v)
{
	// solves u * x >= v
	
	if(v % u == 0) return v / u;
	return v / u + 1;
}

ll solveXY(ll x, ll y)
{
	if(a1 * x + a2 * y <= f)
	{
		if(a1 * x * t1 + a2 * y * t2 + (f - a1 * x - a2 * y) * t0 <= t)
			return x * p1 + y * p2;
		
		return INF;
	}
	
	ll diff = a1 * x + a2 * y - f;
	ll mytime = a1 * x * t1 + a2 * y * t2;
	
	if(t1 < t2)
	{
		if(y > 0) mytime -= diff * t2;
		else mytime -= diff * t1;
	}
	else
	{
		if(x > 0) mytime -= diff * t1;
		else mytime -= diff * t2;
	}
	
	return mytime <= t ? x * p1 + y * p2 : INF;
}

ll solveX(ll x)
{
	// x whole packages 1
	
	ll y;
	
	if((f - a1 * x) * t0 + a1 * t1 * x - t < 0)
		return x * p1;
	
	y = ineq(a2 * (t0 - t2), (f - a1 * x) * t0 + a1 * t1 * x - t);
	
	ll p1 = solveXY(x, y);
	ll p2 = solveXY(x, y + 1);
	
	return min(p1, p2);
}

ll solveY(ll y)
{
	// y whole packages 2
	
	ll x;
	
	if((f - a2 * y) * t0 + a2 * t2 * y - t < 0)
		return y * p2;
	
	x = ineq(a1 * (t0 - t1), (f - a2 * y) * t0 + a2 * t2 * y - t);
	
	ll p1 = solveXY(x, y);
	ll p2 = solveXY(x + 1, y);
	
	return min(p1, p2);
}

void write(ll ans)
{
	cout << (ans == INF ? -1 : ans) << '\n';
}

int main()
{
	ll minx, maxx, miny, maxy, pmin, p, x, y;
	
	cin >> f >> t >> t0;
	cin >> a1 >> t1 >> p1;
	cin >> a2 >> t2 >> p2;
	
	INF = 10000000LL * 10000000LL + 69;
	
	if(f * t0 <= t) return cout << 0 << '\n', 0;
	
	if(t0 - t2 <= 0 && t0 - t1 <= 0) return cout << -1 << '\n', 0;
	
	if(t0 - t2 <= 0)
	{
		write(solveY(0));
		return 0;
	}
	
	if(t0 - t1 <= 0)
	{
		write(solveX(0));		
		return 0;
	}
	
	pmin = INF;
	for(x = 0; a1 * x <= f; ++x)
	{
		p = solveX(x);
		if(p < pmin) pmin = p;
	}
	
	for(y = 0; a2 * y <= f; ++y)
	{
		p = solveY(y);
		if(p < pmin) pmin = p;
	}
	
	write(pmin);
	
	return 0;
}