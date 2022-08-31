/*
Unknown man
Speaks to the world
Sucking your trust
A trap in every world

War for territory
War for territory

Choice control
Behind propaganda
Poor information
To manage your anger

War for territory
War for territory

Dictators' speech
Blasting off your life
Rule to kill the urge
Dumb assholes' speech

Years of fighting
Teaching my son
To believe in that man
Racist human being
Racist ground will live
Shame and regret
Of the pride
You've once possessed

War for territory
War for territory
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

set<string> s1;
string st;
int v[5],com;
int n,m;

int ans;

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>st;
		s1.insert(st);
	}

	for (int i=1;i<=m;i++)
	{
		cin>>st;
		if (s1.find(st)!=s1.end())
		{
			com++;
		}
		else
		{
			v[2]++;
		}
	}

	v[1]=n-com;

	int cur=1;

	while (true)
	{
		if (com==0&&v[cur]==0)
		{
			ans=3-cur;
			break;
		}
		if (com>0)
		{
			com--;
		}
		else
		{
			v[cur]--;
		}
		cur=3-cur;
	}

	if (ans==1)
	{
		cout<<"YES"<<endl;
	}
	else
		cout<<"NO"<<endl;

	cin.get(); cin.get();
	return 0;
}