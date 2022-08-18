/*
If you just walked away
What could I really say?
Would it matter anyway?
Would it change how you feel?

I am the mess you chose
The closet you cannot close,
The devil in you I suppose
'Cause the wounds never heal.

[Chorus:]
But everything changes
If I could turn back the years
If you could learn to forgive me
Then I could learn to feel,

Sometimes the things I say
In moments of disarray
Succumbing to the games we play
To make sure that it's real.

[Chorus]

When it's just me and you.
Who knows what we could do.
If we can just make it through
The toughest part of the day.

[Chorus]

Stay here together
And we could
Conquer the world
If we could
Say that forever
Is more than just a word.

If you just walked away
What could I really say?
Would it matter anyway?
It wouldn't change how you feel.
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

int h,m,s;
int t1,t2;
int g[N];

void update(int x){
	if (x>=t1&&x<t2)
		g[1]=0;
	else
		g[0]=0;
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>h>>m>>s;
	if (h==12)
		h=0;

	cin>>t1>>t2;

	if (t1>t2)
		swap(t1,t2);

	g[0]=g[1]=1;

	update(h);
	update(m/5);
	update(s/5);

	if (g[0]||g[1])
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

	cin.get(); cin.get();
	return 0;
}