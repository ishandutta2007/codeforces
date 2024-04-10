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

void solve()
{
	string str;
	vector<int> arr;
	vector<bool> flag1, flag2;
	int n;

	cin >> n >> str;

	arr.resize(n);
	flag1.resize(n);
	flag2.resize(n);

	int cnt = 0;

	for(int i = 0; i < n; ++i)
	{
		if(str[i] == '(')
			++cnt;
		else
			--cnt;

		arr[i] = cnt;
	}

	flag1[n - 1] = (arr[n - 1] >= 2);
	flag2[n - 1] = (arr[n - 1] >= -2);

	for(int i = n - 2; i >= 0; --i)
		flag1[i] = (flag1[i + 1] && arr[i] >= 2);

	for(int i = n - 2; i >= 0; --i)
		flag2[i] = (flag2[i + 1] && arr[i] >= -2);

	int answ = 0;

	DBG(cnt);

	if(cnt == 2)
	{
		for(int i = 0; i < n; ++i)
		{
			if(str[i] == '(' && flag1[i])
				++answ;

			if(arr[i] < 0)
				break;
		}
	}
	else if(cnt == -2)
	{
		for(int i = 0; i < n; ++i)
		{
			if(str[i] == ')' && flag2[i])
				++answ;

			if(arr[i] < 0)
				break;
		}
	}

	cout << answ << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}