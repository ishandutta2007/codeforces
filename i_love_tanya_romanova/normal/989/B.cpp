/*
The freeway is jammed and it's backed up for miles
The car is an oven and baking is wild
Nothing is ever the way it should be
What we deserve we just don't get you see

A briefcase, a lunch and a man on the edge
Each step gets closer to losing his head
Is someone in heaven are they looking down
'Cause nothing is fair just you look around

Falling down

He's sick of waiting of lying like this
There's a hole in the sky for the angels to kiss
Branded a leper because you don't fit
In the land of the free you just live by your wits

Once he built missiles a nation's defence
Now he can't even give birthday presents
Across the city he leaves in his wake
A glimpse of the future a cannibal state

Falling down

The freeway is jammed and it's backed up for miles
The car is an oven and baking is wild
Nothing is ever the way it should be
What we deserve we just don't get you see

A briefcase, a lunch and a man on the edge
Each step gets closer to losing his head
Is someone in heaven are they looking down
'Cause nothing is fair just you look around

Falling down
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
#define prev asdgSHJsfgsdfhdsh

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 1200031;

int p;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	int n;
	cin>>n>>p;
	string st;
	cin>>st;

	int ok=0;
	for (int i=0;i+p<st.size();i++){
		if (st[i]=='.'||st[i+p]=='.'){
			ok=1;
			if (st[i]=='.'&&st[i+p]=='.')
			{
				st[i]='0';
				st[i+p]='1';
				continue;
			}
			if (st[i]=='.')
				st[i]='0'+'1'-st[i+p];
			else
				st[i+p]='0'+'1'-st[i];
			continue;
		}
		if (st[i]!=st[i+p]){
			ok=1;
		}
	}

	if (!ok){
		cout<<"No"<<endl;
	}
	else
	{
		for (int i=0;i<st.size();i++){
			if (st[i]=='.')
				st[i]='0';
		}
		cout<<st<<endl;
	}

//	cin.get(); cin.get();
	return 0;
}