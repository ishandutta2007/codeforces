#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << endl;
#else
#define DBG(X)
#endif
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 1e7 + 9;
const int MAX_N = 500000;

struct Seq
{
	string str;
	int cnt_end, cnt_min;
};

vector<Seq> pos[MAX_N + 1], neg[MAX_N + 1], zero;

void solve()
{
	int n;
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		Seq sq;
		cin >> sq.str;

		sq.cnt_min = INT_INF;

		int cnt = 0;

		for(int i = 0; i < sq.str.size(); ++i)
		{
			if(sq.str[i] == '(')
				++cnt;
			else
				--cnt;

			sq.cnt_min = min(sq.cnt_min, cnt);
		}

		sq.cnt_end = cnt;

		if(sq.cnt_end > 0)
		{
			if(sq.cnt_min >= 0)
				pos[sq.cnt_end].push_back(sq);
		}
		else if(sq.cnt_end < 0)
		{
			neg[-sq.cnt_end].push_back(sq);
		}
		else
		{
			if(sq.cnt_min >= 0)
				zero.push_back(sq);
		}
	}

	int answer = zero.size() / 2;

	for(int d = 1; d <= MAX_N; ++d)
	{
		if(pos[d].empty() || neg[d].empty())
			continue;

		int delta = 0;

		for(auto sq: neg[d])
			if(sq.cnt_min + d >= 0)
				++delta;

		delta = min(delta, (int)pos[d].size());
		answer += delta;
	}

	cout << answer << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}