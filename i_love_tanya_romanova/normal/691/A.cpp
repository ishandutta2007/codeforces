/*
Do you see the way that tree bends? Does it inspire?
Leaning out to catch the sun's rays...a lesson to be applied...
Are you gettin' something out of this all encompassing trip?
You can spend your time alone redigesting past regrets oh...
Or you can come to terms and realize
You're the only one who can forgive yourself oh yeah...
Makes much more sense to live in the present tense...
Have you ideas on how this life ends?
Checked your hands and studied the lines?
Have you the belief that the road ahead ascends off into the light?
Seems that needlessly it's gettin' harder
To find an approach and a way to live...
Are we gettin' something out of this all-encompassing trip?
You can spend your time alone redigesting past regrets, oh...
Or you can come to terms and realize...
You're the only one who cannot forgive yourself, oh...
A-makes much more sense to live in the present tense...
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

int n, ar[N], s;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
		s += ar[i];
	}
	--n;
	if (n == 0)
		n = 1;

	if (s == n)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	cin.get(); cin.get();
	return 0;
}