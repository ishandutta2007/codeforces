/*
To my mother, to my father,
It's your son or it's your daughter,
Are my screams loud enough for you to hear me?
Should I turn this up for you?

I sit here locked inside my head
Remembering everything you said
The silence gets us nowhere!
Gets us nowhere way too fast!

The silence is what kills me
I need someone here to help me
But you don't know how to listen
And let me make my decisions

I sit here locked inside my head
Remembering everything you said
The silence gets us nowhere!
Gets us nowhere way to fast!

All your insults and your curses make
me feel like I'm not a person
And I feel like I am nothing but
you made me so do something
'Cause I'm fucked up because you are
Need attention, attention you couldn't give

I sit here locked inside my head
Remembering everything you said
The silence get us nowhere!
Gets us nowhere way to fast
*/

//#pragma GCC optimize("O3")
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
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 300031;

string st;
string S[N];
int n,ok;

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>st;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>S[i];
		if (S[i]==st)
			ok=1;
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++)
		{
			if (S[i][1]==st[0]&&S[j][0]==st[1])
				ok=1;
		}
	}

	if (ok)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

	cin.get(); cin.get();
	return 0;
}