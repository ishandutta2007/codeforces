/*
Trading life for life
It all must fall
It must end with us
It must end with me

Insinuations of what might be
Fight through depriviation
There will be no sleep

Heed my cry

Because of greed and hatred
To dust we return
They will see the strength in our numbers
Only then will the self-righteous learn

Insinuations of what might be

To the masses, we mean nothing
But it starts in the hearts of the few
Witness the birth of a people
Unite. Renew.

There is no forever, just today
Don't let your sacrifice waste away

Through change and purity, turn the shadows to light
Buried beneath the ashes is a passion for life

There is no forever, just today
Don't let your sacrifice waste away

Let there be no more of this bloodshed

Heed my cry.

There is no forever, just today
Don't let your sacrifice waste away
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

#define eps 1e-13
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

using namespace std;

const int N = 250000;

int n,m,a[N],b[N];
string tp[N];
vector<int> v1,v2;
int w[N];
int deg2;
vector<int> ans;
int taken[N];

int get(int x)
{
	if (x==w[x])	
		return x;
	return w[x]=get(w[x]);
}

void merge(int a,int b)
{
	a=get(a);
	b=get(b);
	w[a]=b;
}

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin>>n>>m;
	
	if (n%2==0)
	{
		cout<<-1<<endl;
		return 0;
	}
	
	for (int i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i]>>tp[i];
		if (tp[i]=="S")
			v1.push_back(i);
		else
			v2.push_back(i);
	}
	
	for (int i=1;i<=n;i++)	
		w[i]=i;
	
	for (int i=0;i<v1.size();i++)
	{
		int id=v1[i];
		int ta,tb;
		ta=a[id];
		tb=b[id];
		merge(ta,tb);
	}
	
	for (int i=0;i<v2.size();i++)
	{
		int id=v2[i];
		int ta,tb;
		ta=a[id];
		tb=b[id];
		ta=get(ta);
		tb=get(tb);
		if (ta==tb)
			continue;
		merge(ta,tb);
		ans.push_back(id);
		++deg2;
	}
	
	if (deg2>n/2)
	{
		cout<<-1<<endl;
		return 0;
	}
	
	int cnt=0;
	for(int i=1;i<=n;i++)
		if (w[i]==i)
			++cnt;
	if (cnt>1)
	{
		cout<<-1<<endl;
		return 0;
	}
	
	for (int i=1;i<=n;i++)
		w[i]=i;
	
	for (int i=0;i<ans.size();i++)
	{
		int id=ans[i];
		taken[id]=1;
		merge(a[id],b[id]);
	}
	
	for (int i=0;i<v2.size();i++)
	{
		int id=v2[i];
		if (taken[id])
			continue;
		int ta,tb;
		ta=get(a[id]);
		tb=get(b[id]);
		if (ta==tb)
			continue;
		if (deg2==n/2)
			continue;
		++deg2;
		merge(ta,tb);
		ans.push_back(id);
		taken[id]=1;
	}
	
	if (deg2<n/2)
	{
		cout<<-1<<endl;
		return 0;
	}
	
	// back to s
	
	for (int i=0;i<v1.size();i++)
	{
		int id=v1[i];
		int ta,tb;
		ta=a[id];
		tb=b[id];
		ta=get(ta);
		tb=get(tb);
		if (ta!=tb)
		{
			ans.push_back(id);
			merge(ta,tb);
		}
	}
	
	cout<<ans.size()<<endl;
	for (int i=0;i<ans.size();i++)
	{
		if (i)
			cout<<" ";
		cout<<ans[i];
	}
	cout<<endl;
	
	return 0;
}