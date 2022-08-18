/*
I haven't been here in a long long time
It feels so good to be home
Sitting right here light a fire inside
It's so hard to explain

And as the real world disappear
Awaken my memories
Oh, it's all coming back to me

There's something in here, I believe it's love
That sets me free to explore
All of the things that I chose to hide
Now I can see who I am

I am out in the garden where we played
Here began the endless dream
We will never come back

Now I am sitting here in the pouring rain
Something is guiding me right
I feel the fire inside
My heart is telling me that I am on my way
To redefine who I am
I will be stronger this time
I will be myself to the very end

Coming back here is like coming back to life
I feel empowered and new
It's hard to believe that it was so long ago
I called this place my home

Here in this town where I was born
Everything move so fast
I feel like a stranger out here

Now I am sitting here in the pouring rain
Something is guiding me right
I feel the fire inside
My heart is telling me that I am on my way
To redefine who I am
I will be stronger this time
I will be myself to the very end

My head is spinning, I've had the weirdest day
It's really hard to explain
I wish I could tame this ghost in my heart
One part of me will always remain here
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
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 300031;

int n,p[N],a[N],b[N];
set<pair<int,int> > S[10];
set<pair<int,int> > ::iterator it;
vector<int> ans;

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
		cin>>p[i];
	}
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=3;j++)
		{
			if (a[i]==j||b[i]==j)
			{
				S[j].insert(make_pair(p[i],i));
			}
		}
	}

	int m;

	cin>>m;
	for (;m;--m)
	{
		int val;
		cin>>val;
		if (S[val].size()==0)
		{
			ans.push_back(-1);
			continue;
		}
		it=S[val].begin();
		int id=(*it).second;
		ans.push_back(p[id]);
		for (int j=1;j<=3;j++)
		{
			if (a[id]==j||b[id]==j)
				S[j].erase(make_pair(p[id],id));
		}
	}

	for (int i=0;i<ans.size();i++)
	{
		if (i)
			cout<<" ";
		cout<<ans[i];
	}

	cin.get(); cin.get();
	return 0;
}