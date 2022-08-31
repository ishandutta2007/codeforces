/*
To ends unknown
By means unworthy
To answer wishes
Long dead and gone
Old empty promises
A just reward for the blind
Belief makes work for idle minds
We lost our way

The only dream that matters
Is the one you wake up from

Go

Onward to the singularity
Whatever they say
Whatever they do just go
Turn on this unentity
Whatever they say
Whatever they do just go
We are faithless by default

I call for a world where we are nothing
More than the sum of what we know
Are we to be held hostage
By our tolerance for the intolerant
Then we've lost our way

To hope is to surrender
In this series of defeats

Go

Onward to the singularity
Whatever they say
Whatever they do just go
Turn on this unentity
Whatever they say
Whatever they do just go
We are faithless by default
Weve lost our way
A pain far too familiar
Denounce your savage self

Go

Onward to the singularity
Whatever they say
Whatever they do just go
Turn on this unentity
Whatever they say
Whatever they do just go
We are faithless by default
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
const int N = 200031;

string st;
int which_at[100500];
int ans[100500];

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>st;
	for (int i=0;i<st.size();i++)
	{
		if (st[i]=='!')
			continue;
		which_at[i%4]=st[i];
	}

	for (int i=0;i<st.size();i++)
	{
		if (st[i]=='!')
			ans[which_at[i%4]]++;
	}

	cout<<ans['R']<<" "<<ans['B']<<" "<<ans['Y']<<" "<<ans['G']<<endl;

	cin.get(); cin.get();
	return 0;
}