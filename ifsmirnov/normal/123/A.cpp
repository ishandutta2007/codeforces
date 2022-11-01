#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <algorithm>
#include <vector>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
#define fi first
#define se second
#define mp make_pair

bool prime (int x)
{
	for (int i = 2; i*i <= x; i++)
		if (x%i == 0)
			return false;
	return true;
}
int n;
string s;
int b[1010];
int cnt[256];
int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> s;
	n = s.length();
	forn(i, n)
		cnt[s[i]]++;
	
	if (n <= 2)
	{
		cout << "YES\n" << s;
		return 0;
	}
	fore(i, 2, n-1) if (prime(i))
	{
		if (i * 2 <= n)
		{
			for (int j = 1; i * j <= n; j++)
				b[i*j] = 1;
		}
	}
	int ones = count(b+1, b+n+1, 1);
	string res = "";
	forn(i, 256)
		if (cnt[i] >= ones)
		{
			res.resize(n);
			forn(j, n)
				if (b[j+1])
					res[j] = i;
			cnt[i] -= ones;
			break;
		}
	if (res == "")
	{
		cout << "NO";
		return 0;
	}
	string t;
	forn(i, 256)
		t += string(cnt[i], i);
	int pos = 0;
	forn(i, n) if (res[i] == 0)
		res[i] = t[pos++];
	cout << "YES\n" << res;
	return 0;
}