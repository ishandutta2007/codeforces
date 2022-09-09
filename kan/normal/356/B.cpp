#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

typedef long long ll;

const int maxn = 1000006;

int kv1[26], kv2[26];
bool was[maxn];

string s, t;
ll n, m;

inline int gcd(int a, int b)
{
	return (b == 0 ? a : gcd(b, a % b));
}

int main()
{
	cin >> n >> m;
	cin >> s >> t;
	if (s.length() < t.length())
	{
		swap(n, m);
		swap(s, t);
	}
	ll answer = 0;
	for (int i = 0; i < (int)t.length(); i++) if (!was[i])
	{
		int cur = i;
		for (int j = 0; j < 26; j++) kv1[j] = 0;
		for (int j = 0; j < 26; j++) kv2[j] = 0;
		while (!was[cur])
		{
			was[cur] = true;
			kv1[s[cur] - 'a']++;
			if (cur < t.length()) kv2[t[cur] - 'a']++;
			cur = (cur + t.length()) % s.length();
		}
		for (int j = 0; j < 26; j++)
		{
			for (int j2 = 0; j2 < 26; j2++) if (j != j2) answer += (ll)kv1[j] * kv2[j2];
		}
	}
	answer = answer * (n * gcd(s.length(), t.length()) / t.length());
	cout << answer << endl;
	return 0;
}