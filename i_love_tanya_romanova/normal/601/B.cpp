/*
I'm not gonna waste this
This opportunity's mine
I'm sick of complaining
About a beautiful life

How did we get here?
Did we forget all the things inside?
And how do we stay here?
Do we embrace all the things tonight?

I feel so alive tonight
You got me feeling sublime
I wanna yell it from the rooftop down
Until it's over and we're older

For my entertainment
You tell a whimsical lie
To keep me complacent
You knock me down with a smile

How did we get here?
How do we pretend everything's alright?
And how do we stay here?
Do we erase all the fear tonight?

I feel so alive tonight
You got me feeling sublime
I wanna yell it from the rooftop down
Until it's over and we're older

Like sugar and cyanide
These walls are gonna collide
I wanna yell it from the rooftop down
Until it's over and we're older
Yeah

So take me
But go slow
And let me hide somewhere I know
And let this
Seed grow
Until we finally call this home

So take me
But go slow
And let me hide somewhere I know
And let this
Seed grow
Until we finally call this home

If I were to die tonight
Would it tear you apart
Would you yell it from the rooftops down
Until it's over
And you're older

I feel so alive tonight
You got me feeling sublime
I wanna yell it from the rooftop down
Until it's over and we're older

Like sugar and cyanide
I'm never meant to collide
I wanna yell it from the rooftops down
until it's over and we're older
Yeah
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
#define ends adsasdgasdagsdgs

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512
#define N 250000

using namespace std;

int n,tests,ar[N];
vector<pair<int, int> >dif;
set<int> ends;
set<int>::iterator it;
int L[N],R[N];
long long ans;

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin>>n>>tests;
	for (int i=1;i<=n;i++)
	{
		cin>>ar[i];
	}
	for (int i=1;i<n;i++)
	{
		dif.push_back(make_pair(abs(ar[i+1]-ar[i]),i));
	}
	sort(dif.begin(),dif.end());
	reverse(dif.begin(),dif.end());
	
	ends.insert(n+1);
	ends.insert(0);
	
	for (int i=0;i<dif.size();i++)
	{
		int id=dif[i].second;
		it=ends.lower_bound(id);
		int val=(*it);
		R[id]=val;
		--it;
		val=(*it);
		L[id]=val;
		++L[id];
		ends.insert(id);
	}
	
	for (;tests;--tests)
	{
		int l,r;
		cin>>l>>r;
		ans=0;
		for (int i=0;i<dif.size();i++)
		{
			int ps=dif[i].second;
			if (ps<l||ps>r)
				continue;
			int tl=L[ps];
			int tr=R[ps];
			if (tl<l)
				tl=l;
			if (tr>r)
				tr=r;
			long long ttl=(ps-tl+1)*1ll*(tr-ps);
			ans+=ttl*dif[i].first;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}