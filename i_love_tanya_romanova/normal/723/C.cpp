/*
I don't need no license
To sign on no line
And I don't need no preacher
To tell me you're mine
I don't need no diamonds
I don't need no new bride
I just need you, baby
To look me in the eye

I know they have a hand time
And your Daddy don't approve
But I don't need your Daddy
Telling us what we should do

Now there's a million questions
I could ask about our lives
But I only need one answer
To get me through the night

So baby, can you tell me just where we fit in
I call it love they call it living in sin
Is it you and me or just this world we live in
I say we're living on love they say we're living in sin

Is it right for both our parents
Who fight it out most nights
Then pray for God's forgiveness
When they both turn out the lights
Or wear that ring of diamonds
When your heart is made of stone
You can talk but still say nothing
You stay together but alone

Or is it right to hold you
And kiss your lips goodnight
They say the promise is forever
If you sign it on the dotted line

Baby, can you tell me just where we fit in
I call it love they call it living in sin
Is it you and me or just this world we live in
I say we're living on love they say we're living in sin

Baby, can you tell me just where we fit in
I call it love they call it living in sin
Is it you and me or just this world we live in
I say we're living on love they say we're living in sin

I call it love they call it living in sin

Living in sin

I don't know where to begin
I don't know where we fit in

Living in sin
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

int n, m, VAL;
int ar[N];
int cnt[N];
int ANS;

void run_prec()
{
	for (int i = 1; i <= m; i++)
	{
		cnt[i] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		if (ar[i] <= m)
			cnt[ar[i]]++;
	}
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> m;
	VAL = n / m;
	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
	}

	while (true)
	{
		run_prec();
		int flag = 0;
		for (int i = 1; i <= m; i++)
		{
			if (cnt[i] < VAL)
				flag = i;
		}
		if (flag == 0)
			break;
		int Q = 0;
		for (int i = 1; i <= n; i++)
		{
			if (ar[i]>m)
				Q = i;
		}
		if (Q == 0)
		{
			for (int i = 1; i <= n; i++)
			{
				if (cnt[ar[i]] > VAL)
					Q = i;
			}
		}
		ar[Q] = flag;
		++ANS;
	}

	cout << VAL << " " << ANS << endl;
	for (int i = 1; i <= n; i++)
	{
		if (i > 1)
			cout << " ";
		cout << ar[i];
	}
	cout << endl;

	cin.get(); cin.get();
	return 0;
}