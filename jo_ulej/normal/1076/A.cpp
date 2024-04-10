#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;

int n;
string str;

int cmp(int k, int l)
{
	if(k < l)
	{
		return str[k + 1] <= str[k];
	}
	else
	{
		return str[l] <= str[l + 1];
	}
}

int main(int argc, char** argv)
{
	cin >> n >> str;

	int best = 0;

	for(int i = 1; i < n; ++i)
		if(cmp(i, best))
			best = i;

	string result;

	for(int i = 0; i < n; ++i)
		if(i != best)
			result += str[i];

	//cout << "r=" << result << endl;

	if(result <= str)
		cout << result << endl;
	else
		cout << str << endl;

    return 0;
}