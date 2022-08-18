/*
We are heading for tomorrow
But we don't know if we're near
Will we beg or steal or borrow
Will we ever lose the fear

Time has passed in the modern world
Where the madmen live and speak their word
Life in hand they deal with God
Put a trademark sign up on everyone

God bless the children, freedom is their word
Freedom, freedom 'til they learn to obey
Here come the liars, reason is their name
Reason, reason, play a silly game
Where will the children go tomorrow?
Where will the children go tomorrow?

Is anybody there to claim
That he understands our human game?
We can make a prophecy
Oh, we can't say what is going to be

Where are we going and what is our aim?
Freedom, freedom, locked inside our brains
So many answers, reason is their name
Reason, reason, the question will remain
Where will the children go tomorrow?
Where will the children go tomorrow?

Hey, you, hey you, hey you all
Hey, you, where do you go?
Heading for tomorrow
Hey, you, hey you, hey you
Hey, you, where do you go?
Heading for my life

Hey, you, where do you go?
Heading for tomorrow
Hey, you, where do you go?
Heading for my life
Hey, you, where do you go?
Heading for tomorrow
Hey, you, where do you go?

When we are born tell me what is our aim?
And what will be when society fails?
We are heading for tomorrow
We don't know if we are near

When we are gone, tell me what will remain?
And what will be when society fails?
Ohh ohh ohh
We are heading for tomorrow
But we don't know if we're near
*/

//#pragma comment(linker, "/STACK:16777216")
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

const int N = 231231;

using namespace std;

int n;
double clo, fur;

struct pt
{
	double x;
	double y;
};

pt orig;
pt c[N];
double ans;

struct seg
{
	pt p1;
	pt p2;
};

double get_area(double r)
{
	return M_PI*r*r;
}

double get_dist(pt p1, pt p2)
{
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

double get_area(pt p1, pt p2, pt p3)
{
	return (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x);
}

double get_dist(pt p, seg s)
{
	double a, b, c;
	a = get_dist(p, s.p1);
	b = get_dist(p, s.p2);
	c = get_dist(s.p1, s.p2);
	if (a*a >= b*b + c*c || b*b >= a*a + c*c||fabs(c)<eps)
		return min(a, b);
	double A = get_area(p, s.p1, s.p2);
	//s=1/2ah
	//2s=ah
	//h=2s/a;
	return fabs(A / c);
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("C:/input.txt","r",stdin);
	//freopen("C:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> orig.x >> orig.y;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		c[i].x = a;
		c[i].y = b;
	}

	clo= 1e9;
	fur = -1e9;

	for (int i = 0; i < n; i++)
	{
		fur = max(fur, get_dist(orig, c[i]));
		seg s;
		s.p1 = c[i];
		s.p2 = c[(i + 1) % n];
		clo = min(clo, get_dist(orig, s));
	}
	
//	cout << fur << "$" << clo << endl;

	ans = get_area(fur) - get_area(clo);
	cout.precision(10);
	cout << fixed << ans << endl;

	cin.get(); cin.get();
	return 0;
}