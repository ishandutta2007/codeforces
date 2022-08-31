#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e6;
#define vll vector<ll>
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define pll pair<ll,ll>
vll vec;
pair<ll,ll> ans[maxn];
int _ans[maxn];
ll floor_cb(ll n)
{
	ll a = (ll)cbrt(n);
	a = max(0LL,a-100);
	while(a*a*a<=n)
		a++;
	a--;
	return a;
}

ll findval(ll n)
{
	if(n == 1)
		return 1;
	ll a = floor_cb(n);
	return 1 + findval(n- a*a*a);
}
pair<ll,ll> answer(ll m)
{
	if(m<maxn)
		return ans[m];
	ll a = floor_cb(m);
	pll ret;
	ret.F = 0;
	int ind = 0;
	while((m-a*a*a <= 3*a*a+3*a) && a>=1)
	{
		pll x = answer(min(m-a*a*a,3*a*a+3*a));
		if(x.F + 1 > ret.F||(x.F+1==ret.F && x.S+a*a*a >= ret.S))
		{
			ret.F = x.F+1;
			ret.S = x.S+a*a*a;
		}
		a--;
	}
	pll x = answer(min(m-a*a*a,3*a*a+3*a));
	if(a>=1 && (x.F + 1 > ret.F||(x.F+1==ret.F && x.S+a*a*a >= ret.S)))
	{
		ret.F = x.F+1;
		ret.S = x.S+a*a*a;
	}
	return ret;
}

int main()
{
	for(int i = 1;(i-1)*(i-1)*(i-1)<=maxn;i++)
		vec.pb(i*i*i);
	_ans[0] = 0;
	ans[0].F = 0;
	ans[0].S = 0;
	ll mx = 0;
	int ind = 0;
	for(int i = 0;i<vec.size()-1 ;i++)
	{
		ll cb = vec[i];
		for(int j = vec[i];j<vec[i+1] && j<maxn;j++)
		{
			ll k = _ans[j-cb]+1;
			_ans[j] = k;
			if(k >= mx)
			{
				mx = k;	
				ind = j;
			}
			ans[j].F = mx;
			ans[j].S = ind;
		}
	}
	ll m;
	cin>>m;
	pll x = answer(m);
	// cout<<findval(x.S)<<endl;
	cout<<x.F<<" "<<x.S<<endl;
}