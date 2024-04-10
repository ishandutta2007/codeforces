/*
Bring me all your pitch black deeds.
Cover them in moral deficiency.
Beyond the rough fabric of any sane mind.
Just another great depression?
More like another great decision
to submerge your mind into great delusion.
Clear your mind, obey.
Clean me with your unknowing smiles.
Gather at the root of your own decay
and bathe in the maelstrom to cleanse your mind.
All faces blank, without emotion,
a submission, a horrid devotion to
the unnamed, the anonymous.
Bring me all your pitch black deeds.
Cover them in moral deficiency.
Beyond the rough fabric of any sane mind.
The designs,
clinging onto a broken mold.
There are no sides.
When you ignore that there is no trouble at all.
Monolithic splendor.
Tell me about your enemy.
Abomination put into reality.
A drop of sweat inks your skin.
Troubled by the grins of uncertainty.
All faces blank, without emotion,
a submission, a horrid devotion to
the unnamed, the anonymous.
All faces blank, without emotion,
a submission, a horrid devotion to
the unnamed, the anonymous.
Unveil the unnamed.
Deflesh the inner workings.
A burning sensation for freedom in great cowardice,
fulfilling the true human nature.
Clean the truth with blood of the liar's vein.
A burning sensation for freedom in great cowardice,
fulfilling the true human nature.
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

const int N = 300000;

using namespace std;

int n,m;
vector<pair<int, int> > costs,need;
set<pair<int,pair<int, int> > >F;
set<pair<int,pair<int, int> > >::iterator it;
pair<int, int> ans[N];
int bound[N];

void add_edge(int a,int b,pair<int, int> p)
{
	ans[p.second]=make_pair(a,b);
}

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		int w,has;
		cin>>w>>has;
		w=1e9-w;
		if (has==1)
		{
			costs.push_back(make_pair(w,i));
		}
		else
			need.push_back(make_pair(w,i));
	}
	
	sort(costs.begin(),costs.end());
	
	for (int i=1;i<n;i++)
	{
		add_edge(i,i+1,costs[i-1]);
		bound[i]=costs[i-1].first;
	}
	
	for (int i=n-1;i>=1;--i)
	{
		for (int j=i+2;j<=n;j++)
		{
			F.insert(make_pair(bound[i],make_pair(i,j)));
			//cout<<bound[i]<<"%"<<i<<" "<<j<<endl;
			
			if (F.size()>131131)
				break;
		}
	}
	
	sort(need.begin(),need.end());
	reverse(need.begin(),need.end());
	
	for (int i=0;i<need.size();i++)
	{
		pair<int, pair<int,int> > p=make_pair(need[i].first,make_pair(-1,-1));
		it=F.lower_bound(p);
		if (it==F.end())
		{
			cout<<-1<<endl;
			return 0;
		}
		p=(*it);
		F.erase(p);
		add_edge(p.second.first,p.second.second,need[i]);
	}
	
	for (int i=1;i<=m;i++)
	{
		cout<<ans[i].first<<" "<<ans[i].second<<"\n";
	}
	
	return 0;
}