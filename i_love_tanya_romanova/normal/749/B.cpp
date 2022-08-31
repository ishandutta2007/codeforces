/*
The stench of the hopeless and wounded.
The cries that escape from the depths of regret.
A bleeding mass in procession.
That fell on the path from which it strayed.
A whisper in total darkness.
To die at the hands of what we are.
A breath escapes from the lifeless.
The blind and the feeble of our decay.
This is the pain we must suffer.
This is the endless agony.
This is the darkest of secrets we give our lives to keep.
The light that's surrounding.
I am all that you've made me.
Their endless desire feeds the fire inside me and all I can ask for.
Take this life that you gave me.
I'm not your messiah.
The fear that grows like a cancer.
Held likes a breath and sacrificed.
Thee blood that flows from the wounded.
Consumed by the masses who've longed to taste.
This is a prayer for the hopeless.
This is an endless tragedy.
This is the darkest of secrets.
We give ourselves to keep.
The light that's surrounding.
I am all that you've made me.
Their endless desire feed the fire inside me and all I can ask for.
Take this life that you gave me.
I'm not your messiah.
I pray for redemption.
These unanswered cries.
In darkness it came to me and I breathe.
Their distant voices sing to me and everything changes suddenly.
The light that's surrounding.
I am all that you've made me.
Their endless desire feeds the fire inside me and all I can ask for.
Take this life that you gave me.
I'm not your messiah.
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
#define ends asdgahhfdsfshdshfd

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 337

using namespace std;

long long INF = 1e9;
const int N = 2031;

int x[100], y[100];
int sx, sy;

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//	freopen("F:/input.txt", "r", stdin);
	//	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	for (int i = 0; i < 3; i++)
	{
		cin >> x[i] >> y[i];
	}

	cout << 3 << endl;

	for (int othr = 0; othr < 3; othr++)
	{
		sx = x[0] + x[1] + x[2] - 2 * x[othr];
		sy = y[0] + y[1] + y[2] - 2 * y[othr];
		cout << sx << " " << sy << endl;
	}

	cin.get(); cin.get();
	return 0;
}