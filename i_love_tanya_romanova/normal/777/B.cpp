/*
I'm gazing upward, a world I can't embrace
There's only thorns and splinters, venom in my veins
It's okay to cry out, when it's driving you insane
But somehow someday, I'll have to face the pain

It's all gone cold
But no one wants the blame
It's all so wrong
But who am I, who am I to say?

I'm begging for forgiveness, everything I've done
If God is listening, He knows I'm not the only one
It's okay to lash out from the rules that I'm enslaved
But somehow someday, I'll have to turn the page

It's all gone cold
And no one wants to change
It's all so wrong
But no one wants the blame

It's all gone cold
There's nothing left to gain
It's all so wrong
But who am I, who am I to say?

My heart's an endless winter filled with rage
I'm looking forward to forgetting yesterday

It's all gone cold
And no one wants to change
It's all so wrong
But no one wants the blame

It's all gone cold
There's nothing left to gain
It's all so wrong
But who am I, who am I to say?
To say

It's all gone cold
But who am I to say?
It's all gone cold
But who am I, who am I to say?

Cold
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
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 111031;

int n;
string st1,st2;

bool can_eq(int am)
{
	for (int i=0;i<am;i++)
	{
		if (st1[i]>st2[st2.size()-am+i])
			return false;
	}
	return true;
}

bool can_beat(int am)
{
	for (int i=0;i<am;i++)
	{
		if (st1[i]>=st2[st2.size()-am+i])
			return false;
	}
	return true;
}

int main(){
//	freopen("explosion.in","r",stdin);
//	freopen("explosion.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	cin>>st1>>st2;

	sort(st1.begin(),st1.end());
	sort(st2.begin(),st2.end());

	int l,r;
	l=0;
	r=st1.size();
	while (l<r)
	{
		int mid=l+r+1;
		mid/=2;
		if (can_eq(mid))
			l=mid;
		else
			r=mid-1;
	}
	cout<<st1.size()-l<<endl;

	l=0;
	r=st1.size();
	while (l<r)
	{
		int mid=l+r+1;
		mid/=2;
		if (can_beat(mid))
			l=mid;
		else
			r=mid-1;
	}
	cout<<l<<endl;

	cin.get(); cin.get();
	return 0;
}