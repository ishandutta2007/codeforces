/*
Run the race that will lead to nowhere fast
Trapped in the haze of this mindless false reality
Wandering a path laid out by fools
That they call "progression" where chaos rules

There is more to life than this
We are more than just this flesh
We are alive and our time has come
For a new awakening

Come death, come suffering, I will not live in fear
In this fleeting life where time escapes us
The path of least resistance is a slow, quiet death
I'd rather burn out than fade away

There is more to life than this
We are more than just this flesh
We are alive and our time has come
For a new awakening

I would rather die than live my life in fear
Out of step, no regrets in the new awakening

I will not live in fear
Live life with no regrets
I will not live in fear

There is more to life than this
We are more than just this flesh
We are alive and our time has come
For a new awakening

I'd rather burn out than fade away
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

int n,k;
vector<pair<long long, long long> > v;
vector<pair<long long, long long> > ans;

pair<long long, long long> ref(pair<long long, long long> p1,pair<long long, long long> centr)
{
	p1.first=2ll*centr.first-p1.first;
	p1.second=2ll*centr.second-p1.second;
	return p1;
}

void check(pair<long long, long long> p)
{
	int missed=0;
	int ptr=0;
	
	//cout<<"!"<<p.first<<" "<<p.second<<endl;
	
	/*int flag;
	if (p.first==-358668113*2-1)
		flag=1;
	else
		flag=0;
		
	if (flag)
		for (int i=0;i<v.size();i++)
			cout<<v[i].first<<"   "<<v[i].second<<endl;
	*/	
	for (int i=v.size()-1;v[i]>p;--i)
	{
		pair<long long, long long> mi=ref(v[i],p);
	//	if (flag)
	//		cout<<mi.first<<" "<<mi.second<<" "<<missed<<endl;
			
		while (v[ptr]<mi&&v[ptr]<p)
		{
			++missed;
			++ptr;
		}
		if (v[ptr]==mi)
			++ptr;
		else
			++missed;
	}
	
	for (int i=ptr;v[i]<p;i++)
		++missed;
		
	//cout<<fixed<<p.first*.5<<"^"<<p.second*.5<<" "<<missed<<endl;
	
	if(missed<=k)
	{
		ans.push_back(p);
	}
}

vector<pair<long long, long long> > norm(vector<pair<long long, long long> > v)
{
	sort(v.begin(),v.end());
	vector<pair<long long, long long> > res;
	for (int i=0;i<v.size();i++)
	if (i==0||v[i]!=v[i-1])
			res.push_back(v[i]);
	return res;
}

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin>>n>>k;
	
	if (k>=n)
	{
		cout<<-1<<endl;
		return 0;
	}
	
	
	for (int i=1;i<=n;i++)
	{
		int a,b;
		cin>>a>>b;
		v.push_back(make_pair(a*2,b*2));
	}
	
	sort(v.begin(),v.end());
	
	for (int i=0;i<=k+2;i++)
		for (int j=n-1;j>=n-k-2&&j>=0;j--)
		{
			int cx=1ll*(v[i].first+v[j].first)/2;
			int cy=1ll*(v[i].second+v[j].second)/2;
			check(make_pair(cx,cy));
		}
	
	ans=norm(ans);
	
	cout.precision(5);
	cout<<ans.size()<<endl;
	for (int i=0;i<ans.size();i++)
		cout<<fixed<<0.5*ans[i].first<<" "<<0.5*ans[i].second<<endl;
		
	return 0;
}