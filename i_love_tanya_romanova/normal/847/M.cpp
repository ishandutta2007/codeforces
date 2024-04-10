/*
They turn the lights down low,
In shadows hiding from the world,
Only coming out when it gets cold

The seas part when they hit the floor,
The voices carry on and out the door
And everything you touch turns into gold

Like the angel you are you laugh creating
A lightness in my chest,
Your eyes they penetrate me,
(your answer's always 'maybe')
That's when I got up and left

A beating heart and a microphone,
A ticking clock in an empty home
Still tells of these times so long ago,

Even though I've come so far,
I know I've got so far to go
And any day now I'll explode

Like the angel you are you laugh creating
A lightness in my chest,
Your eyes they penetrate me,
(your answer's always 'maybe')
That's when I got up and left

And each and everyday will lead into tomorrow
Tomorrow brings one less day without you
But don't wait up just leave the light on
'Cause all the roads that I might take
Will all one day lead back to you

And like the angel you are you laugh creating
A lightness in my chest,
Your eyes they penetrate me,
(never cease to amaze me)
That's when I got up and left
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
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 100031;

int n,ar[N];

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>ar[i];
	}
	int ok=1;
	for (int i=3;i<=n;i++)
	{
		if (ar[i]-ar[i-1]!=ar[2]-ar[1])
			ok=0;
	}
	if (ok)
		cout<<ar[n]+ar[2]-ar[1];
	else
		cout<<ar[n];
	cout<<endl;

	cin.get(); cin.get();
	return 0;
}