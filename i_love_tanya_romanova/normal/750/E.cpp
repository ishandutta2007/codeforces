/*
Standing naked in your kitchen
Feeling free that I could be alive
Clearly I'm a contradiction
Too young to be my wife

A peaceful storm is never hectic
Her mellow voice that I could be within
The uniform is anorexic
A jealous choice won't win

A metamorphosis samurai
Y'got a little lord fish and I don't know why I got a
Metamorphosis samurai

Paint your face cause I'm a black foot
I thought I counted up the fireflies
Close enough to get a good look
Time to mobilize

A metamorphosis samurai
Y'got a little lord fish and I don't know why I got a
Metamorphosis samurai

I'm a lonely lad
I've lost myself out on the range
I don't remember much
So don't ask me I've gone insane

Taking acid in a graveyard
Stealing food to keep the night alive
Every day I try to play hard
Even with my lies

The day they found you on a tour bus
The news was barren as a desert bone
The tabloids made a kind of small fuss
A couple pictures shown

I'm a lonely lad
I've lost myself out on the range
I don't remember much
So don't ask me I've gone insane

Slowly turning into driftwood
No one ever wants to die alone
Thinking that a pretty gift could
Make you less unknown

Dirty sneakers on the pavement
The brilliant features of a common man
See the miracle of your life
No one ever can

I'm a lonely lad
I've lost myself out on the range
I don't remember much
So don't ask me I've gone insane

See the world go by
The changes that we entertain
I don't recall it all
Remember I have gone insane
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
#define bsize 512

using namespace std;

long long INF = 1e9;
const int N = 200031;

int n, tests;
string st;

int sparse[N][18][15]; 
int maps[20][20];

vector<int> combine(vector<int> &v, int ps, int lev)
{
	vector<int> ret;
	ret = v;
	for (int i = 0; i <= 4; i++)
	{
		ret[i] = 1e9;
	}
	for (int i = 0; i <= 4; i++)
	{
		for (int j = i; j <= 4; j++)
		{
			ret[j] = min(ret[j], v[i] + sparse[ps][lev][maps[i][j]]);
		}
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
	
	string Z = "2017";

	cin >> n >> tests;

	//n = 200000;
	//tests = 200000;


	int P = 0;

	for (int i = 0; i <= 4; i++)
	{
		for (int j = i; j <= 4; j++)
		{
			maps[i][j] = P;
			++P;
		}
	}

	getline(cin, st);
	getline(cin, st);

	for (int i = 0; i < 200000; i++)
	{
		st += "0";
	}
//	cout << P << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			sparse[i][0][j] = 1e9;
		}

		for (int done1 = 0; done1 <= 4; done1++)
		{
			// remove
			sparse[i][0][maps[done1][done1]] = min(sparse[i][0][maps[done1][done1]],1);

			// stay
			if (done1 >=3&&st[i]=='6') // 2016
				continue;
			int new_done = done1;
			if (new_done != 4 && st[i] == Z[new_done])
				++new_done;
			sparse[i][0][maps[done1][new_done]] = min(sparse[i][0][maps[done1][new_done]], 0);
		}
	}

//	cout << sparse[0][0][1] << endl;

	for (int lev = 1; lev < 18; lev++)
	{
		for (int i = 0; i < n; i++)
		{
			if (i + (1 << lev)>n)
				continue;
			for (int q = 0; q < 15; q++)
			{
				sparse[i][lev][q] = 1e9;
			}

			for (int done1 = 0; done1 <= 4; done1++)
			{
				for (int done2 = done1; done2 <= 4; done2++)
				{
					for (int done3 = done2; done3 <= 4; done3++)
					{
						sparse[i][lev][maps[done1][done3]] = min(sparse[i][lev][maps[done1][done3]], sparse[i][lev - 1][maps[done1][done2]] +
							sparse[i + (1 << lev) / 2][lev - 1][maps[done2][done3]]);
					}
				}
			}
		}
	}


	for (; tests; --tests)
	{
		int l, r;
		scanf("%d", &l);
		scanf("%d", &r);
		--l;
		--r;
		/*l = 0;
		r = (1 << 17) - 2;
		*/
		vector<int> here;
		for (int j = 0; j <= 4; j++)
		{
			here.push_back(1e9);
		}
		here[0] = 0;
		for (int i = 17; i >= 0; --i)
		{
			if (l + (1 << i) <= r + 1)
			{
				here = combine(here, l, i);
				l += (1 << i);
			}
		}

	/*	for (int i = 0; i <= 4; i++)
		{
			cout << here[i] << " ";
		}
		cout << endl;
		*/
		if (here[4] > 1e8)
			printf("%d\n", -1);
		else
			printf("%d\n", here[4]);
	}

	cin.get(); cin.get();
	return 0;
}