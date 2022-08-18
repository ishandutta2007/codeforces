/*
Going to the wake
Of the restless soul
Leading to the isle
I don't wanna go

Nothing really matters
Even life or death
Meeting with the man
To feel the dragons breath

Where is the future?
There is no past
Only the present
And will it last?

Greed is the product
Of the fruitful days
Brother have no worries
Captain Adler's case

Lucifer beside me
We are holding hands
I don't need to travel
Floating across the lands

Oh Lucifer, please take my hand
Oh Lucifer come take my hand

Its the way of the dragons curse,
Just not the story you search
Shadows whispers in your ears,
smell of winters always near,
it takes away your fear.

Often it's just ringing into
needle ends, after another hell
and theyre all blown away.

One thing is for certain,
were bound to stay,
the restless soul is calling,
it has seen your grave.

Where is the future?
There is no past
Only the present
And will it last?

Nothing lasts forever
As I'm going to send you back
Black winds flow through the dead
And I know they do not care.
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
 
#define eps 1e-9
#define M_PI 3.141592653589793
//#define bs 1000000007
#define bsize 512
 
using namespace std;

int n,m,k,flag;
int cnt[1<<10];
int sum[1<<10];
int bs;
int full;

long long pw(long long a,long long b)
{
	if (b==0)
		return 1%bs;
	if (b%2)
		return a*pw(a,b-1)%bs;
	return pw(a*a%bs,b/2);
}

int main(){
//freopen("center.in","r",stdin);
//freopen("center.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
if (n%2!=m%2)
{
	cout<<0<<endl;
	return 0;
}

if (n<m)
{
	swap(n,m);
	flag=1;
}

cin>>k;
for (int i=0;i<k;i++)
{
	int a,b,c;
	cin>>a>>b>>c;
	if (flag)
		swap(a,b);
	cnt[a]++;
	sum[a]^=(c==-1);
	if (cnt[a]==m)
	{
		if (sum[a]==0)
		{
			cout<<0<<endl;
			return 0;
		}
		++full;
	}
}

cin>>bs;

int deg=(n-1)*(m-1);
deg-=k;
deg+=full;

cout<<pw(2,deg)<<endl;

//cin.get();cin.get();
return 0;}