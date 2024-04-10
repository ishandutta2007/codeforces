/*
Her gentle hand in his
Revelation serves as bliss
They walk away from sunshine
Led to believe the lie
His lust for untouched youth
A well kept secret sealed
His every night confession
Reveals the most profane obsession

Their trust is won and fate is conquered
The essence of conviction

Why me?
I did no wrong
I did not know
You lied to me
I meant no harm
And I am blaming me

Hand in hand down the altar aisle
Her father's presence brings her to a smile
A grand welcome from the assembled crowd
Greeted as the "circles" first child
Undressed to nothing and held to the sky
Her smile is gone and she starts to cry
Desperately seeking her father's eyes
But he sees nothing
He's blind.
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
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 100031;

long long need, l, r;

long long safe_mult(long long a, long long b)
{
	if (a == 0 || b == 0)
		return 0;
	if (1e18 / b < a)
		return 1e18;
	return a*b;
}

long long solve(long long x)
{
	long long can = 0;

	for (int k = 2;; k++)
	{
		long long T = 1;
		for (int j = 1; j <= 3; j++)
		{
			T = safe_mult(T, k);
		}
		can += x / T;
		if (x < T)
			break;
	}
	return can;

}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> need;

	long long l, r;
	l = 0;
	r = 1e17;
	while (l < r)
	{
		long long mid = l + r;
		mid /= 2;
		if (solve(mid) < need)
			l = mid + 1;
		else
			r = mid;
	}

	if (solve(l) == need)
		cout << l << endl;
	else
		cout << -1 << endl;

	cin.get(); cin.get();
	return 0;
}