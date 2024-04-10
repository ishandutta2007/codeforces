#include <bits/stdc++.h>

#define dbg(x) //cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) 	//do{cerr<<#x"[]: ";for(ll _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define ll unsigned long long 
#define DMAX 100100
#define NMAX 1
#define MMAX 1

using namespace std;

ll n, x, k, t[DMAX], use[DMAX], m, a, d, ans, nr;
string s;
int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> a >> d;
	int dbgg = 0;
	if(d == 1000000000000000000)
		dbgg = 1;

	for(ll i = 1; i <= m; i++)
		cin >> t[i];

	ll last_closed = 0;
	ll nr = d / a + 1;
	ll ok = 1;

	for(ll i = 1; i <= m; i++)
	{
		if(ok)
		{
			ll first_open = ((last_closed + a) / a) * a;
			
			if(first_open <= t[i])
			{
				ll lst_open_index = t[i] - first_open;
				lst_open_index /= nr * a;
				ll last_open = first_open + lst_open_index * nr * a;
				if(last_open >= n * a)
				{
					ok = 0;
					lst_open_index = n * a - first_open;
					lst_open_index /= nr * a;
					last_open = first_open + lst_open_index * nr * a;
				}
				if(last_open >= first_open)
				{
					lst_open_index = (last_open - first_open) / (nr * a);
					ans += lst_open_index + 1;
					last_closed = last_open + d;
				}
	  		dbg(i);
				dbg(t[i]);
				dbg(lst_open_index);
				dbg(first_open);
				dbg(last_open);
			}
		}
		if(last_closed < t[i]) 
		{
			ans++;
			last_closed = t[i] + d;
		}
		dbg(last_closed);
		dbg(ans);
	}
	/*
	if(dbgg)
	{
		cout << ans << '\n';
		return 0;
	}*/
	if(ok) {
		ll first_open = ((last_closed + a) / a) * a;
		if(n * a >= first_open)
		{
			ll cnt = (n * a - first_open) / a + 1;
			if(cnt > 0)
				ans += cnt / nr + 1 - (cnt % nr == 0);
		}
		/*
		ll lst_open_index = n * a - first_open;
		lst_open_index /= nr * a;
		ll last_open = first_open + lst_open_index * nr * a;
		//ll last_open = n * a;
		if(first_open <= last_open)
		{
			ll lst_open_index = (last_open - first_open) / (nr * a);
			dbg(first_open);
			dbg(last_open);
			ans += lst_open_index + 1;
			last_closed = last_open + d;				
		}
		*/
	}
	cout << ans << '\n';
}