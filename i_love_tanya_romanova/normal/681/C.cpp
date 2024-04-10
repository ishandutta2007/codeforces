/*
I got some serious troubles
I have some issues
I have a big obsession
And it's for killing you!

I want to run you over
I want to stab your throat
I want you in some cement shoes
Getting thrown off of a boat!

There is one way
Only one way
To ease this pain
To ease this pain
It will resolve
When I know your dead
In a casket today
Nailed casket today
I'll seal your fate
Death is at your door
There's only one way to go

So now that you've heard my message
Don't say you weren't forewarned
I'm gonna cause you so much pain
You'll wish that you weren't born
Your gonna meet your maker
Your gonna rot in hell
I'll make sure the last thing you see
Is me here with a smile
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
string st;
int val;
multiset<int> S;
multiset<int>::iterator it;
vector<pair<int, int> > ans;

int get_min()
{
	if (S.size() == 0)
		return 2e9;
	it = S.begin();
	return *it;
}

void add_move(int val, int tp)
{
	ans.push_back(make_pair(val, tp));
	if (tp == 3)
	{
		it = S.begin();
		assert((*it) == val);
		S.erase(it);
	}
	if (tp == 2)
	{
		return;
	}
	if (tp == 1)
	{
		S.insert(val);
	}
}

void show_move(pair<int,int> p)
{
	int val = p.first;
	int tp = p.second;

	if (tp == 3)
	{
		cout << "removeMin" << "\n";
	}
	if (tp == 2)
	{
		cout << "getMin " << val << "\n";
	}
	if (tp == 1)
	{
		cout << "insert " << val << "\n";
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
		cin >> st;
		if (st == "insert")
		{
			cin >> val;
			add_move(val, 1);
			continue;
		}
		if (st == "getMin")
		{
			int val;
			cin >> val;
			while (true)
			{
				int val2 = get_min();
				//cout << val2 << endl;
				if (val2 > val)
				{
						add_move(val, 1);
				}
				else if (val2 < val)
				{
					add_move(val2, 3);
				}
				else
					break;
			}
			add_move(val, 2);
			continue;
		}
		if (get_min()>1e9)
		{
			add_move(1, 1);
		}
		int Q = get_min();
		add_move(Q, 3);
	}
	
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
	{
		show_move(ans[i]);
	}

	cin.get(); cin.get();
	return 0;
}