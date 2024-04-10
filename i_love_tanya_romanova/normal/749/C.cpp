/*
Hell waits for everyone.
It's not a question of belief.
We've found our souls now we will burn for it.
So give us damnation.
Eternal suffering.

We sought salvation when there was nothing left to save.
We'll watch the heavens burn tonight.
Praying for an answer when our salvation is death.
As dying voices fade, we're given something to believe.

Hell waits for everyone, and it will call us each by name, to take us home now.
We will burn for it.
So give us damnation.
Eternal suffering.

We sought salvation when there was nothing left to save.
We'll watch the heavens burn tonight.
Praying for an answer when our salvation is death.
As dying voices fade, we're given something to believe.

Pray for us all.
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
const int N = 200031;

int n;
string st;
int alive[N];
int clr[N];
set<int> S[10];
int last_alive;
set<int>::iterator it;

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//	freopen("F:/input.txt", "r", stdin);
	//	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	cin >> st;

	for (int i = 1; i <= n; i++)
	{
		alive[i] = 1;
		if (st[i - 1] == 'D')
			clr[i] = 1;
		else
			clr[i] = 2;
	}

	while (true)
	{
		S[1].clear();
		S[2].clear();

		for (int i = 1; i <= n; i++)
		{
			if (alive[i] == 0)
				continue;
			S[clr[i]].insert(i);
		}
		if (S[1].size() == 0 || S[2].size() == 0)
		{
			if (S[1].size())
				last_alive = 1;
			else
				last_alive = 2;
			break;
		}
		for (int i = 1; i <= n; i++)
		{
			if (alive[i] == 0)
				continue;
			int here = clr[i];
			int need = 3 - here;
			if (S[need].size() == 0)
			{
				last_alive = here;
				break;
			}
			it = S[need].lower_bound(i);
			if (it == S[need].end())
				it = S[need].begin();
			int val = (*it);
			S[need].erase(val);
			alive[val] = 0;
		}
	}

	if (last_alive == 1)
	{
		cout << "D" << endl;
	}
	else
		cout << "R" << endl;

	cin.get(); cin.get();
	return 0;
}