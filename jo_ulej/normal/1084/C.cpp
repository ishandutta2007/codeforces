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

const ll mod = 1e9 + 7;

vector<ll> boxes, dp;

void solve()
{
	string str;
	cin >> str;

	boxes.push_back(0);

	for(int i = 0; i < str.size(); ++i)
	{
		if(str[i] == 'a')
		{
			++boxes[boxes.size() - 1];
		}
		else if(str[i] == 'b')
		{
			if(boxes.back() != 0)
				boxes.push_back(0);
		}
	}

	//for(auto el: boxes)
		//cout << el << " ";

	cout << endl;

	dp.resize(boxes.size());

	dp[0] = boxes[0];

	for(int i = 1; i < boxes.size(); ++i)
		dp[i] = (dp[i - 1] + (dp[i - 1] * boxes[i]) % mod + boxes[i]) % mod;

	cout << dp[boxes.size() - 1] << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

    return 0;
}