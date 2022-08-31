/*
I can't forget the faces
I can't forget the sounds
I can't forget, can't get the fever down
I guess imagination
It makes it come around
Whenever lightning strikes
And thunder sounds

We shared nothing
But storm, but wind
One rains wept moment stuck within

Day by day
I walk the distance alone
Walk the distance alone
Day by day
I fight the fever alone
Fight the fever alone

I can't forget the shaking
Your hands over my own
Both hot with fever
To our very bones
I do regret the feeling
That we will never know
What might have happened
Had we not let go

Day by day
I walk the distance alone
Walk the distance alone
Day by day
I fight the fever alone
Fight the fever alone

I can't forget the faces
I can't forget the sounds

Day by day...
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

int n,m;

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
if (n==1)
{
	if (m==2)
	{
		cout<<0<<endl;
		cout<<1<<" "<<1<<endl;
		cout<<1<<" "<<2<<endl;
		cout<<1<<" "<<1<<endl;
		return 0;
	}
	cout<<1<<endl;
	cout<<1<<" "<<m<<" "<<1<<" "<<1<<endl;
	for (int i=1;i<=m;i++)
		cout<<1<<" "<<i<<endl;
	cout<<1<<" "<<1<<endl;
	return 0;
}

if (m==1)
{
	if (n==2)
	{
		cout<<0<<endl;
		cout<<1<<" "<<1<<endl;
		cout<<2<<" "<<1<<endl;
		cout<<1<<" "<<1<<endl;
		return 0;
	}
	cout<<1<<endl;
	cout<<n<<" "<<1<<" "<<1<<" "<<1<<endl;
	for (int i=1;i<=n;i++)
		cout<<i<<" "<<1<<endl;
	cout<<1<<" "<<1<<endl;
	return 0;
}

if (n%2==0)
{
	cout<<0<<endl;
	cout<<1<<" "<<1<<endl;
	for (int i=1;i<n;i++)
	{
		if (i%2)
			for (int j=2;j<=m;j++)
				cout<<i<<" "<<j<<endl;
		else
			for (int j=m;j>=2;j--)
				cout<<i<<" "<<j<<endl;
	}
	for (int i=m;i;--i)
		cout<<n<<" "<<i<<endl;
	for (int i=n-1;i;--i)
		cout<<i<<" "<<1<<endl;
	return 0;
}

if (m%2==0)
{
	cout<<0<<endl;
	cout<<1<<" "<<1<<endl;
	for (int i=1;i<m;i++)
	{
		if (i%2)
			for (int j=2;j<=n;j++)
				cout<<j<<" "<<i<<endl;
		else
			for (int j=n;j>=2;j--)
				cout<<j<<" "<<i<<endl;
	}
	for (int i=n;i;--i)
		cout<<i<<" "<<m<<endl;
	for (int i=m-1;i;--i)
		cout<<1<<" "<<i<<endl;
	return 0;
}

cout<<1<<endl;
cout<<n<<" "<<m<<" "<<1<<" "<<1<<endl;

for (int i=1;i<=n;i++)
{
	if (i%2==1)
		for (int j=1;j<=m;j++)
			cout<<i<<" "<<j<<endl;
	else
		for (int j=m;j;--j)
			cout<<i<<" "<<j<<endl;
}

cout<<1<<" "<<1<<endl;

//cin.get();cin.get();
return 0;}