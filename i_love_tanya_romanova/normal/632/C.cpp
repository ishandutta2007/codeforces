/*
A beating pulse, a pounding heart,
a million pieces from the start
I never doubted for a second
that it would be hard
But the will to be alive
greater than any ideals

I believe in you my love, we are above
simple things are not for us, we bleed for love

Driven by our violent past,
ever forcing us to last,
unbridled killer instinct
ever standing fast
And so the will to be alive
overshadows any doubt

I believe in you my love, we are above
simple things are not for us, we bleed for love
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

const int N = 100010;

using namespace std;

int n;
string st[N];

bool cmp(string& a, string& b)
{
	return a + b < b + a;
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> st[i];
	}
	sort(st, st + n, cmp);

	for (int i = 0; i < n; i++)
		cout << st[i];
	cout << endl;

	cin.get(); cin.get();
	return 0;
}