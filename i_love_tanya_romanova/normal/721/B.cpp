/*
They come from every state to find
Some dreams were meant to be declined
Tell the man what did you have in mind
What have you come to do?

No turning water into wine
No learning while you're in the line
I'll take you to the broken sign
You see these lights are blue

Come and get it
Lost it at the city limit
Say goodbye
'Cause they will find a way to trim it
Everybody
Lookin' for a silly gimmick
Gotta get away
Can't take it for another minute

This town is made of many things
Just look at what the current brings
So high, it's only promising
This place was made on you

Tell me, baby, what's your story
Where you come from
And where you wanna go this time?
Tell me, lover, are you lonely?
The thing we need is
Never all that hard to find
Tell me, baby, what's your story
Where do you come from
And where you wanna go this time?
You're so lovely, are you lonely?
Giving up on the innocence you left behind

Some claim to have the fortitude
Too shrewd to blow the interlude
Sustaining pain to set a mood
Step out to be renewed

I'll move you like a baritone
Jungle brothers on the microphone
Getting over with an undertone
It's time to turn to stone

Chitty chitty, baby
When your nose is in the nitty gritty
Life could be a little sweet
But life could be a little shitty
What a pity
Boston and a Kansas city
Looking for a hundred
But you only ever found a fitty

Three fingers in the honeycomb
You ring just like a xylophone
Devoted to the chromosome
The day that you left home

Tell me, baby, what's your story
Where you come from
And where you wanna go this time?
Tell me, lover, are you lonely?
The thing we need is
Never all that hard to find
Tell me, baby, what's your story
Where you come from
And where you wanna go this time?
You're so lovely, are you lonely?
Giving up on the innocence you left behind

Tell me, baby, what's your story
Where you come from
And where you wanna go this time?
Tell me, lover, are you lonely?
The thing we need is
Never all that hard to find
Tell me, baby, what's your story
Where you come from
And where you wanna go this time?
You're so lovely, are you lonely?
Giving up on the innocence you left behind
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
#define have adsgagshdshfhds

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 200031;

int n, k;
vector<string> words;
vector<pair<string, int> > v;

bool cmp(pair<string, int> p1, pair<string, int> p2)
{
	if (p1.first.size() != p2.first.size())
		return p1.first.size() < p2.first.size();
	return p1.second>p2.second;
}

int eval(vector<pair<string, int> >v)
{
	int cnt_bad = 0;

	int res = 0;
	for (int i = 0; i < v.size(); i++)
	{
		res += 1;
		if (v[i].second == 1)
		{
			return res;
		}
		cnt_bad += 1;
		if (cnt_bad == k)
		{
			res += 5;
			cnt_bad = 0;
		}
	}
	return res;
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		string st;
		cin >> st;
		words.push_back(st);
	}

	string Z;

	cin >> Z;
	for (int i = 0; i < words.size(); i++)
	{
		if (words[i] == Z)
			v.push_back(make_pair(words[i], 1));
		else
			v.push_back(make_pair(words[i], 0));
	}

	sort(v.begin(), v.end(), cmp);
	cout << eval(v) << " ";
	for (int i = 0; i < v.size(); i++)
	{
		if (i + 1 < v.size() && v[i].first.size() == v[i + 1].first.size() && v[i].second == 1)
			swap(v[i], v[i + 1]);
	}
	cout << eval(v) << endl;

	cin.get(); cin.get();
	return 0;
}