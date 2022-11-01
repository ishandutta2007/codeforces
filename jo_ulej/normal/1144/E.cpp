#include <bits/stdc++.h>
 
#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << endl;
#else
#define DBG(X)
#endif
 
using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld  = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int INT_INF = (int)(2e9);
const ll  LL_INF  = (ll)(2e18);

const ll mod = 1e9 + 7;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

using number = vector<int>;
const int BASE = 26;
int k;

number str2num(const string& s)
{
	number n;

	for(auto chr: s)
		n.push_back(chr - 'a');

	return n;
}

string num2str(const number& n)
{
	string s;

	for(auto d: n)
		s.push_back(d + 'a');

	return s;
}

number add(number a, number b)
{
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	if(a.size() > b.size())
		swap(a, b);

	while(a.size() < b.size())
		a.push_back(0);

	number ret;
	int carry = 0, sz = a.size();

	for(int i = 0; i < sz; ++i)
	{
		int sm = (a[i] + b[i] + carry);
		ret.push_back(sm % BASE);

		carry = sm / BASE;
	}

	ret.push_back(carry);

	while(ret.size() > 1 && ret.back() == 0)
		ret.pop_back();

	reverse(ret.begin(), ret.end());

	return ret;
}

number div2(number a)
{
	int sz = a.size();

	number ans(sz, 0);

	for(int i = 0; i < sz; ++i)
	{
		ans[i] += a[i] / 2;

		if(a[i] & 1)
			ans[i + 1] += BASE / 2;
	}

	for(int i = sz - 1; i >= 0; --i)
	{
		if(ans[i] >= BASE)
		{
			ans[i - 1] += ans[i] / BASE;
			ans[i] %= BASE;
		}
	}

	reverse(ans.begin(), ans.end());

	while(ans.size() > k && ans.back() == 0)
		ans.pop_back();

	while(ans.size() < k)
		ans.push_back(0);

	reverse(ans.begin(), ans.end());

	return ans;
}

void solve()
{
	string s, t;

	cin >> s >> t;

	auto a = str2num(s), b = str2num(t);
	auto c = add(a, b);

#ifdef __LOCAL
	auto oldc = c;
#endif
	c = div2(c);

#ifdef __LOCAL
	auto temp = add(c, c);
	assert(temp.size() == oldc.size());

	for(int i = 0; i < temp.size(); ++i)
		assert(temp[i] == oldc[i]);
#endif

	DBG(a); DBG(b); DBG(c);

	cout << num2str(c) << endl;
}

int main(int argc, char** argv)
{
	fast_io();

	cin >> k;

	solve();

	return 0;
}