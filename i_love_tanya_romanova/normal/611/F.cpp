/*
Mother told me, yes, she told me I'd meet girls like you
She also told me, "Stay away, you'll never know what you'll catch"
Just the other day I heard a soldier falling off
Some Indonesian junk that's going round

Mommy's alright, daddy's alright, they just seem a little weird
Surrender, surrender, but don't give yourself away, ay, ay, ay

Father says, "Your mother's right, she's really up on things
Before we married, mommy served in the WACS in the Philippines"
Now, I had heard the WACS recruited old maids for the war
But mommy isn't one of those, I've known her all these years

Mommy's alright, daddy's alright, they just seem a little weird
Surrender, surrender, but don't give yourself away, ay, ay, ay

Whatever happened to all this season's losers of the year?
Every time I got to thinking, where'd they disappear?
When I woke up, mom and dad are rolling on the couch
Rolling numbers, rock and rolling, got my Kiss records out

Mommy's alright, daddy's alright, they just seem a little weird
Surrender, surrender, but don't give yourself away, ay, ay, ay

Away, away

Mommy's alright, daddy's alright, they just seem a little weird
Surrender, surrender, but don't give yourself away, ay, ay, ay

Mommy's alright, daddy's alright, they just seem a little weird
Surrender, surrender, but don't give yourself away, ay, ay, ay

Mommy's alright, daddy's alright, they just seem a little weird
Surrender, surrender, but don't give yourself away, ay, ay, ay

Mommy's alright, daddy's alright, they just seem a little weird
Surrender, surrender, but don't give yourself away, ay, ay, ay

Mommy's alright, daddy's alright, they just seem a little weird
Surrender, surrender, but don't give yourself away, ay, ay, ay

Mommy's alright, daddy's alright, they just seem a little weird
Surrender, surrender, but don't give yourself away, ay, ay, ay

Mommy's alright, daddy's alright, they just seem a little weird
Surrender, surrender, but don't give yourself away, ay, ay, ay
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

const int N = 550050;

using namespace std;

long long L, n, m;
string st;
long long qr, qc;
long long escape_row[N], escape_col[N];
vector<long long> suf_er[N], suf_ec[N], pref_er[N], pref_ec[N];
long long DR, DC;
vector<long long> v1, v2;

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("C:/input.txt","r",stdin);
	//freopen("C:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> L;
	cin >> n >> m;

	qr = qc = 0;
	cin >> st;

	for (int i = 1; i <= n; i++)
		escape_row[i] = 1e18;
	for (int i = 1; i <= m; i++)
		escape_col[i] = 1e18;

	for (int i = 0; i < st.size(); i++)
	{
		if (st[i] == 'U')
			--qr;
		if (st[i] == 'D')
			++qr;
		if (st[i] == 'L')
			--qc;
		if (st[i] == 'R')
			++qc;
		if (qc>0)
			suf_ec[m - qc + 1].push_back(i+1);
		if (qc < 0)
			pref_ec[-qc].push_back(i+1);
		if (qr>0)
			suf_er[n - qr + 1].push_back(i+1);
		if (qr < 0)
			pref_er[-qr].push_back(i+1);
	}

	DR = qr;
	DC = qc;

	long long val;
	val = 1e18;

	// escape col
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < suf_ec[i].size(); j++)
		{
			val = min(val, suf_ec[i][j]);
		}
		escape_col[i] = min(escape_col[i], val);
	}
	val = 1e18;
	for (int i = m; i; --i)
	{
		for (int j = 0; j < pref_ec[i].size(); j++)
		{
			val = min(val, pref_ec[i][j]);
		}
		escape_col[i] = min(escape_col[i], val);
	}

	// escape row
	val = 1e18;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < suf_er[i].size(); j++)
		{
			val = min(val, suf_er[i][j]);
		}
		escape_row[i] = min(escape_row[i], val);
	}

	val = 1e18;
	for (int i = n; i; --i)
	{
		for (int j = 0; j < pref_er[i].size(); j++)
		{
			val = min(val, pref_er[i][j]);
		}
		escape_row[i] = min(escape_row[i], val);
	}

	// cycles, R

	if (DR>0)
	{
		for (int i = n; i; i--)
		{
			if (i + DR<=n)
				escape_row[i] = min(escape_row[i], escape_row[i + DR] + L);
		}
	}
	if (DR < 0)
	{
		for (int i = 1; i<=n; ++i)
		{
			if (i + DR >=1)
			{
				escape_row[i] = min(escape_row[i], escape_row[i + DR] + L);
			}
		}
	}
	//cycles, C
	if (DC > 0)
	{
		for (int i = m; i; i--)
		{
			if (i + DC <=m)
				escape_col[i] = min(escape_col[i], escape_col[i + DC] + L);
		}
	}
	if (DC < 0)
	{
		for (int i = 1; i<=m; ++i)
		{
			if (i + DC >=1)
				escape_col[i] = min(escape_col[i], escape_col[i + DC] + L);
		}
	}

	long long ans = 0;


	// debug
	/*
	for (int i = 1; i <= n; i++)
	{
		cout << escape_row[i] << " ";
	}
	cout << endl;
	for (int i = 1; i <= m; i++)
	{
		cout << escape_col[i] << " ";
	}
	cout << endl;
	*/
	// brute
	/*
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			ans += min(escape_row[i], escape_col[j]);
		}
	}
	*/

	int safe_row = 0;
	int safe_col = 0;

	for (int i = 1; i <= n; i++)
	{
		if (escape_row[i] > 1e17)
		{
			safe_row = 1;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		if (escape_col[i] > 1e17)
		{
			safe_col = 1;
		}
	}

	if (safe_row&&safe_col)
	{
		cout << -1 << endl;
		return 0;
	}

	for (int i = 1; i <= m; i++)
	{
		v1.push_back(escape_col[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		v2.push_back(escape_row[i]);
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	long long below = 0;
	long long below_sum = 0;
	/*
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << " ";
	}
	cout << endl;
	*/
	for (int i = 0; i < v2.size(); i++)
	{
		while (below < v1.size() && v1[below] <= v2[i])
		{
			below_sum += v1[below];
			below++;
			below_sum %= bs;
		}
		ans += below_sum;
		long long above = v1.size() - below;
		ans += 1ll * above*v2[i];
		ans %= bs;
//		cout << ans << "%" << above << " " << below_sum <<" "<<below<< endl;
	}

	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}