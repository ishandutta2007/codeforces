#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
const int maxn = 200500;
#define se second
#define fi first
#define mp make_pair
#define pb push_back
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef double ld;
const int inf = 1e9+100500;
const ld eps = 1e-9;
typedef long long i64;

string vow = "aoeui";

int n, k;

string suf(string s)
{
	reverse(s.begin(), s.end());
	int cnt = 0;
	string res = "";
	for (int i = 0; i < (int)s.length() && cnt < k; i++)
	{
		res += s[i];
		if (vow.find(s[i]) != vow.npos)
			cnt++;
	}
	return cnt == k ? res : "-";
}

bool rhyme (string s1, string s2)
{
	s1 = suf(s1), s2 = suf(s2);
	return s1 == s2 && s1 != "-";
}

int type (string s1, string s2, string s3, string s4)
{
	int res = 0;
	if (rhyme(s1, s2) && rhyme(s3, s4))
		res |= 1;
	if (rhyme(s1, s3) && rhyme(s2, s4))
		res |= 2;
	if (rhyme(s1, s4) && rhyme(s2, s3))
		res |= 4;
	return res;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> k;
	int mask = 7;
	string s;
	getline(cin, s);
	forn(i, n)
	{
		string s1, s2, s3, s4;
		getline(cin, s1);
		getline(cin, s2);
		getline(cin, s3);
		getline(cin, s4);
		mask &= type(s1, s2, s3, s4);
	}
	if ((mask & 7) == 7)
		cout << "aaaa";
	else if ((mask & 1) == 1)
		cout << "aabb";
	else if ((mask & 2) == 2)
		cout << "abab";
	else if ((mask & 4) == 4)
		cout << "abba";
	else
		cout << "NO";
	
	return 0;
}