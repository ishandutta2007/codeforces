/*
Sometimes I feel like I don't have a partner
Sometimes I feel like my only friend
It's the city I live in, the City of Angels
Lonely as I am, together we cry

I drive on her streets 'cause she's my companion
I walk through her hills cause she knows who I am
She sees my good deeds and she kisses me windy
I never worry, now that is a lie

I dont ever wanna feel like I did that day
Take me to the place I love, take me all the way
I dont ever wanna feel like I did that day
Take me to the place I love, take me all the way
Yeah, yeah, yeah

It's hard to believe that there's nobody out there
It's hard believe that I'm all alone
At least I have her love the city, she loves me
Lonely as I am, together we cry

And I dont ever wanna feel like I did that day
Take me to the place I love, take me all the way
And I dont ever wanna feel like I did that day
Take me to the place I love, take me all the way
Yeah, yeah, yeah, oh, no, no, no
Yeah, yeah, love me I say yeah, yeah

Under the bridge downtown is where I drew some blood
Under the bridge downtown I could not get enough
Under the bridge downtown forgot about my love
Under the bridge downtown I gave my life away
Yeah, yeah, yeah

Yeah, yeah, yeah, oh, no, no, no
Yeah, yeah, oh, no, no
I said yea yeah, Ill stay
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
const int N = 500031;

struct pt
{
	double x;
	double y;
};

pt p[10];
double r[10];

double get_dist(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

double eval(double x, double y)
{
	vector<double> v;

	for (int i = 0; i < 3; i++)
	{
		v.push_back(get_dist(x, y, p[i].x, p[i].y) / r[i]);
	}
	sort(v.begin(), v.end());
	double res = 0;
	for (int i = 0; i < 3; i++)
	{
		res += (v[i] - v[1])*(v[i] - v[1]);
	}
	return res;
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	for (int i = 0; i < 3; i++)
	{
		cin >> p[i].x >> p[i].y >> r[i];
	}

	double cur_x = 0;
	double cur_y = 0;

	for (int i = 0; i < 3; i++)
	{
		cur_x += p[i].x;
		cur_y += p[i].y;
	}
	cur_x /= 3;
	cur_y /= 3;

	double step = 1.0;

	int C = 0;

	for (int iter = 1; iter <= 100000; iter++)
	{
		double Q = rand();
		double dx = cos(Q)*step;
		double dy = sin(Q)*step;
		if (eval(cur_x, cur_y) > eval(cur_x + dx, cur_y + dy))
			cur_x += dx,
			cur_y += dy;
		else
		{
			++C;
			if (C > 1000)
				C = 0,
				step *= .5;
		}
	}

	//cout << cur_x << " " << cur_y << " " << eval(cur_x, cur_y) << endl;

	double here = eval(cur_x, cur_y);
	if (here < eps)
	{
		cout.precision(12);
		cout << fixed << cur_x << " " << cur_y << endl;
	}
	cin.get(); cin.get();
	return 0;
}