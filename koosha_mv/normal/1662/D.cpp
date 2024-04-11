/* Im the best and i work like that */

#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

#define F first
#define S second
#define all(x) x.begin(),x.end()
#define Mp make_pair
#define point complex
#define endl '\n'
#define SZ(x) (int)x.size()
#define fast_io ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define file_io freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define mashtali return cout << "Hello, World!", 0;

const int N = 1e6 + 10;
const int LOG = 20;
const ll mod = 1e9 + 7;
const ll inf = 8e18;
const double pi = acos(-1);
const ld eps = 1e-18;
const ld one = 1.;

ll pw(ll a, ll b, ll M, ll ret = 1) { if(a == 0) return 0; a %= M; while(b) { ret = (b & 1? ret * a % M : ret), a = a * a % M, b >>= 1; } return ret % M; }

mt19937 rng(time(nullptr));

string fir, sec;

int cnt1, cnt2, cnt;

vector < pii > calc(string s)
{
	int n = SZ(s);
	cnt = 0;
	vector < pii > A;
	for(int i = 0; i < n; i ++)
	{
		if(s[i] == 'B')
		{
			cnt ++;
			continue;
		}
		if(A.empty() || A.back().F != s[i] - 'A')
		{
			A.push_back(Mp((int)(s[i] - 'A'), 1));
		}
		else
		{
			A.pop_back();
		}
	}
	vector < pii > B;
	for(auto [a, b] : A)
	{
		if(b % 2 == 0) continue;
		B.push_back(Mp(a, b));
	}
	return B;
}

void solve()
{
	cin >> fir >> sec;
	vector < pii > A, B;
	A = calc(fir);
	cnt1 = cnt;
	B = calc(sec);
	cnt2 = cnt;
	if((cnt1 % 2) == (cnt2 % 2) && A == B)
	{
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
	return;
}

int main()
{
	fast_io;
	int q;
	cin >> q;
	while(q --)
	{
		solve();
	}	
	return 0;
}

/* check corner case(n = 1?), watch for negetive index or overflow */