#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll x1, _y1, x[100005], y[100005], r2;
long double r1;

int main()
{
	cin.sync_with_stdio(false); cin.tie(0);
	cin >> n >> x1 >> _y1; r1 = 100000000000000.L;
	for (int i = 0;i < n;i++)
	{
		cin >> x[i] >> y[i];
		ll d = (x[i]-x1)*(x[i]-x1)+(y[i]-_y1)*(y[i]-_y1);
		r1 = min(r1, 1.L*d);
		r2 = max(r2, d);
	}
	for (int i = 0;i < n;i++)
	{
		pair<ll, ll> b(x[(i+1)%n]-x[i], y[(i+1)%n]-y[i]), a(x1-x[i], _y1-y[i]);
		ll num = a.first*b.first+a.second*b.second, den = b.first*b.first+b.second*b.second;
		if (0 < num && num < den)
		{
			long double coef = 1.*num/den;
			pair<long double, long double> A(a.first-b.first*coef, a.second-b.second*coef);
			r1 = min(r1, A.first*A.first+A.second*A.second);
		}
	}
	long double pi = acos(-1);
	cout << setprecision(15) << fixed << pi*(r2-r1) << endl;
	return 0;
}