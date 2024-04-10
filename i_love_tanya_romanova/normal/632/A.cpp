/*
When the world was darker than I could understand
When nothing turned out the way I planned
When the sky turned grey with no one in sight
When I couldn't sleep through the lonely nights

I turned to you
like a flower leaning towards the sun
I turned to you the only one
who could turn me around
when I was upside down
I turned to you

When my insides were wrecked with anxiety
You have the touch that quieted me
You lifted my spirit to melt the ice
When I needed inspiration, when I needed advice
I turned to you

Where would I be
what would I do
had you never helped me through?
I hope someday
If you've lost your way
you can turn to me
like I turned to you
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

int n, p;
long long odd[100], total;
long long ex;

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> p;

	for (int i = 1; i <= n; i++)
	{
		string st;
		cin >> st;
		if (st.size() > 4)
			odd[i] = 1;
	}

	total = 0;
	for (int i = n; i; --i)
	{
		total = total * 2;
		if (odd[i])
			ex++,
			total++;
	}

	cout << total*p - ex*p / 2 << endl;

	cin.get(); cin.get();
	return 0;
}