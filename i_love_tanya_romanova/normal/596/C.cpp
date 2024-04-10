/*
Can't you see who I am I'm invincible

I am the voice in your dreams
So come and follow me
I am the terror unseen
In our society

Like an invincible shield
The force inside us all
Returned
To strike back
Cause I'm unstoppable

Can't you see who I am I'm invincible
Like a force that is out of control
It's the key to achieving my goals
Unbreakable
Can't you hear what I say
It's a miracle
Naw you're scared that you're losing it all
But this power runs deep in my soul
Invincible

I am your dream in disguise
I am your enemy
I am in the shadow you fear
The code awakens me

Inject the brutal vaccine
One man against them all
Like the truth never dies
I'm indestructible

Can't you see who I am I'm invincible
Like a force that is out of control
It's the key to achieving my goals
Unbreakable
Can't you hear what I say
It's a miracle
Naw you're scared that you're losing it all
But this power runs deep in my soul
Invincible

This power runs deep in my soul
I'm invincible
And I will never give in
Nor leave you behind
A frantic Wonder united we're stronger

Can't you see who I am I'm invincible
Like a force that is out of control
But this power runs deep in my soul
Invincible

Can't you see who I am I'm invincible
Like a force that is out of control
It's the key to achieving my goals
Unbreakable
Can't you hear what I say
It's a miracle
Naw you're scared that you're losing it all
But this power runs deep in my soul
Invincible
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
#define ry asdgasdg
#define rx iqowputtew

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

const int N = 201000;

using namespace std;

int n;
int x[N],y[N];
map<int, int> have,need;
set<pair<int, int> > S;
set<pair<int, int> > ::iterator it;
int ans[N];
int w[N];
vector<pair<pair<int, int> ,int> > order;
vector<pair<int, int> > xs[N],ys[N];
int where[N];

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i] >> y[i];
		have[y[i]-x[i]]++;
	}
	
	for (int i=1;i<=n;i++)
	{
		cin >> w[i];
		need[w[i]]++;
	}
	
	for (int i=1;i<=n;i++)
	{
		if (have[w[i]]!=need[w[i]])
		{
			cout<<"NO"<<endl;
			return 0;
		}
		S.insert(make_pair(w[i],i));
	}
	
	for (int i=1;i<=n;i++)
	{	
		order.push_back(make_pair(make_pair(x[i],y[i]),i));
	}
	
	sort(order.begin(),order.end());
	
	for (int i=0;i<order.size();i++)
	{
		int id=order[i].second;
		pair<int, int> p=make_pair(y[id]-x[id],-1);
		it=S.lower_bound(p);
		ans[id]=(*it).second;
		S.erase(it);
	}
	/*
	for (int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	*/
	for (int i=1;i<=n;i++)
	{
		xs[x[i]].push_back(make_pair(y[i],ans[i]));
		ys[y[i]].push_back(make_pair(x[i],ans[i]));
	}
	
	for (int i=0;i<=100000;i++)
		sort(xs[i].begin(),xs[i].end()),
		sort(ys[i].begin(),ys[i].end());
	
	for (int i=0;i<=100000;i++)
	{
		for (int j=1;j<xs[i].size();j++)
		{
			if (xs[i][j].second<xs[i][j-1].second)
			{
				cout<<"NO"<<endl;
				return 0;
			}
		}
		for (int j=1;j<ys[i].size();j++)
		{
			if (ys[i][j].second<ys[i][j-1].second)
			{
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	
	cout<<"YES"<<endl;
	for (int i=1;i<=n;i++)
		where[ans[i]]=i;
	
	for (int i=1;i<=n;i++)
	{
		cout<<x[where[i]]<<" "<<y[where[i]]<<endl;
	}
	
	return 0;
}