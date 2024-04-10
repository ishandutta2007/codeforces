/*
Another day unfolds, still I exist
Never felt so cold, I never knew I was turning away
Though I can't explain, I only love you now that your missed
As I stand in the rain, just leave me to go through this

I don't think I could face another sleepless night
If only I could trace that elusive light
In a dreamland flight to your agonizing eyes
A never ending flight, my silent cries

Still I close my eyes and my mind becomes clear
Still I dream, and there you are...
How still you lie and how your eyes bring back the fear
Still I can't face what's going on in here...

Everything that I've ever felt has gone
At last my spirit breathes
I see no point in going on
So goodbye... It's time for me to leave
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

int n, val;
map<long long, long long> cnt;
long long ans;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> val;
		for (int j = 0; j <= 33; j++)
		{
			long long need = (1ll << j);
			need -= val;
			ans += cnt[need];
		}
		cnt[val]++;
	}

	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}