/*
Spare the rod, spoil the child
Daddy's boy's been too wild
His discipline's taught with a strap
No sweet song on father's lap
He always said that men don't cry
But burns and bruises seldom lie
Dad learned his lesson well
Spitting image of a man in hell

Brought up in a home where love's replaced by pain
And when he's on his own he's sure to do the same
Expressing his feelings not with love but with his fists
The pattern of hurting began generations before

Like father, like son
Another life has begun
The punishing ways that you choose
You were always born to lose
Like father, like son
A war you've never won
Please Daddy, no more...
Please Daddy, no more!

The circle continues of violence passed down
All there is hope for is a tear from a clown
Hoping someday that this torture will end
To prison or death I hope you will be sent
*/

#pragma comment(linker, "/STACK:16777216")
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

int found;
int val;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> val;
	for (int i = 0; i <= 1000; i++)
	{
		for (int j = 0; j <= 10000; j++)
		{
			long long here = 1234567ll * i + 123456 * j;
			if (here <= val && (val - here) % 1234 == 0)
				found = 1;
		}
	}
	if (found)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	cin.get(); cin.get();
	return 0;
}