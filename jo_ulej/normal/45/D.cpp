#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << endl;
#else
#define DBG(X)
#endif
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

const int T = 666;

struct Seg
{
	int l, r, idx, len;
};

bool cmp2(const Seg& lhs, const Seg& rhs)
{
	if(lhs.len != rhs.len)
		return lhs.len < rhs.len;

	if(lhs.l != rhs.l)
		return lhs.l < rhs.l;

	return lhs.r < rhs.r;
}

void solve()
{
	int n;
	cin >> n;

	vector<Seg> segs(n);

	for(auto& el: segs)
		cin >> el.l >> el.r;

	for(int i = 0; i < n; ++i)
		segs[i].idx = i, segs[i].len = segs[i].r - segs[i].l + 1;

	sort(segs.begin(), segs.end(), cmp2);

	vector<int> st;

	for(int i = 0; i < n;)
	{
		bool found = false;
		int x;

		for(int j = 0; j < T; ++j)
		{
			x = randint(segs[i].l, segs[i].r);

			bool used = false;

			for(auto y: st)
				used |= (x == y);

			if(!used)
			{
				found = true;
				break;
			}
		}

		if(!found)
		{
			st.pop_back();
			--i;
		}
		else
		{
			st.push_back(x);
			++i;
		}
	}

	vector<int> ans(n);

	for(int i = 0; i < n; ++i)
		ans[segs[i].idx] = st[i];

	for(auto el: ans)
		cout << el << " ";

	cout << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}