/*
Gathered round the wooden table
Same tavern as the nights before
I brace myself against the gable
Sunlight pushes its way through the gap in the door

As the golden sunbeams reach my eyes
I stand up and raise my pint up high

One more for our brothers who fought beside us
One more and forward again
Once more, we'll fight and conquer
Until we'll meet again

Staring at the stools not taken
I reach for my tankard of ale
The silence remains unbroken
All you hear is a tinkle of mail

As the golden sunbeams reach my eyes
I stand up and raise my pint up high

One more for our brothers who fought beside us
One more and forward again
Once more, we'll fight and conquer
We'll see you when we die
We'll see you when we die

Like a raging thunderstorm we flew down the forested hill
Tree-trunks and rocks passing by
The endless ranks stood waiting out in the open field
My fingers gripped the handle of my sword

With full power we smashed into their lines
The ground shook, swords tasted their flesh
Hooves trampling over men screaming for their lives
The battle raged until both troops were threshed

Grief no more over friends who died
That day will come to us all
Until then we shall fight with pride
Raise our pints till the dawn

Grief no more over friends who died
That day will come to us all
Side by side we shall ride once more
When the Horn calls for War

Feeling low and heavy hearted
Interrupted by a distant alarm
Seems like the war has started
May it be for our brothers in arms

Once again the golden sunbeam reaches my eyes
I stand up and raise my sword up high

One more for our brothers who fought beside us
One more and forward again
Once more, we'll fight and conquer
Until we'll meet again

One more for our brothers who fought beside us
One more and forward again
Once more, we'll fight and conquer
Until we'll meet again

One more, And forward again
One more for ever
We'll see you when we die
We'll see you when we die
*/

//#pragma comment(linker, "/STACK:16777216")
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
#include <ctime> 
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define N ((1<<21)+31)
//#define root 1
#define M 150

using namespace std;

long long n,ans,ad;

int main(){
//	freopen("game.in","r",stdin);
//	freopen("game.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	
	cin>>n;
	
	ans=n-2; // 1st
	for (int i=2;i<=n;i++)
	{
		ad=n-3;
		if (i!=2&&i!=n-1)
			--ad;
		ans+=ad;
//		cout<<i<<"  "<<ans<<endl;
		
	}
	if (n==3)
	{
		cout<<1<<endl;
		return 0;
	}
	
	cout<<ans<<endl;
	
	
	return 0;
	
}