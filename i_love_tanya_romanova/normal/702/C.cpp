/*
Inside...
The dark is fading away
I don't want to be alone anymore

Inside...
The light of dawn is here once more

The light...
Darkness is slipping away

Of dawn...
I don't want to be alone

Is here...
Won't you stay?

Not a word passed your lips
Just a golden kiss
As I whispered silently
"Help me through this"
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
const int N = 200000;

int n, m, ar[N];
int b[N];

bool covers(int b_id, int a_id,long long val)
{
	return abs(b[b_id] - ar[a_id]) <= val;
}

bool check(long long val)
{
	int ptr = 0;

	for (int i = 0; i < m; i++)
	{
		while (ptr < n&&covers(i, ptr,val))
			++ptr;
	}
	//cout << val << " " << ptr << endl;
	return (ptr == n);
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> ar[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}

	long long l, r;
	l = 0;
	r = 4e9;

	while (l < r)
	{
		long long mid = l + r;
		mid /= 2;
		if (check(mid))
			r = mid;
		else
			l = mid + 1;
	}

	cout << l << endl;

	cin.get(); cin.get();
	return 0;
}