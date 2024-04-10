/*
I will not play along
With things I find unfair
I will not mount defences
Against unjust attacks
This land was never given
We built this on our own
It is sanity dependent
Whether we rise or fall

Whether we rise or we fall
One for the night
One for uncontrol

Hold your feet to the ground
To the end of our time for the rest of our lives
Hold your head up high
To the end of our time for the rest of our lives

Secretly I hope
That nothing ever comes of this
And you are not alone
In wanting to come back
To a place where it won't matter
Just what side you're on
It's when our lives are branded
What's underneath will overcome

What's underneath will overcome
One for the night one for the uncontrol

Hold your feet to the ground
To the end of our time for the rest of our lives
Hold your head up high
To the end of our time for the rest of our lives

Now it's time to stand up tall
One for the night
One for the uncontrol

Hold your feet to the ground
To the end of our time for the rest of our lives
Hold your head up high
To the end of our time for the rest of our lives
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

int n,s,ar[N];

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
		s+=ar[i];
	}
	sort(ar,ar+n);
	cout<<ar[n-1]*n-s<<endl;

	cin.get(); cin.get();
	return 0;
}