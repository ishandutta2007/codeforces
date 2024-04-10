/*
What brings this anger? To kill us and lie
Now we have hunger, our children will die
And they anchor, our strength to the ground
And will this banker, steal without sound

They fought a battle, to erase our race
They promised death, in a fiery place

In the middle of the night, the sirens calling
In the middle of the night, perished in flames

Now we are in danger, we can't survive
Locked with strangers, they're gonna burn us alive

In the middle of the night, the sirens calling
In the middle of the night, perished in flames
In the middle of the night, the masses praying
In the middle of the night, the ashes in air

Can't understand the hatred that's been unleashed on us
Our daily bread, been canceled by the press
A crown of stolen diamonds, won't last forever
Our spirit never dies and you'll pay the price
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

int n;
int ar[N];
map<int, int> used;
vector<int> order;
vector<int> ans;

vector<int> get_trace(int x)
{
	vector<int> res;
	while (x)
	{
		res.push_back(x);
		x /= 2;
	}
	reverse(res.begin(), res.end());
	return res;
}

vector<int> cur;

vector<int> run_merge(vector<int> a, vector<int> b)
{
	vector<int> res;
	int ptr1 = 0;
	int ptr2 = 0;
	while (ptr1 < a.size() || ptr2 < b.size())
	{
		if (ptr1 == a.size())
		{
			res.push_back(b[ptr2]);
			++ptr2;
		}
		else if (ptr2 == b.size())
		{
			res.push_back(a[ptr1]);
			++ptr1;
		}
		else if (a[ptr1] < b[ptr2])
		{
			res.push_back(a[ptr1]);
			++ptr1;
		}
		else
		{
			res.push_back(b[ptr2]);
			++ptr2;
		}
	}
	return res;
}

bool solve(int thold)
{
	vector<int> now;
	for (int i = 1; i <= n; i++)
	{
		int here = ar[i];
		while (here > thold)
			here /= 2;
		now.push_back(here);
	}
	sort(now.begin(), now.end());

	while (true)
	{
		bool ok = 1;
		/*for (int i = 0; i < now.size(); i++)
		{
			cout << now[i] << " ";
		}
		cout << endl;
		*/
		for (int i = 0; i < now.size(); i++)
		{
			if (now[i] == 0)
				return false;
		}

		for (int i = 1; i < now.size(); i++)
		{
			if (now[i] == now[i - 1])
				ok = 0;
		}
		if (ok)
		{
			cur = now;
			return true;
		}
		vector<int> list1, list2;
		for (int i = 0; i < now.size(); i++)
		{
			if (i!=0&&now[i] == now[i - 1])
			{
				list2.push_back(now[i] / 2);
			}
			else
			{
				list1.push_back(now[i]);
			}
		}
		/*for (int i = 0; i < cur.size(); i++)
		{
			cout << npw[i] << " ";
		}
		cout << endl;
		cout << thold << endl;
		
		for (int i = 0; i < list1.size(); i++)
		{
			cout << list1[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < list2.size(); i++)
		{
			cout << list2[i] << " ";
		}
		cout << endl;
		*/
		now = run_merge(list1, list2);
	}
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
	}
	int l, r;
	l = 1;
	r = 1e9;
	while (l < r)
	{
		int mid = l + r;
		mid /= 2;
		if (solve(mid))
			r = mid;
		else
			l = mid + 1;
	}

	solve(l);

	for (int i = 0; i < cur.size(); i++)
	{
		if (i)
			cout << " ";
		cout << cur[i];
	}
	cout << endl;

	cin.get(); cin.get();
	return 0;
}