/*
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 337

using namespace std;

long long INF = 1e9;
const int N = 102231;

int n, ans[N];
vector<int> order[1000];

vector<int> make_query(vector<int> v)
{
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
	{
		if (i)
			cout << " ";
		cout << v[i];
	}
	cout << endl;
	vector<int> ret;
	for (int i = 1; i <= n; i++)
	{
		int val;
		cin >> val;
		ret.push_back(val);
	}
	return ret;
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//	freopen("F:/input.txt", "r", stdin);
	//	freopen("F:/output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		ans[i] = 1e9;
	}

	for (int bit = 0; bit < 10; bit++)
	{
		order[0].clear();
		order[1].clear();
		for (int i = 1; i <= n; i++)
		{
			if (i&(1 << bit))
				order[1].push_back(i);
			else
				order[0].push_back(i);
		}
		if (order[0].size())
		{
			vector<int> res = make_query(order[0]);
			for (int i = 1; i <= n; i++)
			{
				if (i&(1 << bit))
					ans[i] = min(ans[i], res[i - 1]);
			}
		}
		if (order[1].size())
		{
			vector<int> res = make_query(order[1]);
			for (int i = 1; i <= n; i++)
			{
				if (!(i&(1 << bit)))
					ans[i] = min(ans[i], res[i - 1]);
			}
		}
	}

	cout << -1 << endl;
	for (int i = 1; i <= n; i++)
	{
		if (i > 1)
			cout << " ";
		cout << ans[i];
	}
	cout << endl;

	//cin.get(); cin.get();
	return 0;
}