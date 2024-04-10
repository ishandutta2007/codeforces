#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ld eps = 1e-5;
ld get_res(ld p, ld m, ld v)
{
	ld res = 0;
	ld p1 = 0;
	if(p >= 0)
	{
		p1 = p;
	}
	ld m1 = 0;
	if(m >= 0)
	{
		m1 = m;
	}
	ld c1 = (ld)1 - p1 - m1;
	res += c1;
	if(m > 0)
	{
		ld mnew = m - v;
		ld minus = m - max((ld)0, mnew);
		ld pnew = p;
		if(p > eps)
		{
			pnew += minus / 2;
		}
		res += m * (1 + get_res(pnew, mnew, v));
	}
	if(p > 0)
	{
		ld pnew = p - v;
		ld minus = p - max((ld)0, pnew);
		ld mnew = m;
		if(m > eps)
		{
			mnew += minus / 2;
		}
		res += p * (1 + get_res(pnew, mnew, v));
	}
	return res;
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
    int t;
    cin >> t;
    while(t--)
    {
    	ld c, m, p, v;
    	cin >> c >> m >> p >> v;
    	cout << fixed << setprecision(10) << get_res(c, m, v) << '\n';
    }
}