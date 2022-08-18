/*
You want someone to blame
The one who drives the rusted nail
But who's left will never care
Pretending becomes a chore
All you search for, a little piece of mind
Too far, too deep, the two faced smile
So lost, you feel, I know

Wide awake but still asleep
Always a stranger in a crowd (sleep, sleep, sleep)
Wide awake, always a stranger in a crowd (wake, wake, wake)

Just this once
Listen to the words I say
If you want I will
I'm there until the end of time

Leave the doomed behind
Search with different light
You were trying to remember
But it's all make believe

You are, you are, you are

Wide awake but still asleep (wide awake but still asleep)
Always a stranger in a crowd

Just this once
Listen to the words I say
If you want I will
I'm there until the end of time

Just this once
Listen to the words I say
If you want, I'm there

Just this once
Listen to the words I say
If you want I will
I'm there until the end of time
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
const int N = 110000;

int n;
long long k;
int id[N];

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> id[i];
	}

	for (int i = 1; i <= n; i++)
	{
		if (i >= k)
		{
			cout << id[k] << endl;
			break;
		}
		k -= i;
	}

	cin.get(); cin.get();
	return 0;
}