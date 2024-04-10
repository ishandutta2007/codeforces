/*
Dark shadows lie over the city
Tonight someone will die
You can hear painful screams
The air is full of flies
Mayhemic legions are ready
To steal the human souls
Come into my vault and do like you get told
I'll eat your intestines
No matter if you pray or please
I'll bring you down to your knees
Tonight you're gonna meet your fate
You try to run but it's too late
I am here to liquidate

Time to raise the flag of hate
Destroy the earth is our only aim
To strike all down is the only way
To give 'em death and let them pay

The galleys of the underground sail
On the sea of blood
All that we want crucify your god
The posers on this earth have no right to live
We're gonna split their brains
Torture is what we give
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
#include <ctime> 
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1234567891
#define bsize 512

const int N = 210000;

using namespace std;

struct pt
{
	double x;
	double y;
};

struct seg
{
	pt p1;
	pt p2;
};

int used[N];
int n;
int a;
int b;
pt orig, goal;
seg tr[N];
double dist[N];

double get_dist(pt p1, pt p2)
{
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

double get_area(pt a, pt b, pt c)
{
	double res = (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
	return fabs(res);
}

double get_dist(pt a, seg b)
{
	double A = get_dist(a, b.p1);
	double B = get_dist(a, b.p2);
	double C = get_dist(b.p1, b.p2);
	if (A*A + C*C <= B*B || B*B + C*C <= A*A)
	{
		return min(A, B);
	}
	A = get_area(a, b.p1, b.p2);
	// 2S=ah
	//h=2s/a
	return A / C;
}

double get_dist(seg a, seg b)
{
	double res = get_dist(a.p1, b);
	res = min(res, get_dist(a.p2, b));
	res = min(res, get_dist(b.p1, a));
	res = min(res, get_dist(b.p2, a));
	return res;
}

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> a >> b;
	
	cin >> orig.x >> orig.y >> goal.x >> goal.y;

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> tr[i].p1.x >> tr[i].p1.y >> tr[i].p2.x >> tr[i].p2.y;
	}
	
	if (get_dist(orig, goal) <= a + eps)
	{
		cout.precision(10);
		cout << fixed << get_dist(orig, goal) << endl;
		return 0;
	}

	for (int i = 1; i <= n; i++)
	{
		dist[i] = 1e9;
	}

	for (int i = 1; i <= n; i++)
	{
		double D = get_dist(orig, tr[i]);
		if (D <= a + eps)
		{
			dist[i] = D;
		}
	}

	double ans = 1e15;

	for (int iter = 1; iter <= n; iter++)
	{
		double bst = 2e9;
		int bp = 1;
		for (int i = 1; i <= n; i++)
		{
			if (used[i] == 0 && dist[i] < bst)
				bst = dist[i],
				bp = i;
		}
		used[bp] = 1;
		//cout << bp << "%" << dist[bp] << endl;

		int ful = (dist[bp]+eps) / (a + b);
		double start = ful + 1;
		start *= (a + b);
		double T = get_dist(goal, tr[bp]);
		if (T <= a + eps)
		{
			ans = min(ans, start + T);
		}

		for (int i = 1; i <= n; i++)
		{
			if (used[i])
				continue;
			double D2 = get_dist(tr[i], tr[bp]);
			if (D2 > a + eps)
				continue;
			dist[i] = min(dist[i], start + D2);
		}
	}

	cout.precision(12);
	if (ans > 4e8)
		cout << -1 << endl;
	else
		cout << fixed << ans << endl;

	cin.get(); cin.get();
	return 0;
}