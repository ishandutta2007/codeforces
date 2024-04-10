/*
There's no time to give at all
I cause you grief
And blow my hatred

Further in your mind
You reach and I run, you fall
On skinned knees you crawl

I want to set you free, recognize my disease
Love, sex, pain, confusion, suffering
You're there crying, I feel not a thing
Drilling my way deeper in your head
Sinking, draining, drowning, bleeding, dead

So, you sit and think of love
I wait, hate all the more and I fall
On skinned knees I crawl

I want to set you free, recognize my disease
Love, sex, pain, confusion, suffering
You're there crying, I feel not a thing
Drilling my way deeper in your head
Sinking, draining, drowning, bleeding, dead

Now there's time to give it all
I put my fears behind again
On skinned knees we'll crawl

I want to set you free, yeah recognize my disease
Love, sex, pain, confusion, suffering
You're there crying, I feel not a thing
Drilling my way deeper in your head
Sinking, draining, drowning, bleeding, dead
Love, sex, pain, confusion, suffering
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
const int N = 100031;

struct pt
{
	int x;
	int y;
};

double get_dist(pt a, pt b)
{
	return sqrt((a.x - b.x)*1.0*(a.x - b.x) + (a.y - b.y)*1.0*(a.y - b.y));
}

int n;
pt a, b, t;
double sdist;
pt s[N];
vector<pair<double, int> > v1, v2;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> a.x >> a.y >> b.x >> b.y >> t.x >> t.y;

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i].x >> s[i].y;
		sdist += get_dist(s[i], t)*2;
	}

	for (int i = 1; i <= n; i++)
	{
		v1.push_back(make_pair(get_dist(a, s[i])-get_dist(s[i],t), i));
		v2.push_back(make_pair(get_dist(b, s[i])-get_dist(s[i],t), i));
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	double ans = 1e18;

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (i >= v1.size() || j >= v2.size())
				continue;
			if (v1[i].second == v2[j].second)
				continue;
			int id1, id2;
			id1 = v1[i].second;
			id2 = v2[j].second;
			double am = sdist - get_dist(t, s[id1]) - get_dist(t, s[id2]) + get_dist(a, s[id1]) + get_dist(b, s[id2]);
			//cout << id1 << "%" << id2 << " " << am << endl;
			ans = min(ans, am);
		}
	}
//	cout << sdist << endl;

	for (int i = 1; i <= n; i++)
	{
		//cout << sdist - get_dist(t, s[i]) + get_dist(a, s[i]) << " " << sdist - get_dist(t, s[i]) + get_dist(b, s[i]) << endl;
		ans = min(ans, sdist - get_dist(t, s[i]) + get_dist(a, s[i]));
		ans = min(ans, sdist - get_dist(t, s[i]) + get_dist(b, s[i]));
	}
	cout.precision(12);

	cout << fixed<<ans << endl;

	cin.get(); cin.get();
	return 0;
}