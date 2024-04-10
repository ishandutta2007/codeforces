/*
From the middle of the room she hears the conversation moving, further from where she's going without even knowing.
Now the vibrations in the floor are getting closer to the door, and is this the way you let your problems drift away to?

I climb so high, it blows me away sometimes, see through my holes, into this place I call my own.
This time I'll try, it's in the air tonight, sleep tonight, no more cryin.
Cause I've got you on my side.

I don't want you to be anything at all, I just want you to say you love me, I don't care, just stop living life like this.
I don't want to be anything at all, I just want you to see who I am, and stop the violence, no more silence.

From the middle of the room she hears the conversation moving, further from where she's going without even knowing.
Now the vibrations in the floor are getting closer to the door, and is this the way you let your problems drift away to?

I don't want you to be anything at all, I just want you to say you love me, I don't care, just stop living life like this.
I don't want to be anything at all, I just want you to see who I am, and stop the violence, no more silence.

I'm gonna show ya I'm alive, breathing clearly for the first time, take my in your arms, take me to the place you are.
I needed time to clear my mind, keeping balanced on this line was impossible before I met you.
I climb so high, it blows me away sometimes, sleep tonight, no more cryin.
Cause I've got you on my side.

I don't want you to be anything at all, I just want you to say you love me, I don't care, just stop living life like this.
I don't want to be anything at all, I just want you to see who I am, and stop the violence, no more silence.

I'll shout from the top of the rooftop singing, I'm not afraid of the bed I lay in.
Listen to the sound of the voices ringing, I can't deny it, no more silence.
We'll shout from the top of the rooftop singing, I'm not afraid of the bed I lay in.
Listen to the sound of the voices ringing, I can't deny it, no more silence.
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

#define eps 1e-6
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 337

using namespace std;

const int INF = 1e9;
const int N = 400031;


int t[N];
int up[N][20];

long long dep[N];
int n;
long long w[N], a[N];
vector<int> g[N];
int timer;
int p[N];
int bal[N];

void update(int v, long long thold)
{
	for (int i = 19; i >= 0; --i)
	{
		if (dep[up[v][i]] >= thold)
			v = up[v][i];
	}
	if (v == 1)
		return;
	v = up[v][0];
	bal[v]--;
}

void dfs(int v,int p)
{
	bal[v] += 1;
	up[v][0] = p;
	for (int i = 1; i < 20; i++)
	{
		up[v][i] = up[up[v][i - 1]][i - 1];
	}

	update(v, dep[v] - a[v]);

	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		dfs(to,v);
	}
}

int ans[N];

void solve(int v)
{
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		solve(to);
		bal[v] += bal[to];
	}
	ans[v] = bal[v];
}

void trace(int v)
{
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		dep[to] = dep[v] + w[to];
		trace(to);
	}
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/input.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	for (int i = 2; i <= n; i++)
	{
		cin >> p[i] >> w[i];
		g[p[i]].push_back(i);
	}

	trace(1);

	dfs(1,1);
	solve(1);

	for (int i = 1; i <= n; i++)
	{
		if (i > 1)
			cout << " ";
		cout << ans[i]-1;
	}
	cout << endl;

	cin.get(); cin.get();
	return 0;
}