#include<bits/stdc++.h>
#define __int128 ll
using namespace std;
typedef long long ll;
int n, m;
ll k;
vector<int> a, b, pos;
int gcd1;
vector<vector<ll> > res;


ll _gcd(ll a, ll b)
{
	if(b == 0)
	{
		return a;
	}
	return _gcd(b, a % b);
}

ll check(ll mid)
{
	ll ans = mid + 1;
	for(int i = 0; i < res.size(); i++)
	{
		ll x0, y0, k1, k2, pos1, pos2;
		x0 = res[i][0];
		y0 = res[i][1];
		k1 = res[i][2];
		k2 = res[i][3];
		pos1 = res[i][4];
		pos2 = res[i][5];
		if((__int128)x0 * n + pos1 > mid)
		{
			continue;
		}
		ll can_max_x = (mid - pos1) / n;
		ll can_max_y = (mid - pos2) / m;
		ll can_x = (can_max_x - x0) / k1;
		ll can_y = (can_max_y - y0) / k2;
		ans -= min(can_x, can_y) + 1;
	}
	return ans;
}

ll find_sol(ll a, ll b, ll & x, ll & y) {
	if(a == 0)
	{
		x = 0; y = 1;
		return b;
	}
	ll x1, y1;
	ll d = find_sol(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

void precalc()
{
	for(int i = 0; i < n; i++)
	{
		if(pos[a[i]] == -1)
		{
			continue;
		}
		int j = pos[a[i]];
		if(abs(i - j) % gcd1 != 0)
		{
			continue;
		}
		if(i == j)
		{
			res.push_back((vector<ll>){0, 0, m / gcd1, n / gcd1, i, j});
			continue;
		}
		ll x0, y0;
		find_sol(n, m, x0, y0);
		if(j >= i)
		{
			x0 *= (j - i) / gcd1;
			y0 *= (j - i) / gcd1;
			y0 = -y0;
		}
		else
		{
			x0 *= (i - j) / gcd1;
			y0 *= (i - j) / gcd1;
			x0 = -x0;
		}
		ll k1 = m / gcd1;
		ll k2 = n / gcd1;
		if(x0 < 0)
		{
			ll amount = (abs(x0) - 1) / k1 + 1;
			x0 += (ll)k1 * amount;
			y0 += (ll)k2 * amount;
		}
		if(y0 < 0)
		{
			ll amount = (abs(y0) - 1) / k2 + 1;
			x0 += (ll)k1 * amount;
			y0 += (ll)k2 * amount;
		}
		if(x0 > 0 && y0 > 0)
		{
			ll amountx = x0 / k1;
			ll amounty = y0 / k2;
			ll amount = min(amountx, amounty);
			x0 -= amount * k1;
			y0 -= amount * k2;
		}
		res.push_back((vector<ll>){x0, y0, k1, k2, i, j});
	}
}

void print(vector<ll> res)
{
	for(int i = 0; i < res.size(); i++)
	{
		cout << res[i] << ' ';
	}
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> m >> k;
    gcd1 = _gcd(n, m);
    a.resize(n);
    b.resize(m);
    pos.assign(2 * max(n, m) + 1, -1);
    for(int i = 0; i < n; i++)
    {
    	cin >> a[i];
    }
    for(int i = 0; i < m; i++)
    {
    	cin >> b[i];
    	pos[b[i]] = i;
    }
    precalc();
    ll r = 1000000000000000001ll;
    ll l = -1;
    while(r - l > 1)
    {
    	ll mid = (l + r) / 2;
    	if(check(mid) >= k)
    	{
    		r = mid;
    	}
    	else
    	{
    		l = mid;
    	}
    }
    cout << r + 1 << endl;
    //cout << res.size();
    //cout << check(1);
    //print(res[0]);
    //print(res[1]);
    //print(res[2]);
}