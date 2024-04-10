/*
Standing in line at the battlefield
The march of the brothers in arms
Awaiting the sign to crush the enemies
In silence we pray for our souls
Holding the flags up high
On the signal march or die
The gods will show the way to the
Dawn of victory
Breaking their bones with hammer and steel
Dawn of victory
We fight till the end and no man will kneel
At the dawn of victory
Run down the hill, let the slaughter begin
The blood will cover the ground
Metal and steel will meet once again
The soldiers will die to the sound
Holding the flags up high
On the signal march or die
The gods will show the way to the
Dawn of victory
Breaking their bones with hammer and steel
Dawn of victory
We fight till the end and no man will kneel
At the dawn of victory
Dawn of the dead will arise in the night
We will be waiting for you at the gate
Dawn of the dead, will arise in the night
Just show your face and we will prevail with light
Holding the flags up high
On the signal march or die
The gods will show the way to the
Dawn of victory
Breaking their bones with hammer and steel
Dawn of victory
We fight till the end and no man will kneel
At the dawn of victory
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

int n,k;
int x[1<<20];
vector<pair<int, int> >order;
double ans;
int flag;
int y[1<<20];

double gd(int a,int b)
{
	return sqrt(1.0*(x[a]-x[b])*(x[a]-x[b])+1.0*(y[a]-y[b])*(y[a]-y[b]));
}

double solve(int l,int r)
{
	if (l>r)
		return 0;
	double v=min(gd(n+1,l),gd(n+1,r));
	v+=gd(l,r);
	return v;
}

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
for (int i=1;i<=n+1;i++)
	cin>>x[i];

for (int i=1;i<=n;i++)
{
	order.push_back(make_pair(x[i],i));
}

cin>>y[n+1];

sort(order.begin(),order.end());

for (int i=0;i<order.size();i++)
{
	if (order[i].second==k&&flag==0)
	{
		k=i+1;
		flag=1;
	}
	x[i+1]=order[i].first;
}

if (k==n+1)
{
	double ans1=gd(n+1,1);
	double ans2=gd(n+1,n);
	cout.precision(12);
	cout<<fixed<<min(ans1,ans2)+(x[n]-x[1])<<endl;
	return 0;	
}

ans=1e9;
/*
for (int i=1;i<=n;i++)
{
	cout<<x[i]<<" ";
}
cout<<endl;
cout<<k<<endl;
*/
// 1 - x

for (int i=k;i<=n;i++)
{
	double res=min(gd(k,i)+gd(i,1)+gd(1,n+1),gd(k,1)+gd(1,i)+gd(i,n+1));
	res+=solve(i+1,n);
	ans=min(ans,res);
}

// x-n

for (int i=1;i<=k;i++)
{
	double res=min(gd(k,i)+gd(i,n)+gd(n,n+1),gd(k,n)+gd(n,i)+gd(i,n+1));
	res+=solve(1,i-1);
	ans=min(ans,res);
}
cout.precision(12);
cout<<fixed<<ans<<endl;

//cin.get();cin.get();
return 0;}