/*
Dolls of voodoo all stuck with pins
One for each of us and our sins
So you lay us in a line
Push your pins, they make us humble
Only you can tell in time
If we fall or merely stumble

But tell me
Can you heal what father's done?
Or fix this hole in a mother's son?
Can you heal the broken worlds within?
Can you strip away so we may start again?

Tell me
Can you heal what father's done?
Or cut this rope and let us run?
Just when all seems fine
And I'm pain free
You jab another pin
Jab another pin in me

Mirror, mirror upon thy wall
Break the spell or become the doll
See you sharpening the pins
So the holes will remind us
We're just the toys in the hands of another
And in time the needles turn from shine to rust

But tell me
Can you heal what father's done?
Or fix this hole in a mother's son?
Can you heal the broken worlds within?
Can you strip away so we may start again?

Tell me
Can you heal what father's done?
Or cut this rope and let us run?
Just when all seems fine
And I'm pain free
You jab another pin
Jab another pin in me

Jab it
Here come the pins

Blood for face
Sweat for dirt
Three X's for the stone
To break this curse
A ritual's due
I believe I'm not alone
Shell of shotgun
Pint of gin
Numb us up to shield the pins
Renew our faith
Which way we can
To fall in love with life again
To fall in love with life again
To fall in love with life again
To fall in love
To fall in love
To fall in love with life again

So tell me
Can you heal what father's done?
Or fix this hole in a mother's son?
Can you heal the broken worlds within?
Can you strip away so we may start again?

Tell me
Can you heal what father's done?
Or cut this rope and let us run?
Just when all seems fine
And I'm pain free
You jab another pin
Jab another pin in me

No more pins in me
No more, no more pins in me
No more, no more pins in me
No more, no more, no more
No, no, no
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
const int N = 250031;

int n,ptr;
int have[N];

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	ptr=n;
	for (int i=1;i<=n;i++)
	{
		int val;
		cin>>val;
		have[val]=1;
		vector<int> here;
		while (have[ptr])
		{
			here.push_back(ptr);
			--ptr;
		}
		for (int j=0;j<here.size();j++)
		{
			if (j)
				cout<<" ";
			cout<<here[j];
		}
		cout<<endl;
	}
	cin.get(); cin.get();
	return 0;
}