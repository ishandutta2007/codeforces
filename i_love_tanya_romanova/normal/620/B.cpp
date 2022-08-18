/*
Life on earth for you to know
In peace you live in peace you will go
Behind the scenes of salvation
Nobody knows lust and temptation

The mass begins the spirit appears
The man in black nothing he fears
A fatal disguise is what you call holy
Where is god? I want you to show me.

In the name of the father the son
The holy spirit the show has begun
Thy kingdom come thy will be done
Hallowed be thy name

Reincarnation
False celebration
Reincarnation
Mental subordination

Go down on your knees
And pray for peace
Join the club of total devotion
Religious faith and social failure
Once you've been trapped
Death is your saviour

In the name of the father the son
The holy spirit the show has begun
Thy kingdom come thy will be done
Hallowed be thy name

Reincarnation
False celebration
Reincarnation
Mental subordination

In the name of the father the son
The holy spirit the show has begun
Thy kingdom come thy will be done
Hallowed be thy name

Reincarnation
False celebration
Reincarnation
Mental subordination
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

const int N = 600000;

using namespace std;

int a, b;
int res;
int c(int x)
{
	if (x == 0)
		return 6;
	if (x == 1)
		return 2;
	if (x == 2)
		return 5;
	if (x == 3)
		return 5;
	if (x == 4)
		return 4;
	if (x == 5)
		return 5;
	if (x == 6)
		return 6;
	if (x == 7)
		return 3;
	if (x == 8)
		return 7;
	return 6;
}
int solve(int x)
{
	if (x == 0)
		return 0;
	return c(x % 10) + solve(x / 10);
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//	freopen("F:/in.txt", "r", stdin);
	//	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> a >> b;
	for (int i = a; i <= b; i++)
	{
		res += solve(i);
	}
	cout << res << endl;

	cin.get(); cin.get();
	return 0;
}