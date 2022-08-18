/*
My loneliness makes you feel insecure
My loneliness will never let you find a cure
My loneliness has no directions for me and you
My loneliness speaks no truth of what you do
Listen to what I say

Turn me in
You're going crazy and I can't stand to feel your tears over me
Turn me in
It's not a crime to feel the way that I do, again and again

My loneliness does not lead you to my core
My loneliness always tells you to ignore
My loneliness, a waste of time if there's no trust
My loneliness is turning everything to dust
Listen to what I say

Turn me in
You're going crazy and I can't stand to feel your tears over me
Turn me in
It's not a crime to feel the way that I do, again and again

No one can save us from this pain
I wish that I could stop the rain
These dark gray skies are closing in

Oh
You're going crazy and I can't stand to feel your tears over me
Turn me in
It's not a crime to feel the way that I do, again and again
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

long long gcd(long long a,long long b)
{
	while (a&&b)a>b?a%=b:b%=a;
	return a+b;
}

long long x,y;
vector<pair<long long, long long> > ans;

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>x>>y;
if (gcd(x,y)>1)
{
	cout<<"Impossible"<<endl;
	return 0;
}

while (x>1||y>1)
{
	if (x==1)
	{
		ans.push_back(make_pair(y-1,2));
		y=1;
	}
	else if (y==1)
	{
		ans.push_back(make_pair(x-1,1));
		x=1;
	}
	else if (x>y)
	{
		ans.push_back(make_pair(x/y,1));
		x%=y;
	}
	else
	{
		ans.push_back(make_pair(y/x,2));
		y%=x;
	}
}

//reverse(ans.begin(),ans.end());
for (int i=0;i<ans.size();i++)
{
	cout<<ans[i].first;
	if (ans[i].second==1)
		cout<<"A";
	else
		cout<<"B";
}
cout<<endl;

//cin.get();cin.get();
return 0;}