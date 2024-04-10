/*
And if you're taking a walk through the garden of life
What do you think you'd expect you would see?
Just like a mirror reflecting the moves of your life
And in the river reflections of me

Just for a second a glimpse of my father I see
And in a movement he beckons to me
And in a moment the memories are all that remain
And all the wounds are reopening again

We're blood brothers, we're blood brothers
We're blood brothers, we're blood brothers

And as you look all around at the world in dismay
What do you see, do you think we have learned
Not if you're taking a look at the war-torn affray
Out in the streets where the babies are burned

We're blood brothers, we're blood brothers
We're blood brothers, we're blood brothers

There are time when I feel I'm afraid for the world
There are times I'm ashamed of us all
When you're floating on all the emotion you feel
And reflecting the good and the bad

Will we ever know what the answer to life really is?
Can you really tell me what life is?
Maybe all the things that you know that are precious to you
Could be swept away by fate's own hand

We're blood brothers, we're blood brothers
We're blood brothers, we're blood brothers

When you think that we've used all our chances
And the chance to make everything right
Keep on making the same old mistakes
Makes untipping the balance so easy
When we're living our lives on the edge
Say a prayer on the book of the dead

We're blood brothers, we're blood brothers
We're blood brothers, we're blood brothers

And if you're taking a walk through the garden of life....
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

const int N = 200031;

int n;
int r;
int x[N];
long double Y[N];

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>r;
	for (int i=1;i<=n;i++){
		cin>>x[i];
	}

	for (int i=1;i<=n;i++){
		Y[i]=r;
		for (int j=1;j<i;j++){
			if (abs(x[i]-x[j])>2*r)
				continue;
			long double Dx=abs(x[i]-x[j]);
			//Dr*Dr=dx*dx+dy*dy
			long double dy2=4*r*r-Dx*Dx;
			long double dy=sqrt(dy2);
			Y[i]=max(Y[i],Y[j]+dy);
		}
	}

	for (int i=1;i<=n;i++){
		if (i>1)
			cout<<" ";
		cout.precision(12);
		cout<<fixed<<Y[i];
	}
	cout<<endl;

	cin.get(); cin.get();
	return 0;
}