/*
It kills me not to know this but I've all but just forgotten
What the color of her eyes were and her scars or how she got them
As the telling signs of age rain down a single tear is dropping
Through the valleys of an aging face that this world has forgotten

There is no reconciliation that will put me in my place
And there is no time like the present to drink these draining seconds
But seldom do these words ring true when I'm constantly failing you
Like walls that we just can't break through until we disappear

So tell me now
If this ain't love then how do we get out?
Because I don't know
That's when she said I don't hate you boy
I just want to save you while there's still something left to save (whoa, whoa)
That's when I told her I love you girl
But I'm not the answer for the questions that you still have (whoa, whoa)

But the day pressed on like crushing weights
For no man does it ever wait
Like memories of dying days
That deafen us like hurricanes
Bathed in flames we held the brand
Uncurled the fingers in your hand
Pressed into the flesh like sand
Now do you understand?

So tell me now
If this ain't love then how do we get out?
Because I don't know
That's when she said I don't hate you boy
I just want to save you while there's still something left to save (whoa, whoa)
That's when I told her I love you girl
But I'm not the answer for the questions that you still have (whoa, whoa)

One thousand miles away
There's nothing left to say
But so much left that I don't know
We never had a choice
This world is too much noise
It takes me under
It takes me under once again
I don't hate you
I don't hate you, no

So tell me now
If this ain't love then how do we get out?
Because I don't know
That's when she said I don't hate you boy
I just want to save you while there's still something left to save (whoa, whoa)
That's when I told her I love you girl
But I'm not the answer for the questions that you still have (whoa, whoa)

I don't hate you
I don't hate you (whoa, whoa)
I don't hate you
I don't hate you, no (whoa, whoa)
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

long long n,k;

int first_group;

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>k;
	long long max_can=1ll*n*(n-1)/2;
	if (max_can<k)
	{
		cout<<"Impossible"<<endl;
		return 0;
	}

	int addend=-1;

	for (int i=0;i<n;i++)
	{
		if (k>=i){
			k-=i;
			first_group++;
		}
		else if (k>0){
			addend=k;
			k=0;
		}
	}

	//cout<<first_group<<" "<<addend<<endl;

	for (int i=0;i<first_group;i++){
		cout<<"(";
	}

	// dep= first_group now

	for (int i=first_group;i>max(addend,0);--i){
		cout<<")";
	}

	if (addend!=-1){
		cout<<"()";
	}
	for (int i=addend;i>0;--i)
		cout<<")";

	n-=first_group;
	if (addend!=-1)
		--n;
	for (int i=1;i<=n;i++)
		cout<<"()";
	cout<<endl;

	cin.get(); cin.get();
	return 0;
}