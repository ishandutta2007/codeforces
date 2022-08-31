/*
I don't believe, I don't believe
I don't

I learned about America from my first day in school
Land of opportunity, land of the free
They told us we were blessed and fortunate
But they turned away my questions on homelessness

I don't believe
(I don't believe)
I don't believe
(I don't believe)
I don't believe
(I don't believe)

I don't believe
(I don't believe)
I don't believe
(I don't believe)

Born into a national identity
A citizenship that defines the word free
But if we're so fucking free
Why don't we even get a choice?
I never choose to be a citizen
There was no choice given to make

I don't believe
(I don't believe)
I don't believe
(I don't believe)

I don't believe
(I don't believe)
I don't believe
(I don't believe)
I don't believe

I don't believe in America
Or the American dream
I don't believe in nationalism
We're all the same

Until the rich old men who control the world
Find something they can't have
And they send us out there to kill each other
Let the rich fight their wars themselves

I don't believe, I don't believe
I don't believe, I don't believe
I don't believe, I don't believe
I don't believe, I don't believe

I don't believe, I don't believe
(You've got nothing to gain by fighting for them)
I don't believe, I don't believe
(You've got nothing to gain by fighting for them)

You've got nothing to gain by fighting for them
You've got nothing to gain by fighting for them
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
const int N = 200031;

int cnt[1 << 21];
int tests;
string st;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tests;
	for (; tests; --tests)
	{
		cin >> st;
		if (st == "+" || st == "-")
		{
			string temp;
			cin >> temp;
			reverse(temp.begin(), temp.end());
			while (temp.size() < 20)
				temp += "0";
			reverse(temp.begin(), temp.end());
			int mask = 0;
			for (int i = 0; i < temp.size(); i++)
			{
				mask = mask * 2 + temp[i] % 2;
			}
			if (st == "+")
				cnt[mask]++;
			else
				cnt[mask]--;
		}
		else
		{
			string temp;
			cin >> temp;
			reverse(temp.begin(), temp.end());
			while (temp.size() < 20)
				temp += "0";
			reverse(temp.begin(), temp.end());
			int mask = 0;
			for (int i = 0; i < temp.size(); i++)
			{
				mask = mask * 2 + temp[i] % 2;
			}
			cout << cnt[mask] << "\n";
		}
	}

	cin.get(); cin.get();
	return 0;
}