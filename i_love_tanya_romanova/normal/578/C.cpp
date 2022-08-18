/*
I must believe that what's a memory now
Was the only way
To know that all of those you love
Were just stripped away

And now if I'm the one to lead us
Into a brand new day
At peace I must be with the brutal truth
To truly lead the way

Please God, give me the strength to lead
(It's my charge to keep)
Make the sorrow the fuel I need
(It's my charge to keep)

Please God, give me the strength to lead
(It's my charge to keep)
Make the sorrow the fuel I need
(It's my charge to keep)

And now we must wipe the tears away
Gather up our inner strength
The loss of those we can't replace
Will bring about their fate

And though many lifetimes it will take
To bring justice on our way
We must never falter, we must never fail
This is our charge to keep

Please God, give me the strength to lead
(It's my charge to keep)
Make the sorrow the fuel I need
(It's my charge to keep)

Please God, give me the strength to lead
(It's my charge to keep)
Make the sorrow the fuel I need
(It's my charge to keep)

Please God, give me the strength to lead
(It's my charge to keep)
Make the sorrow the fuel I need
(It's my charge to keep)

Please God, give me the strength to lead
(It's my charge to keep)
Make the sorrow the fuel I need
(It's my charge to keep)
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

#define eps 1e-6
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

using namespace std;

int n;
int ar[1<<20];
long double l,r;

long double solve(long double val)
{
	long double mn,mx;
	mn=1e18;
	mx=-1e18;
	long double res=0;
	long double s=0;
	for (int i=1;i<=n;i++)
	{
		mn=min(mn,s);
		mx=max(mx,s);
		s+=(ar[i]-val);
		res=max(res,fabs(s-mn));
		res=max(res,fabs(s-mx));
	}
//	cout<<val<<" "<<res<<endl;
	return res;
}

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
	cin>>ar[i];

l=-1e10;
r=1e10;
for (int iter=1;iter<=150;iter++)
{
	long double mid1,mid2;
	mid1=l*2+r;
	mid2=l+2*r;
	mid1/=3;
	mid2/=3;
	long double val1=solve(mid1);
	long double val2=solve(mid2);
	if (val1<val2)
		r=mid2;
	else
		l=mid1;
}


cout.precision(12);
//cout<<fixed<<r-l<<endl;

cout<<fixed<<solve(l)<<endl;

//cin.get();cin.get();
return 0;}