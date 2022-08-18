/*
I fall out of bed
Bang my head on the bedroom floor
It's one of those days
I know you've seen it all before
A bottle of Jack
And I'm ready to go again
Forget about it all
And wait for the show to begin

So come on, shout it
Give it all you've got, hey!
Your heart will be the way
Feel it, metal rules the will
You can't hear enough
And you won't sit still
You're ready, ready to rock
I know you're ready, ready to rock

Alcohol is burnin' puttin' pressure on me
The only way to fight back society

So come on, shout it
Give it all you got, hey!
Your heart will be the way
Feel it, metal rules the will
You can't hear enough
And you won't sit still
You're ready, ready to rock
I know you're ready, ready to rock

Ready to rock
I know you're ready, ready to rock
You're ready, ready to rock
I know you're ready, ready to rock
I know you're ready, ready to rock
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
const int N = 200031;

int n;
struct rect
{
	int x1;
	int y1;
	int x2;
	int y2;
};
vector<rect> known;

int query(int x1, int y1, int x2, int y2)
{
	cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	int val;
	cin >> val;
	for (int i = 0; i < known.size(); i++)
	{
		if (known[i].x1 >= x1&&known[i].x2 <= x2&&known[i].y1 >= y1&&known[i].y2 <= y2)
			--val;
	}
	return val;
}

rect run_solver()
{
	int l, r;
	l = 1;
	r = n;
	rect ret;
	while (l < r)
	{
		int mid = l + r+1;
		mid /= 2;
		int res = query(mid, 1, n, n);
		if (res>0)
		{
			l = mid;
		}
		else
			r = mid - 1;
	}

	ret.x1 = l;

	l = 1;
	r = n;
	while (l < r)
	{
		int mid = l + r + 1;
		mid /= 2;
		int res = query(ret.x1, mid, n, n);
		if (res>0)
			l = mid;
		else
			r = mid - 1;
	}
	ret.y1 = l;

	l = ret.x1;
	r = n;
	while (l < r)
	{
		int mid = l + r;
		mid /= 2;
		int res = query(ret.x1, ret.y1, mid, n);
		if (res>0)
			r = mid;
		else
			l = mid + 1;
	}
	ret.x2 = l;
	l = ret.y1;
	r = n;
	while (l < r)
	{
		int mid = l + r;
		mid /= 2;
		int res = query(ret.x1, ret.y1, ret.x2, mid);
		if (res>0)
			r = mid;
		else
			l = mid + 1;
	}
	ret.y2 = l;
	return ret;
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n;
	
	// find 
	
	rect temp=run_solver();
	known.push_back(temp);
	rect temp2 = run_solver();
	known.push_back(temp2);
	
	cout << "!";
	for (int i = 0; i < known.size(); i++)
	{
		cout << " " << known[i].x1 << " " << known[i].y1 << " " << known[i].x2 << " " << known[i].y2;
	}
	cout << endl;

	cin.get(); cin.get();
	return 0;
}