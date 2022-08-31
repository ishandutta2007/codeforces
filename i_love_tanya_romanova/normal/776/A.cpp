/*
Let me take you down
Deeper than you know
Reality is gone
Yet so much left to show
Let me take you down
Let us look inside
There's still so much to come
It's time to say goodbye

Broken dreams
Misery replaced by constant extasy
Wide awake open wide
existance of a better kind
Waits for you waits for me
Our minds become forever free
Free of fear free of rage
The coming of the Golden Age for all

Let me take you down
Let life fade away
The ritual has begun
Your life begins today
Let me take you down
Explore the other side
Enlightened as we drown
It's time to say goodbye

Don't you turn around now
Don't you be afraid now
Just turn another page now
Celebrate the Golden Age
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
const int N = 1211031;

string st[10];
int tests;

int main(){
//	freopen("explosion.in","r",stdin);
//	freopen("explosion.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>st[1]>>st[2];
	cout<<st[1]<<" "<<st[2]<<endl;
	cin>>tests;
	for (;tests;--tests)
	{
		string a,b;
		cin>>a>>b;
		for (int i=1;i<=2;i++)
		{
			if (st[i]==a)
				st[i]=b;
		}
		cout<<st[1]<<" "<<st[2]<<"\n";
	}


	cin.get(); cin.get();
	return 0;
}