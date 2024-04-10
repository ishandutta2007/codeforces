/*
Sick and tired, of unlucky days
Many times life trick or treats, with heartbreak and change
Like a broken record, nothing clever to play
I'm no good they say
I'm no good they say

What am I fighting for

Pack your bags and hit the streets
With these dirty vocal chords
That will never be in key

These empty streets and dreams
You're not there looking for me
Walking dead
Walking dead
Walking dead
These empty streets and dreams
You're not there looking for me
Walking dead
Walking dead
Walking dead

The only glory is the end

To crash into life
One more day alone
To hold the failures
That are my own, that are my own

I've looked at my existence
I want out
Left torn down in our tracks
Where's your saving grace now?

These empty streets and dreams
You're not there looking for me
Walking dead
Walking dead
Walking dead
These empty streets and dreams
You're not there looking for me
Walking dead
Walking dead
Walking dead

The battle good versus evil
Never come out on top
Hide behind misconception
This world turned itself on

My sanity is nowhere to be found
Walking dead
Walking dead
Walking dead

Only glory
Only glory, is revenge
Only glory
Only glory, is revenge
Where's your saving grace now?
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
#define bsize 256

using namespace std;

const int INF = 1e9;
const int N = 600031;

int n, k;

long long one, s;
int ar[N];
long long z[N];
int rem;
long long pref, cval, k2, need;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> ar[i];

	for (int i = 0; i < n; i++)
		s += ar[i];

	one = s / n;
	for (int i = 0; i < n; i++)
		z[i] = one;
	rem = s%n;

	for (int i = n - 1; i >= 0; --i)
	{
		if (rem)
		{
			++z[i];
			--rem;
		}
	}

	sort(ar, ar + n);

	long long ohead = 0;

	for (int i = 0; i < n; i++)
	{
		if (ar[i]>z[i])
			ohead += ar[i] - z[i];
	}

	if (k >= ohead)
	{
		k = ohead;
	}

	k2 = k;

	int cp = 0;

	cval = ar[0];
	for (int i = 0; i < n; i++)
	{
		if (ar[i]>=z[i])
			break;

		if (i + 1 == n)
			need = 1e9;
		else
			need = ar[i + 1];
		long long F = (need-ar[i])*(i + 1);
		if (F <= k)
		{
			k -= F;
			cp++;
			cval = need;
		}
		else
		{
			cval = ar[i] + k / (i + 1);
			pref = k % (i + 1);
			break;
		}
	}

	for (int i = 0; i <= cp; i++)
	{
		ar[i] = cval;
		if (i < pref)
			++ar[i];
	}
	k = k2;

	//cout << "#" << k << endl;
	cp = n - 1;
	cval = ar[n - 1];

	for (int i = n - 1; i >= 0; i--)
	{
		if (ar[i]<=z[i])
			break;

		if (i == 0)
			need = 0;
		else
			need = ar[i - 1];
		long long F = (ar[i]-need)*(n-i);
		//cout << "%" << F << endl;

		if (F <= k)
		{
			k -= F;
			cp--;
			cval = need;
		}
		else
		{
			cval = ar[i] - k / (n-i);
			pref = k % (n - i);
			break;
		}
	}

	//cout << cp << " " << cval << " " << pref << endl;

	for (int i = n - 1; i >= cp; --i)
	{
		ar[i] = cval;
		if (pref)
		{
			--ar[i];
			--pref;
		}
	}

	sort(ar, ar + n);
	/*
	for (int i = 0; i < n; i++)
	{
		cout << ar[i] << " ";
	}
	cout << endl;
	*/
	cout << ar[n - 1] - ar[0] << endl;

	cin.get(); cin.get();
	return 0;
}