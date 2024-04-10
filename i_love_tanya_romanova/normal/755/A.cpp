/*
Fear ties you up
And you don't grow
Being wrong and lost
No one admits the defeat

Conscience is fair
Unfaithful words
Betrayal and greed
Past thoughts to win alone

Envy - still strong
Hatred - still alive

From beyond - an empty world
Infected voice - a scream alone

Infected voice!

My throat is dry
A last cry tries to escape
Guilt and frustration
No time to turn around

Looking behind I'm not alone
Are they friends or enemies?
Going insane without a cure
Scarring my eyes, visions lost

Remorse for the human race
Fear of becoming them
Envy the strongest feeling
Hatred still in their heart

Envy - still strong
Hatred - still alive

From beyond - an empty world
Infected voice - a scream alone

Infected voice!
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 200031;

int n,ans;

bool prime(int x)
{
	for (int i=2;i*i<=x;i++)
	{
		if (x%i==0)
			return false;
	}
	return true;
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<=1000;i++)
	{
		if (!prime(i*n+1))
		{
			ans=i;
			break;
		}
	}
	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}