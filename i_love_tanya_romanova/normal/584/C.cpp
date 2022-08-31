/*
Yeah, yeah 
If I could change the world 
Like a fairy tale 
I would drink the love 
From your Holy Grail 
I would start with love 
Tell ol' Beelzebub 
To get outta town 
'Cause you just lost your job 
How did we get so affected ('cause I think) 
Love is love reflected 

Time 
Don't let it slip away 
Raise yo' drinkin' glass 
Here's to yesterday 
In Time 
We're all gonna trip away 
Don't piss Heaven off 
We got Hell to pay 
Come full circle 

And if 
There's a spell on you that 
I could take away 
I would do the deed 
Yeah and by the way 
Here's to Heaven knows 
As the circle goes 
It ain't right 
I'm uptight 
Yeah and get off my toes 

I used to think that every little thing I did was crazy 
But now I think the Karma cops are comin' after you 

Time 
Don't let it slip away 
Raise yo drinkin' glass 
Here's to yesterday 
In Time 
We're all gonna trip away 
Don't piss Heaven off 
We got Hell to pay 
Come full circle 

Every time you get yourself caught up inside 
Of someone else's crazy dream 
Own it, yeah that's a mistake 
Everybody's gotta lotta nada killing them 
Instead of killing time 

Time 
Don't let it slip away 
Raise yo' drinkin' glass 
Here's to yesterday 
In Time 
We're all gonna trip away 
Don't piss Heaven off 
We got Hell to pay 

Time 
Don't let it slip away 
Raise yo' drinkin' glass 
Here's to yesterday 
In Time 
We're all gonna trip away 
Don't piss Heaven off 
We got Hell to pay 
Come full circle 

Circle, circle, circle, circle, circle, circle, circle
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
#define bsize 512

using namespace std;

int n,t;
string st1,st2;
int twos,ones1,ones2;

char oth(char c)
{
	for (int i='a';i<='z';i++)
		if (i!=c)
			return i;
}

char oth(char a,char b)
{
	for (int i='a';i<='z';i++)
		if (i!=a&&i!=b)
			return i;
}

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>t;
cin>>st1;
cin>>st2;

int dif=0;
for (int i=0;i<st1.size();i++)
	if (st1[i]!=st2[i])
		dif++;

int same=n-dif;

int found=-1;
int need;

for (int d2=0;d2<=same;d2++)
{
	need=t-d2;
	need*=2;
	
	if (need<dif||need>2*dif)
		continue;
	found=d2;	
}

if (found==-1)
{
	cout<<-1<<endl;
	return 0;
}

//cout<<found<<endl;

twos=(t-found)*2-dif;
ones1=dif-twos;
ones2=ones1;
string res=st1;

ones1/=2;
ones2/=2;

//cout<<ones1<<" "<<ones2<<" "<<twos<<endl;

for (int i=0;i<st1.size();i++)
{
	if (found>0&&st1[i]==st2[i])
	{
		res[i]=oth(st1[i]);
		--found;
		continue;
	}
	else if (st1[i]==st2[i])
	{
		res[i]=st1[i];
		continue;
	}
	else
	{
		if (twos>0)
		{
			res[i]=oth(st1[i],st2[i]);
			--twos;
		}
		else
		{
			if (ones1>0)
			{
				res[i]=st2[i];
				--ones1;
			}
			else
			{
				res[i]=st1[i];
				--ones2;
			}
		}
	}
}
cout<<res<<endl;

//cin.get();cin.get();
return 0;}