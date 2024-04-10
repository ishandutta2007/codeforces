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

const ll mod = 1e9 + 7;

void solve()
{
	string str, before_dot, after_dot;
	bool dot = false;
	cin >> str;

	for(auto chr: str)
	{
		if(chr == '.')
		{
			dot = true;
			continue;
		}

		if(dot)
			after_dot += chr;
		else
			before_dot += chr;
	}

	{
		int i = 0;

		while(i < before_dot.size() && before_dot[i] == '0')
			++i;

		before_dot = before_dot.substr(i, before_dot.size() - i);
	}

	{
		int k = 0;

		while(after_dot.size() - k - 1 >= 0 && after_dot[after_dot.size() - k - 1] == '0')
			++k;

		after_dot = after_dot.substr(0, after_dot.size() - k);
	}

	int dlt = before_dot.size() - 1;

	if(dlt == -1)
	{
		int i = 0;

		while(i < after_dot.size() && after_dot[i] == '0')
			++i;

		dlt -= i;

		after_dot = after_dot.substr(i, after_dot.size() - i);
	}

	string answer;

	for(auto chr: before_dot)
	{
		if(answer.size() == 1)
			answer += ".";

		answer += chr;
	}

	for(auto chr: after_dot)
	{
		if(answer.size() == 1)
			answer += ".";

		answer += chr;
	}

	{
		int k = 0;

		while(answer.size() - k - 1 >= 0 && (answer[answer.size() - k - 1] == '0' || answer[answer.size() - k - 1] == '.'))
			++k;

		answer = answer.substr(0, answer.size() - k);
	}
   
	if(dlt != 0)
		answer += "E" + to_string(dlt);

	cout << answer << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}