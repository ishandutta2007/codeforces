/*
Battles rage throughout hamlets and empires
Heroes die, legends are born
The righteous pray all through the eons
Still the evil unsheaths the sword

God of time keeps track of all the things
Gathers in the souls of the dead
A champion born, knight reincarnate

Fear, death, blood, flesh - my glory day is here
Over lords, raging hordes, the spoils of war are near

I will fight alone
Stand and face and army of one
I will fight alone
Until I'm overrun

Answer the cries of innocent children
Bury deep the overlords
The banner hails avenging warrior
Savior of a stricken world

Hear the seer's foretell my - lonely demise
Reap the sorceress angered - am still alive
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
#define have adsgagshdshfhds

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 200031;

int solve(int a, int b, int c)
{
	return abs(b - a) + abs(c - a);
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	cout << min(solve(a, b, c),min( solve(b, a, c), solve(c, b, a))) << endl;

	cin.get(); cin.get();
	return 0;
}