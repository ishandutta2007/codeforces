/*
The first time I saw you
You were chasing down
A cyclone
All alone in a field
With rail yards and clovers
I kept rolling on and never thought
You'd wind up chasing me

Well settle down I won't hesitate
To hit the highway
Before you lay me to waste
Settle up and I'll help you find
Something to drive
Before you drive me insane

You're tired of walking and you
Loathe the ground
The sidewalk will barely
Touch your feet and life moves
Too slowly to hold you down
With ringing hands
You take it out on me

Well settle down I won't hesitate
To hit the highway
Before you lay me to waste
Settle up and I'll help you find
Something to drive
Before you drive me insane

Get yourself a car and drive it all alone
Get yourself a car and ride it on the wind
Get yourself a car and drive it all alone
Get yourself a car and ride it on the wind

Well settle down I won't hesitate
To hit the highway
Before you lay me to waste
Settle up and I'll help you find
Something to drive
Before you drive me insane

Get yourself a car and drive it all alone
Get yourself a car and ride it on the wind
Get yourself a car and drive it all alone
Get yourself a car and ride it on the wind
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

struct pt
{
	int x;
	int y;
	int v;
};

pt orig;
int n;

pt p[N];

double get_dist(pt a, pt b)
{
	return sqrt(1.0*(a.x - b.x)*(a.x - b.x) + 1.0*(a.y - b.y)*(a.y - b.y));
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> orig.x >> orig.y;

	double ans = 1e9;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i].x >> p[i].y >> p[i].v;
		double here = get_dist(p[i], orig);
		double T = here / p[i].v;
		ans = min(ans, T);
	}

	cout.precision(12);
	cout << fixed << ans << endl;

	cin.get(); cin.get();
	return 0;
}