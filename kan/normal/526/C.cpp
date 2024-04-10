#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

#define pb push_back
#define all(x) begin(x), end(x)

const ll T = 1000;

ll c, wa, wb, ha, hb;
ll add;

void brute(bool go = false)
{
	ll answer = 0;
	if (wa > T || go)
	{
		for (int i = 0; wa * i <= c; i++)
		{
			answer = max(answer, ha * i + ((c - wa * i) / wb) * hb);
		}
		cout << answer + add << endl;
		exit(0);
	}
}

int main()
{
	cin >> c >> ha >> hb >> wa >> wb;
	add = 0;
	brute();
	ll gcd = wa * wb;
	ll best = max(wa * hb, wb * ha);
	ll answer = 0;
	for (int i = 0; i <= wa && i * wb <= c; i++)
	{
		ll other = (c - wb * i);
		answer = max(answer, hb * i + best * (other / gcd) + ((other % gcd) / wa) * ha);
	}
	cout << answer << endl;
	return 0;
}