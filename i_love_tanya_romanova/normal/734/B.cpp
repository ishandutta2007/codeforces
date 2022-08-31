/*
It's just another sleepless night
The hunt is on
Looking for anything
To fill the void
Make me feel alive
Take me back to paradise

'Cause I'm walking on broken glass
I should know, good things never fucking last
The reflections of a shattered past
They keep me walking on broken glass

A thousand eyes focus
Here is your god
Which one will sacrifice
Their innocence tonight?
Don't think twice
Take me back to paradise

'Cause I'm walking on broken glass
I should know, good things never fucking last
The reflections of a shattered past
They keep me walking on broken glass

The nameless walking with their guide
For a chance to meet their god
And it just wont stop

Can't describe this satisfaction
Can't control the chain reaction
I employ you to fulfill this greed
Insensitive
On flesh I feed
Welcome to my hell

Make me feel alive
Take me back to paradise
'Cause I'm walking on broken glass
I should know, good things never fucking last
The reflections of a shattered past
They keep me walking on broken glass
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
const int N = 200031;

int k2, k3, k5, k6;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/input.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> k2 >> k3 >> k5 >> k6;

	long long ans = 0;

	for (int i = 0; i <= 5e6; i++)
	{
		if (i <= k3&&i <= k2)
		{
			int rem_k2 = k2 - i;
			int rem_k5 = k5;
			int rem_k6 = k6;
			int here = min(rem_k2, min(rem_k5, rem_k6));
			ans = max(ans, 1ll * here * 256 + i * 32);
		}
	}
	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}