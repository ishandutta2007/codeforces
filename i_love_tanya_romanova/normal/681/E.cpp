/*
Unraveling the gruesome nest of tales
Sadistic Magician
A crime scene set left to resemble hell
Sadistic Magician
A brain consumed obsessed within itself
Sadistic Magician
Lives left wreaked to cast the perfect spell

I cannot run, I cannot see
All I know is death is surrounding me
Tied down and trapped
Someone set me free
No chance to escape, nowhere to flee

The smell of burning flesh fills up the lungs
The sound of chanting ringing through your ears
Your voice is lost from screaming out for help
It feels like you have been here trapped for years

Convinced that this will be the final outcome
You're pleading for it now so you can rest
Instead he's trapped here in the hands of a maniac
Who's convinced he's a sorcerer of death

Thick smoke completely filled up his enclosure
The blade is getting closer to the throat
Your life begins to flash before your own very eyes
And slips away as you begin to choke
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

int n;
int x0, y0;
long double T;
int x[N], y[N], r[N];
long double thold[N];

long double get_d(long double x, long double y)
{
	return sqrt(x*x + y*y);
}

long double get_w(int id)
{
	long double D1 = get_d(x[id], y[id]);
	long double res = asin(r[id] / D1); 
	thold[id] = D1*cos(res);
	return res;
}

pair<long double, long double> solve_tan(int id)
{
	long double cen_ang = atan2(y[id], x[id]);
	long double shi = get_w(id);
	return make_pair(cen_ang - shi, cen_ang + shi);
}

long double v;
vector<pair<long double, int> > events;

long double get_dist(long double x1, long double y1, long double x2, long double y2)
{
	return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

long double G(long double x1, long double y1, long double x2, long double y2)
{
	return ((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

bool check(long double ang, int id)
{
	long double tx = cos(ang)*v;
	long double ty = sin(ang)*v;
	long double Da = get_dist(x[id], y[id], tx, ty);
	long double Db = get_dist(0, 0, x[id], y[id]);
	long double Dc = get_dist(0, 0, tx, ty);
	//cout << tx << " " << ty << " " << " "<<Da<<" "<<Db<<" "<<r[id]<<" "<<ang<<" "<<
	//	Da*Da+Db*Db<<" "<<Dc*Dc<<endl;
	if (Da <= r[id])
		return true;
	if (Dc>thold[id])
		return true;
	return false;
}

void ADD(long double l, long double r)
{
	assert(l >= -eps&&r <= 2 * M_PI + eps);

	events.push_back(make_pair(l-1e-9, 1));
	events.push_back(make_pair(r+1e-9, -1));
}

void add_seg(long double l, long double r)
{
	if (l<0)
	{
		ADD(2 * M_PI + l, 2 * M_PI);
		ADD(0, r);
	}
	else
	{
		ADD(l, r);
	}
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> x0 >> y0 >> v >> T;
	cin >> n;
	v *= T;

	if (v > 4e9)
		v = 4e9;

	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i] >> r[i];
		x[i] -= x0;
		y[i] -= y0;
		if (1ll * x[i] * x[i] + 1ll * y[i] * y[i] <= 1ll * r[i] * r[i])
		{
			cout << 1 << endl;
			return 0;
		}
	}

	if (v < eps)
	{
		cout << 0 << endl;
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		pair<long double, long double> P = solve_tan(i);
		if (P.second>2 * M_PI)
			P.first -= 2 * M_PI, P.second -= 2 * M_PI;
		if (P.second < 0)
			P.second += 2 * M_PI, P.first += 2 * M_PI;

		//cout << P.first << " " << P.second << endl;
		long double l, r;
		l = P.first;
		r = P.first + P.second;
		r /= 2;
		//cout << thold[i] << endl;
		for (int iter = 0; iter <= 60; iter++)
		{
			long double mid = l + r;
			mid /= 2;

			if (check(mid, i))
				r = mid;
			else
				l = mid;
		}
		long double center = P.first + P.second;
		center /= 2;
		r = 2 * center - l;
		//		cout << l << " " << r << endl;
		if (r < 0)
		{
			l += 2 * M_PI;
			r += 2 * M_PI;
		}

		add_seg(l, r);
		//cout << l << " " << r << endl;
	}

	sort(events.begin(), events.end());
	int cnt = 0;
	long double ans = 0;
	for (int i = 0; i < events.size(); i++)
	{
		assert(cnt >= 0);
		if (cnt>0)
		{
			ans += events[i].first - events[i - 1].first;
		}
		cnt += events[i].second;
	}

	cout.precision(12);

	cout << fixed << ans*1.0 / (2 * M_PI) << endl;

	cin.get(); cin.get();
	return 0;
}