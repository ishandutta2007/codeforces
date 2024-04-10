/*
Are we so alone,
So distant,
So forgotten,
As we think ourselves to be?

These are our lives
But did they ever even matter?
Are we worth remembering?

These machines feed on the tears
Of broken lives and dying dreams
We're throwing wrenches in the gears
Our lives will not be lived in vain

When this is all said and done
We spent this life on the run
Judged by the company we keep

Our language, buried inside
These lungs that keep us alive
We breathe so selfishly

Promises we plan to break
Are made in whispered voices
Cause our despair knows many names

We make mistakes
But we apologize with roses
We never stop to smell along the way

These machines feed on the tears
Of broken lives and dying dreams
We're throwing wrenches in the gears
Our lives will not be lived in vain

When this is all said and done
We spent this life on the run
Judged by the company we keep

Our language, buried inside
These lungs that keep us alive
We breathe so selfishly

We fell from the sky today
We melt into balls of clay
We sell ourselves everyday
Don't tell me how to live this way

Pushed so far to the edge
We teeter just on the brink
You can lead me to the bloodbath
But you can't make me drink

As these machines feed on the tears
Of broken lives and dying dreams
We're throwing wrenches in the gears
Our lives will not be lived in vain
My life will not be lived in vain
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

const int N = 100031;

int n,l[N],r[N];
vector<int> starts,ends;

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>l[i]>>r[i];
		if (l[i]==0)
		{
			starts.push_back(i);
		}
	}

	for (int i=0;i<starts.size();i++)
	{
		int id=starts[i];
		while (r[id]!=0)
			id=r[id];
		ends.push_back(id);
	}
	for (int i=0;i+1<ends.size();i++)
	{
		r[ends[i]]=starts[i+1];
		l[starts[i+1]]=ends[i];
	}

	for (int i=1;i<=n;i++)
	{
		cout<<l[i]<<" "<<r[i]<<endl;
	}

	cin.get(); cin.get();
	return 0;
}