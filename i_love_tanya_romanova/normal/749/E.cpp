/*
I will destroy myself.
Content to burn forever in this Hell you've made.
This is finality.

I will destroy myself.
My body torn to pieces, yet I feel no pain.
This is finality.

Deny me your mercy.
This time I will not beg forgiveness.
You'll watch me die.

Dear father, take my life.
Your child has lost the will to fight, the will to bleed,
the way you've bleed for me.
Dear father, take my breath and I'll scream until there's nothing left.
Just bury me.

Take the sight from my eyes and the breath within my lungs.
My fear is my reason for suffering.
Is this the cost of redemption?
Shall I suffer for my sins?
I'm willing to bleed on your alter.

Deny me your mercy.
This time I will not beg forgiveness.
You'll watch me die.

Dear father, take my life.
Your child has lost the will to fight, the will to bleed,
the way you've bleed for me.
Dear father, take my breath and I'll scream until there's nothing left.
Just bury me.
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
#define ends asdgahhfdsfshdshfd

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 337

using namespace std;

long long INF = 1e9;
const int N = 200031;

int n;
int ar[N];

long long t[N];

long double res;

long long ti[N];

long long sum_i(long long r)
{
	long long res = 0;
	for (; r >= 0; r = (r&(r + 1)) - 1)
		res += ti[r];
	return res;
}

void inc_i(long long i, long long delta)
{
	for (; i < N; i = (i | (i + 1)))
		ti[i] += delta;
}

long long sum_i(long long l, long long r)
{
	return sum_i(r) - sum_i(l - 1);
}

long long sum(long long r)
{
	long long res = 0;
	for (; r >= 0; r = (r&(r + 1)) - 1)
		res += t[r];
	return res;
}

void inc(long long i, long long delta)
{
	for (; i < N; i = (i | (i + 1)))
		t[i] += delta;
}

long long sum(long long l, long long r)
{
	return sum(r) - sum(l - 1);
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//	freopen("F:/input.txt", "r", stdin);
	//	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
	}

	for (int i = n; i >= 1; --i)
	{
		int here = sum_i(ar[i]);
		long double prob_chosen = 1.0*i*(n - i + 1) / (1.0*n*(n + 1) / 2);
		res += (1.0-prob_chosen)*here;

		//shit starts here

		// below, unreached

		long double res2 = 0;
		res2 += 0.5*(n - i);
		long long S = sum(ar[i]);
		long long cnt = sum_i(ar[i]);
		long long sum_seg = S - cnt*i;
		res2 += sum_seg*1.0 / (n - i + 1) / 2; // they stay to the right giving 1

		// above, uncreached
		long long S2 = sum(ar[i] + 1, n);
		long long cnt2 = sum_i(ar[i] + 1, n);
		sum_seg = S2 - cnt2*i;
		res2 -= sum_seg*1.0 / (n - i + 1) / 2;// they stay to the right giving 0

		//cout << sum_seg << endl;

		inc_i(ar[i], 1);
		inc(ar[i], i);
		res += res2*prob_chosen;

//		cout << res << endl;

	}

	cout.precision(15);

	cout << fixed<<res << endl;

	cin.get(); cin.get();
	return 0;
}