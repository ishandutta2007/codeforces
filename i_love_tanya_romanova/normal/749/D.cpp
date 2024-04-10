/*
Give us the death of creation.
Bring famine, flood and plague to end our tortured existence.
Let us suffer forevermore.
We forged this path of resistance and died for an empty cause when there was nothing to live for.
Let us suffer forevermore.
Is this the reason we bleed?
We never thought to question why.
A life lived in fear is so meaningless.
Open your eyes.
Is this what we've suffered for?
Hopeless and self-deprived, we are forever discontent.
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
int a[N], b[N];
vector<int> entries[N];
set<pair<int, int> > L;
set<pair<int, int> > ::iterator it;
int last_entry[N];
int tests, sz, id[N];

int get_winner()
{
	if (L.size() == 0)
		return 0;
	it = L.end();
	--it;
	if ((*it).first == 0)
		return 0;
	return (*it).second;
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//	freopen("F:/input.txt", "r", stdin);
	//	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i];
	}
	
	for (int i = 1; i <= n; i++)
	{
		entries[a[i]].push_back(i);
	}

	for (int i = 1; i <= n; i++)
	{
		last_entry[a[i]] = i;
	}

	for (int i = 1; i <= n; i++)
	{
		L.insert(make_pair(last_entry[i], i));
	}

	cin >> tests;
	for (; tests; --tests)
	{
		cin >> sz;
		for (int i = 1; i <= sz; i++)
		{
			cin >> id[i];
			L.erase(make_pair(last_entry[id[i]], id[i]));
		}
		int ans = get_winner();
		//cout << ans << endl;

		if (ans == 0)
		{
			for (int i = 1; i <= sz; i++)
			{
				L.insert(make_pair(last_entry[id[i]], id[i]));
			}
			cout << 0 << " " << 0 << "\n";
			continue;
		}
		L.erase(make_pair(last_entry[ans], ans));
		int qp;
		if (L.size() == 0)
			qp = 0;
		else
		{
			it = L.end();
			--it;
			pair<int,int> here = (*it);
			qp = here.first;
		}
		int win_move = lower_bound(entries[ans].begin(), entries[ans].end(), qp) - entries[ans].begin();
		win_move = entries[ans][win_move];
		
		cout << ans << " " << b[win_move] << "\n";
		L.insert(make_pair(last_entry[ans], ans));
		for (int i = 1; i <= sz; i++)
		{
			L.insert(make_pair(last_entry[id[i]], id[i]));
		}
	}
	cin.get(); cin.get();
	return 0;
}