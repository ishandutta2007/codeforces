/*
Anchor the night, open the sky
Hide in the hours before sunrise
Pray for me not, I won't lose sight
Of where I belong and where you lie

Heaven's dead when you get sad
I see your wishes flying
Out of time
For the best time you've had

Shipwreck the sun, I'm on your side
An army of one, onward we'll ride
And whisper your songs, birds to the air
We will bury all of our burdens there

Heaven's dead when you get sad
I see your wishes flying
Out of time
For the best time you've had
Heaven's dead when you get sad
I see your wishes flying
Out of time
For the best time you've had

Best time you had
For the best time you had
Heaven's dead when you get sad

Heaven's dead when you get sad
I see your wishes flying
Out of time
For the best time you've had
Heaven's dead when you get sad
I see your wishes flying
Out of time

I'll take it all, arrows or guns
Hundreds or more to save you from one
Save you from one
And where I'll be
Heaven's dead when you get sad
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
const int N = 1300000;
const int SZ = 201000;

int n, tests;
vector<int> ar;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	ar.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> ar[i];
	}
	sort(ar.begin(),ar.end());
	cin >> tests;
	for (; tests; --tests)
	{
		int val;
		cin >> val;
		int res = upper_bound(ar.begin(),ar.end(), val)-ar.begin();
		cout << res << "\n";
	}

	cin.get(); cin.get();
	return 0;
}