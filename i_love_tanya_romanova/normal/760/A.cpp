/*
Look forward to the break down
Pay attention to the worst
The uneducated fail rate
Cause they said it wouldn't hurt.

Time changes everything
So remarkable
Time changes all
Time changes everything
But be careful what you wait for

Fake it till you make it
Consistency the yolk
If you live like someone's watching you
You'll be the egg that never broke

No more screaming, "someone save me"
No more echoing the fail
Where there's wind... be a hurricane
Cut the anger set the sail
Set the sail
Set it

Time changes everything
So remarkable
Time changes all
Time changes everything
But be careful what you wait for

I never needed to win
I never needed anything
I never needed to win at all
I never needed to win
I never needed a win
I will stand here in awe
So I stand...
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

int m,d;

int get_len(int m)
{
	if (m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		return 31;
	if (m==4||m==6||m==9||m==11)
		return 30;
	return 28;
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>m>>d;
	int here=get_len(m);
	int ans=1;
	for (int i=1;i<here;i++)
	{
		d++;
		if (d==8)
		{
			ans++;
			d=1;
		}
	}
	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}