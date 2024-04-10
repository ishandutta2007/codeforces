/*
Never good at talking, so many things I couldn't say
But those thoughts never went away
And I'm sure you remember, said that all I wanted was sympathy
Now add this to your memory

Too many times I felt so sad and lonely
Too many times I needed someone there
Too many times I tried to tell you something
Too many times it seemed like no one cared

And I don't like asking and it's not easy to say
I never learned how to pray
So if you have a moment it means
So much to me oh can't you see
If you'd just say a prayer for me

Too many times I didn't even have a second
Too many times you thought I was much too strong
Too many times you said the feeling wouldn't last forever
Too many times I proved you so damn wrong

When you saw the changes thought they'd go away
Do you still remember that day
I can't really fault you only have myself to blame
But do you still feel the same

Do ya, do ya, do ya, do ya, do ya?
But I waited so long for
Someone to take my hand, and say they understand
And I waited so long for
Someone to show the way to make a better day
And I waited so long for
Someone to spare a kiss for the love I miss

And I waited so long for you to look me in the eye
And say it's worth another try
But you keep me waiting waiting too many times
You keep me waiting waiting too many times

Many times
You keep me waiting
Many times, many times
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
#include <ctime> 
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define escape asdgasdgasdg

#define eps 1e-8
#define M_PI 3.141592653589793
//#define bs 1234567891
#define bsize 512

const int N = 1200;

using namespace std;

int n;
double p[N][N];
double escape_ev[N];
double total_ev[N];
set<pair<double,int> > S;
int used[N];
double escape[N];

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int val;
			cin >> val;
			p[i][j] = val*.01;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		escape[i] = 1.0;
		escape_ev[i] = 0;
		total_ev[i] = 1e9;
	}

	total_ev[n] = 0;

	for (int i = 1; i <= n; i++)
	{
		S.insert(make_pair(total_ev[i], i));
	}

	while (S.size())
	{
		pair<double, int> pp = *S.begin();
		S.erase(S.begin());
		int id = pp.second;
		
		used[id] = 1;

//		cout << id << " " << total_ev[id] << endl;

		for (int i = 1; i <= n; i++)
		{
			if (used[i])
				continue;
			S.erase(make_pair(total_ev[i], i));
			escape_ev[i] += escape[i] * p[i][id] * total_ev[id];
			//total_ev[i]=escape[i]*total_ev[i]+escape_ev[i]+1;
			//total_ev[i]*(1.0-escape[i])=escape_ev[i]+1;
			escape[i] = escape[i] * (1.0 - p[i][id]);
			//cout << escape[i] << endl;

			if (escape[i] < 1.0 - eps)
				total_ev[i] = (escape_ev[i] + 1) / (1.0 - escape[i]);
			else
				total_ev[i] = 1e9;
			S.insert(make_pair(total_ev[i], i));
		}
	}

	cout.precision(10);

	cout << fixed << total_ev[1] << endl;

	cin.get(); cin.get();
	return 0;
}