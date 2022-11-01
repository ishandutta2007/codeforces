#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

typedef long long ll;

string ans;

void gcd(ll a, ll b)
{
	char tmp[32];
	while (a && b)
	{
		if (a > b)
		{
			sprintf(tmp, "%lld", b!=1?a/b:(a-1));
			ans.append(tmp);
			ans.push_back('A');
			a %= b;
		} else
		{
			sprintf(tmp, "%lld", a!=1?b/a:(b-1));
			ans.append(tmp);
			ans.push_back('B');
			b %= a;
		}
	}
	if (a+b != 1)
	{
		printf("Impossible\n");
		exit(0);
	}
}

int main()
{
	ll a, b;
	cin >> a >> b;
	gcd(a, b);
	cout << ans << endl;
	return 0;
}