/*
I can still remember
The words and what they meant
As we etched them with our fingers
In years of wet cement
The days blurred into each other
Though everything seemed clear
We cruised along at half speed
But then we shifted gears

We ran like vampires from a thousand burning suns
But even then we should have stayed
But we ran away
Now all my friends are gone
Maybe we've outgrown all the things that we once loved
Runaway
But what are we running from?
A show of hands from those in this audience of one
Where have they gone?

Identities assume us
As nine and five add up
Synchronizing watches
To the seconds that we lost
I looked up and saw you
I know that you saw me
We froze but for a moment
In empathy

I brought down the sky for you but all you did was shrug
You gave my emptiness a name
But you ran away
Now all my friends are gone
Maybe we've outgrown all the things that we once loved
Runaway
But what are we running from?
A show of hands from those in this audience of one
Where have they gone?

We're all ok, until the day we're not
The surface shines, while the inside rots
We raced the sunset and we almost won
We slammed the brakes, but the wheels went on

We ran away
Now all my friends are gone
Maybe we've outgrown all the things that we once loved
Runaway
But what are we running from?
A show of hands from those in this audience of one
Where have they gone?
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
long long score_pref[N],score_suf[N],val_pref[N],val_suf[N];

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

	for (int i=1;i<=n;i++)
	{
		score_pref[i]=score_pref[i-1];
		long long need=max(val_pref[i-1]+1,0ll+ar[i]);
		need-=ar[i];
		need=max(need,0ll);
		score_pref[i]+=need;
		val_pref[i]=ar[i]+need;
	}

	for (int i=n;i>=1;--i)
	{
		score_suf[i]=score_suf[i+1];
		long long need=max(val_suf[i+1]+1,0ll+ar[i]);
		need-=ar[i];
		need=max(need,0ll);
		score_suf[i]+=need;
		val_suf[i]=ar[i]+need;
	}

	long long ans=score_suf[1];

	for (int i=1;i<=n;i++)
	{
		long long here=score_pref[i]+score_suf[i+1];
		if (val_pref[i]==val_suf[i+1])
			here++;
		ans=min(ans,here);
	}
	cout<<ans<<endl;

	/*for (int i=1;i<=n;i++)
	{
		cout<<score_pref[i]<<" "<<score_suf[i]<<endl;
	}*/

	cin.get(); cin.get();
	return 0;
}