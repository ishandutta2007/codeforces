/*
The way the light hits the room
The way I am unable to protect you
Oh I'm running away
I will never forgive myself
For running away from you

He came back to our house
I didn't take it as a promise
Always thought it was a lie
He went too far the fucker
It's not like I owe him money
This is different

So gather your strength and break free
Or you will surely die
So gather your strength don't follow me
'Cause I will surely die

Way my eyes cannot move
Way I hope to be protected
And for one moment I thought
That I was lost among the lights of houses

He came back to our house
I didn't take it as a promise
Always thought it was a lie
He went too far the fucker
It's not like I owe him money
This is different

So gather your strength and break free
Or you will surely die
So gather your strength don't follow me
'Cause I will surely die

My dreams, dreams of violence
See them coming true
My dreams, dreams of violence
See them coming true

He came back to our house
I didn't take it as a promise
Always thought it was a lie
He went too far the fucker
It's not like I owe him money
This is different

So gather your strength and break free
Or you will surely die
So gather your strength don't follow me
'Cause I will surely die
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
#define bsize 512

const int N = 1000000;

using namespace std;

int n, m, s, d, ar[N];
vector<pair<int, int> > segs;
int shit;
int cur;
vector<pair<int, int> > ops;

void add_operation(int tp, int val)
{
	ops.push_back(make_pair(tp, val));
	cur += val;
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> m >> s >> d;
	
	for (int i = 0; i < n; i++)
	{
		cin >> ar[i];
	}

	sort(ar, ar + n);

	for (int i = 1; i < n; i++)
	{
		if (ar[i]>=ar[i - 1] + s + 2)
		{
			segs.push_back(make_pair(ar[i - 1] + 1, ar[i] - 1));
		}
	}

	if (ar[0]>1)
	{
		add_operation(1, ar[0] - 1);
	}

	if (ar[0] <= s)
		shit = 1;

	for (int i = 0; i < segs.size(); i++)
	{
		int dist = segs[i].first - cur;
		if (dist>d)
			shit = 1;
		add_operation(0, dist);
		add_operation(1, segs[i].second - segs[i].first);
	}

	if (ar[n - 1]+1 - cur > d)
		shit = 1;
	add_operation(0, ar[n - 1]+1 - cur);
	if (ar[n - 1] != m - 1)
		add_operation(1, m - ar[n - 1] - 1);

	if (shit)
	{
		cout << "IMPOSSIBLE" << endl;
	}
	else
	{
		for (int i = 0; i < ops.size(); i++)
		{
			if (ops[i].first == 1)
				cout << "RUN ";
			else
				cout << "JUMP ";
			cout << ops[i].second;
			cout << "\n";
		}
	}

	cin.get(); cin.get();
	return 0;
}