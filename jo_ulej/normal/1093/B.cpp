#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;

int main(int argc, char** argv)
{
	int t;
	cin >> t;

	for(int i = 0; i < t; ++i)
	{
		string str;
		cin >> str;

		bool eq = true;

		for(int i = 0; i < str.size() - 1; ++i)
			eq &= (str[i] == str[i + 1]);

		sort(str.begin(), str.end());

		if(!eq)
			cout << str << endl;
		else
			cout << "-1" << endl;
	}

    return 0;
}