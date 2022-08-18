/*
Have you ever felt this way before?
(Felt this way)
Pushed to be someone you don't know
(I don't know)

I've never felt this way before
(Felt this way)
Pushed to be someone I don't know

People telling lies all the time
(Another part of this pointless game)
I don't wanna be part of your lie

Give me a chance and you'll know
(Who I wanna be)
Give me a chance to figure it out
(Who I am)

I've told you what I have to say
(I've told you)
You never listened and you pushed me away

People telling lies all the time
(Another part of this pointless game)
I don't wanna be part of your lie

Give me a chance and you'll know
(Who I wanna be)
Give me a chance to figure it out
(Who I am)

Give me a chance and you'll know
(Who I wanna be)
Give me a chance to figure it out
(Who I am)

(Now)
Just give me my life back
(So)
I'm taking it back now
(No)
You never will take me in vain

I've told you what I have to say
(I've told you)
You never listened and you pushed me away

Give me a chance and you'll know
(Who I wanna be)
Give me a chance to figure it out
(Who I am)

Give me a chance and you'll know
(Who I wanna be)
Give me a chance to figure it out
(Who I am)
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

#define eps 1e-12
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 100031;

int n;
vector<int> g[N];
int subsize[N];

void dfs(int v)
{
	subsize[v] = 1;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		dfs(to);
		subsize[v] += subsize[to];
	}
}

double res[N];

void solve(int v)
{
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		res[to] = res[v] + (subsize[v] - subsize[to] - 1)*0.5 + 1;
		solve(to);
	}
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;

	for (int i = 2; i <= n; i++)
	{
		int v;
		//cin >> v;
		scanf("%d", &v);

		g[v].push_back(i);
	}

	dfs(1);

	solve(1);

	for (int i = 1; i <= n; i++)
	{
		if (i > 1)
			printf(" ");
		printf("%.8lf", res[i]+1);
	}
	puts("");

	cin.get(); cin.get();
	return 0;
}