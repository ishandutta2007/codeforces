/*
I came across a smoking field
Pulsating afterglow
I saw a searing flash of light
Erupt and skyward go
I staggered back in dazed surprise
What was it I had seen?
And as I stood there mesmerized
I heard my spirit scream

Invader, invader nearby
Invader, invader is nigh

This is the first of more to come
In carefully planned attacks
If it is so we must prepare
Defenses to fight back
The call is out throughout the world
United we must stand
To build a line, strategic force
They will not take a man

Invader, invader nearby
Invader, invader is nigh

When they come to take control
Every man must play his role
They won't take our world away
When the children we leave
Will have to believe in today

We warn you now you things out there
Whatever you may send
Won't give in without a fight
A fight until the end
With vigilance by day and night
Our scanners trace the sky
A shield is sealed upon this earth
A shield you won't get by

Invader, invader nearby
Invader, invader is nigh
*/

//#pragma comment(linker, "/STACK:16777216")
#define _CRT_SECURE_NO_WARNINGS

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
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

const int N = 1002000;

using namespace std;

long long fact[N], invf[N];

long long pw(long long a, long long b)
{
	if (b == 0)
		return 1;
	if (b % 2)
		return a*pw(a, b - 1) % bs;
	return pw(a*a%bs, b / 2);
}

long long inv(long long x)
{
	return pw(x, bs - 2);
}

long long C(long long n, long long m)
{
	if (m > n)
		return 0;
	long long res = fact[n];
	res *= invf[m];
	res %= bs;
	res *= invf[n - m];
	return res%bs;
}

int n, k, q;
long long res;
vector<int> divs[N];
int cnt[N];
long long deg[N];
long long coef[N];

void update(int val)
{
	res = res - C(cnt[val], k)*coef[val]%bs + bs;
	res %= bs;
	cnt[val]++;
	res = res + C(cnt[val], k)*coef[val];
	res %= bs;
}

void add(int val)
{
	for (int i = 0; i < divs[val].size(); i++)
	{
		int cur_div = divs[val][i];
		update(cur_div);
	}
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	fact[0] = 1;
	for (int i = 1; i < N; i++)
	{
		fact[i] = fact[i - 1] * i%bs;
	}

	for (int i = 0; i < N; i++)
	{
		invf[i] = inv(fact[i]);
	}

	for (int i = 1; i < N; i++)
	{
		long long totake = i - deg[i];
		coef[i] = totake;
		for (int j = i; j < N; j += i)
		{
			divs[j].push_back(i);
			deg[j] += totake;
		}
	}

//	cout << "@" << mx << endl;

	/*
	for (int i = 1; i <= 20; i++)
	{
		cout << i << " " << deg[i] << endl;
	}
	*/
	cin >> n >> k >> q;

	for (int i = 1; i <= n; i++)
	{
		int val;
		cin >> val;
		add(val);
	}

	for (int i = 1; i <= q; i++)
	{
		int val;
		cin >> val;
		add(val);
		cout << res << "\n";
	}


	cin.get(); cin.get();
	return 0;
}