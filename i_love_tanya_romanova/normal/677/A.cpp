/*
I'm feelin' so good right now
There's a handsome boy tells me how I changed his past
He buys me a brandy
But could it be he's really just after my ass?

He likes the clothes I wear
He says he likes a man who's dressed in season
But no-one else ever stares, he's being so kind
What's the reason?

How many friends have I really got?
You can count 'em on one hand
How many friends have I really got?
How many friends have I really got?
That love me, that want me, that'll take me as I am?

Suddenly it's the silver screen
And a face so beautiful that I have to cry out
Everybody hears me
But I look like a fool now
With a cry and I shy out
She knows all of my friends
But it's nice to find a woman who's keen on living
Now I think I've reached the end
I wonder in the dead of night - how do I rate?

How many friends have I really got?
How many friends have I really got?
How many friends have I really got?
That love me, that want me, that'll take me as I am?

It's all like a dream you know
When you're still up early in the morning
And you all sit together to watch the 1 come through
But things don't look so good
When you could use a bit of warning
Then you know that no-one will ever speak the truth about you

How many friends have I really got?
How many friends have I really got?
How many friends have I really got?
That love me, that want me, that'll take me as I am?

When I first signed a contract
It was more than a handshake then
I know it still is
But there's a plain fact
We talk so much shit behind each other's backs
I get the willies
People know nothing about their own soft gut
So how come they can sum us up
Without suffering all the hype we've known
How come they bum us up

How many friends have I really got?
You can count 'em on one hand
How many friends have I really got?
How many friends have I really got?
That love me, that want me, that'll take me as I am?
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
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 1040;

int n, h, ans;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> h;
	for (int i = 1; i <= n; i++)
	{
		int val;
		cin >> val;
		if (val > h)
			++ans;
	}
	cout << ans + n << endl;

	cin.get(); cin.get();
	return 0;
}