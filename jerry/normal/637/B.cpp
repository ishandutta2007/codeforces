#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> sol;
ll all[200005];
char buf[16];
set<ll> have;
int n;

ll hsh()
{
	ll ret = 0;
	for (int i = 0;buf[i];i++)
		ret = ret * 27 + buf[i] - 'a' + 1;
	return ret;
}

void ush(ll v)
{
	int len = 0;
	for (;v;v/=27)
		buf[len++] = (v%27-1)+'a';
	reverse(buf, buf+len);
	buf[len] = 0;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
	{
		scanf("%s", buf);
		all[i] = hsh();
	}
	for (int i = n-1;i >= 0;i--) if (have.find(all[i]) == have.end())
	{
		have.insert(all[i]);
		sol.push_back(all[i]);
	}
	for (ll u: sol)
	{
		ush(u);
		printf("%s\n", buf);
	}
	return 0;
}