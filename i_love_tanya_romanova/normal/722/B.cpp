/*
There must be something
In the way I feel
That she don't want me to feel
The stare she bares cut me
I don't care
You see so what if I bleed

I could never change
Just what I feel
My face will never show
What is not real

A mountain never seems to have
The need to speak
A look that shares so many seek
The sweetest feeling
I got from you
The things I said to you were true

I could never change
Just what I feel
My face will never show
What is not real

I could have lied I'm such a fool
My eyes could never never never
Keep their cool
Showed her and I told her how
She struck me but I'm fucked up now

But now she's gone yes she's gone away
A soulful song
That would not stay
You see she hides 'cause she is scared
But I don't care
I won't be spared

I could have lied I'm such a fool
My eyes could never never never
Keep their cool
Showed her and I told her how
She struck me but I'm fucked up now

I could have lied I'm such a fool
My eyes could never never never
Keep their cool
Showed her and I told her how
She struck me but I'm fucked up now
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

string st;
int n;
int ar[N];

int solve(string st)
{
	int res = 0;
	for (int i = 0; i < st.size(); i++)
	{
		if (st[i] == 'a' || st[i] == 'e' || st[i] == 'o' || st[i] == 'i' || st[i] == 'u' ||
			st[i] == 'y')
			++res;
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
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
	}
	getline(cin, st);
	for (int i = 1; i <= n; i++)
	{
		getline(cin, st);
		int here = solve(st);
		if (here != ar[i])
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;

	cin.get(); cin.get();
	return 0;
}