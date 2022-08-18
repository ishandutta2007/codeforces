/*
Lock the bus undo the chain

She
She
She

Off the bus on to the chain
Getting all to hot, gotta head on 5th and main
I look like you I feel the same
You don't even know my name

I got this tied up to my cell
Well everybody's gone to the everybody shelf

Are you coming through, do you want me to, take your body
It would be so cool, to be cool with you, I said lordy lordy

I don't like blood into the chain
There aint a nelly man that stays up in my brain
A dirty sun will burn away
Do you even want to stay

Are you coming through, do you want me to, take your body
It would be so cool, to be cool with you, I said lordy lordy
Where'd you get that bruise, do you want me to,
take your body
I must still, taking your bod away

Are you coming through, do you want me to, take your body
It would be so cool, to be cool with you. I said lordy lordy
Where'd you get that bruise, do you want me to,
take your body
I must still, taking your bod away
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

int n;
int c[N];
int d[N];
int last2;

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//	freopen("F:/input.txt", "r", stdin);
	//	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i] >> d[i];
	}
	
	int cur = 0;
	int upr = 1e9;
	int lwr = -1e9;
	
	for (int i = 1; i <= n; i++)
	{
		if (d[i] == 1)
		{
			lwr = max(lwr, 1900 - cur);
		}
		else
		{
			upr = min(upr, 1899 - cur);
		}
		cur += c[i];
	//	cout << cur << endl;

	}

//	cout << lwr << " " << upr << endl;

	if (lwr > upr)
	{
		cout << "Impossible" << endl;
	}
	else
	{
		if (upr > 8e8)
		{
			cout << "Infinity" << endl;
		}
		else
		{
			cout << upr+cur << endl;
		}
	}

	cin.get(); cin.get();
	return 0;
}