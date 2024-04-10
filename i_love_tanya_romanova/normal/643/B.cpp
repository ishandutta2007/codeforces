/*
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

int n, k, v1, v2, u1, u2;
vector<int> order1, order, order2;
int used[N];

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> k;
	cin >> v1 >> v2 >> u1 >> u2;
	
	if (n == 4)
	{
		cout << -1 << endl;
		return 0;
	}

	int need = n + 1;
	if (k < need)
	{
		cout << -1 << endl;
		return 0;
	}

	used[v1] = 1;
	used[v2] = 1;
	used[u1] = 1;
	used[u2] = 1;

	order.push_back(v1);
	order.push_back(u1);

	for (int i = 1; i <= n; i++)
	{
		if (used[i])
			continue;
		order.push_back(i);
	}

	order.push_back(u2);
	order.push_back(v2);

	for (int i = 0; i < order.size(); i++)
	{
		if (i)
			cout << " ";
		cout << order[i];
	}
	cout << endl;
	order2.push_back(order[1]);
	order2.push_back(order[0]);

	for (int i = 2; i < order.size() - 2; i++)
	{
		order2.push_back(order[i]);
	}
	order2.push_back(order.back());
	order2.push_back(order[order.size() - 2]);

	order = order2;

	for (int i = 0; i < order.size(); i++)
	{
		if (i)
			cout << " ";
		cout << order[i];
	}
	cout << endl;

	cin.get(); cin.get();
	return 0;
}