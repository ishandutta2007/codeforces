/*
Can't sleep with all this frustration, intoxication
I no longer have regret
So what If I cause hysteria, It's not my dilemma
I'm only here to inflict pain
I will never forgive the ones who pushed me away
Like a tumor, rage grows inside me
Reminding me every day, I will retaliate
A thorn in my spine for ?(8) years

The Man who sheds no tears
I am here to expose you
All of the poison that you take
All people you violate
Your faith can't save you now

I will never forgive the ones who pushed me away
Like a tumor, rage grows inside me
Reminding me every day, I will retaliate
I am your family with the power

To end everything
Everything you love
You should be paranoid
I guess I no longer share this vision

I guess I have a new agenda
While you sink down into your hole
I am proud watching you lose control
I will never forgive the ones who pushed me away
Like a tumor, rage grows inside me

Reminding me every day,
I will never forgive the ones who pushed me away
Like a tumor, rage grows inside me
*/

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
#define have adsgagshdshfhds

#define eps 1e-6
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 337

using namespace std;

const int INF = 1e9;
const int N = 500031;

int n, a[N], b[N], c[N];

long long here[N], total;
long long this_val, ans[N];

long long exp_a[N], exp_b[N];
int cnt[100];

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/input.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n;
	/*for (int i = 1; i <= n; i++)
	cin >> ar[i];


	for (int i = 1; i <= n; i++)
	{
	for (int j = 1; j <= n; j++)
	{
	b[i] += (ar[i] & ar[j]);
	c[i] += (ar[i] | ar[j]);
	}
	cout << b[i] << " ";
	}
	cout << endl;

	for (int i = 1; i <= n; i++)
	{
	cout << c[i] << " ";
	}
	cout << endl;
	*/

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
	}

	for (int i = 1; i <= n; i++)
	{
		here[i] = a[i] + b[i];
		total += here[i];
	}

	//cout << total << endl;

	if (total % (n * 2))
	{
		cout << -1 << endl;
		return 0;
	}

	long long sum_all = total / (n * 2);

	for (int i = 1; i <= n; i++)
	{
		this_val = here[i] - sum_all;
		if (this_val%n>0 || this_val<0)
		{
			cout << -1 << endl;
			return 0;
		}
		ans[i] = this_val / n;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= 30; j++)
		{
			if (ans[i] & (1 << j))
				cnt[j]++;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= 30; j++)
		{
			if (ans[i] & (1 << j))
			{
				exp_a[i] += (1 << j) * 1ll * (cnt[j]);
				exp_b[i] += (1 << j) * 1ll * n;
			}
			else
			{
				exp_b[i] += (1 << j) * 1ll * cnt[j];
			}
			
		}
	}

	/*for (int i = 1; i <= n; i++)
	{
		cout << exp_a[i] << " ";
	}
	cout << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << exp_b[i] << " ";
	}
	cout << endl;
	while (true);
	*/
	for (int i = 1; i <= n; i++)
	{
		if (exp_a[i] != a[i] || exp_b[i] != b[i])
		{
			cout << -1 << endl;
			return 0;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (i>1)
			cout << " ";
		cout << ans[i];
	}
	cout << endl;

	cin.get(); cin.get();
	return 0;
}