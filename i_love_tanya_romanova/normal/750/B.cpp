/*
I fuck 'em, just to see the look on their face
I fuck 'em, just to see the look on their face
I fuck 'em, just to see the look on their face

I say it out loud
I'm freaky styley
And I'm proud

I say it out loud
I'm freaky styley
And I'm proud

I say it out loud
I'm freaky styley
And I'm proud

I fuck 'em, just to see the look on their face
I fuck 'em, just to see the look on their face
I fuck 'em, just to see the look on their face

I'm freaky styley
And I'm proud
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
#define bsize 337

using namespace std;

long long INF = 1e9;
const int N = 200031;

int n, dist;
string st;
int cur;

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//	freopen("F:/input.txt", "r", stdin);
	//	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	int ok = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> dist;
		cin >> st;
		if (cur == 0 || cur == 20000)
		{
			if (cur == 0 && st != "South")
				ok = 0;
			if (cur == 20000 && st != "North")
				ok = 0;
		}
		if (st == "East" || st == "West")
			continue;
		if (st == "North")
		{
			cur -= dist;
		}
		else
			cur += dist;
		if (cur<0 || cur>20000)
			ok = 0;
	}
	if (cur)
		ok = 0;

	if (ok)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	cin.get(); cin.get();
	return 0;
}