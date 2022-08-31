/*
Once upon a time I could take anything, anything.
Always stepped in time, regardless of the beat
I moved my feet, I carried weight
What I could not do I faked
I dug seeking treasure
Just to wake up in an early grave
So I stopped right there and said

Go on alone, 'cause I won't follow.
This isn't giving up, no this is letting go
Out with the old dreams I've borrowed
The path I carve from here on out will be my own
The path will be my own

This is the part where the needle skips
And the chorus plays like a sink that drips
A syllable repeating, like a warning we aren't heeding
Until all of a sudden we noticed it
When the wheels brace and the tires grip
A map we've been misreading
A defeat we're not conceding
Until now
There must be some other way out

Go on alone, because I won't follow
But this isn't giving up no this is letting go
Out with the old dreams I've borrowed
The path I carve from here on out will be my own
A path to take me home

(Hey! Hey! Hey! Hey!)

The wind died
The whole world ceased to move
Now so quiet
Her beating heart became a boom
We locked eyes
For just a moment or two
She asked why
I said "I don't know why,
I just know"

The wind died
The whole world ceased to move
Now so quiet
Her beating heart became a boom
We locked eyes
For just a moment or two
She asked why
I said "I don't know why
I just know
I just know"

Go on alone, 'cause I won't follow
This isn't giving up, no this is letting go
I made most of all this sorrow
I tried to brave this discontent, but now I'm through
I'm letting go of you.

This is letting go
This is letting go

Once upon a time I could take anything, anything.
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

int n,tp[N],VAL[N],ps[N];

int t[N*4];
int toadd[N*4];

void push(int v,int tl,int tr)
{
	if (toadd[v]==0)
		return;
	t[v*2]+=toadd[v];
	toadd[v*2]+=toadd[v];
	toadd[v*2+1]+=toadd[v];
	t[v*2+1]+=toadd[v];
	toadd[v]=0;
}

int get(int v,int tl,int tr,int l,int r) // max
{
	if (l>r)
		return -1e9;
	if (tl==l&&tr==r)
		return t[v];
	push(v,tl,tr);
	int tm=tl+tr;
	tm/=2;
	return max(get(v*2,tl,tm,l,min(r,tm)),get(v*2+1,tm+1,tr,max(tm+1,l),r));
}

void add(int v,int tl,int tr,int l,int r,int val)
{
	if (l>r)
		return;
	if (tl==l&&tr==r)
	{
		t[v]+=val;
		toadd[v]+=val;
		return;
	}
	push(v,tl,tr);
	int tm=tl+tr;
	tm/=2;
	add(v*2,tl,tm,l,min(r,tm),val);
	add(v*2+1,tm+1,tr,max(tm+1,l),r,val);
	t[v]=max(t[v*2],t[v*2+1]);
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
//	build(1,1,n);

	for (int i=1;i<=n;i++)
	{
		scanf("%d",&ps[i]);
		scanf("%d",&tp[i]);
		if (tp[i]==1)
		{
			scanf("%d",&VAL[ps[i]]);
		}
		if (tp[i]==0)
			add(1,1,n,1,ps[i],-1);
		else
			add(1,1,n,1,ps[i],1);
		if (get(1,1,n,1,n)<=0)
		{
			printf("%d\n",-1);
			continue;
		}
		int l,r;
		l=1;
		r=n;
		while (l<r)
		{
			int mid=l+r+1;
			mid/=2;
			if (get(1,1,n,mid,n)>=1)
				l=mid;
			else
				r=mid-1;
		}
		printf("%d\n",VAL[l]);
	}

	cin.get(); cin.get();
	return 0;
}