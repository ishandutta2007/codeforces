/*
5th of May, V-Day is just around the corner
1945 the fuhrer reign is at its end

Jenny at the gates, as the SS open fire
There's no time to waste, the final battle has begun

After the downfall, a castle besieged
Facing the Nazis awaiting relief
Gangl and Lee and their men set the prisoners free

An it's the end of the line of the final journey
Enemies leaving the past
And it's American troops and the German army
Joining together at last

One last fight. It's the death throes of the 3rd Reich
Justice shall be done. The final battle remains

Ammo is running low, they're depleting their machine guns
Every bullet counts until surrender is announced

After the downfall, a castle relieved
Defeating the Nazis who held them besieged
Gangl and Lee and their men set the prisoners free

From the foot of the alps to the shores of the sea
From the foot of the alps to the shores of the sea
From the home of the brave, from the land of the free
From the foot of the alps to the shores of the sea
*/

#pragma GCC optimize("O3")
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

#define eps 1e-11
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007
const int N = 500031;

int used[N];
vector<int> g[N];
double dp[N];
int n;

void solve(int v)
{
	used[v]=1;
	double s=0;
	int cnt=0;
	for (int i=0;i<g[v].size();i++)
	{
		int to=g[v][i];
		if (used[to])
			continue;
		solve(to);
		s+=dp[to];
		++cnt;
	}
	if (cnt)
	{
		dp[v]=(s+cnt)*1.0/cnt;
	}
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	solve(1);

	cout.precision(15);
	cout<<fixed<<dp[1]<<endl;

	cin.get(); cin.get();
	return 0;
}