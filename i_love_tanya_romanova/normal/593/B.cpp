/*
They came to the land, to kill on command.
They ride through the dark of the night.
Metal warrior stands over victims whose hands
Grab for their last chance of life.

Bright shields! sharp swords!
March forward for their Lord.
Set the bow, rulers come
Meet your maker.
Battle cries! silent screams!
Submerge the Devil in evil dreams
Feel the blade, rulers come
Meet your maker.

I live for the kill, I do it at will
Let the weak ride back to the lair.
Now they will kneel to leather and steel
Gasp for the last breath of air.

Blood runs! heads roll!
Enemy fear, take the soul
Set the bow, rulers come
Meet your maker.
Lash out! strike first!
Blood of the dead quench my thirst
Feel the pain, rulers come
Meet your maker.

A gilded warrior wonders why...
His fear becomes new life on high...
Looking down... the dead won't tell.
Why his soul existence lives on in Hell.
Long live the spirit!..
In a life that knows no end...
Many pass before him...
Many in the wind.
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
#define N 500000

using namespace std;

int n;
long long xl,xr;
vector<int> v1;
int k[N];
int b[N];

long long eval(long long id,long long ps)
{
	return k[id]*ps+b[id];
}

long double eval2(long long id,long double ps)
{
	return k[id]*ps+b[id];
}

bool cmp(int a,int b)
{
	long long v1=eval(a,xl);
	long long v2=eval(b,xl);
	if (v1!=v2)
	{
		return v1<v2;
	}
	long double p1=eval2(a,xl+0.5);
	long double p2=eval2(b,xl+0.5);
	return (p1<p2);
}

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin>>n;
	cin>>xl>>xr;
	for (int i=1;i<=n;i++)
	{
		cin>>k[i]>>b[i];
	}
	
	for (int i=1;i<=n;i++)
	{
		v1.push_back(i);
	}
	
	
	sort(v1.begin(),v1.end(),cmp);
	/*
	for (int i=0;i<v1.size();i++)
		cout<<v1[i]<<" "<<eval(v1[i],xl)<<" "<<eval(v1[i],xr)<<endl;
	*/	
	for (int i=0;i+1<v1.size();i++)
	{
		long long p1=eval(v1[i],xr);
		long long p2=eval(v1[i+1],xr);
		if (p1>p2)
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	
	cout<<"NO"<<endl;
	return 0;
}