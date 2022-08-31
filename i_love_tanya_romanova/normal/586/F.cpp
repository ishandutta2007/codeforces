/*
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

int take[1000];
int n,a[1<<20],b[1<<20],c[1<<20];
vector<pair<pair<int, int> ,pair<int, int> > > V;
int amask1,amask2;

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=0;i<n;i++)
	cin>>a[i]>>b[i]>>c[i];

int half=n/2;

if (n%2==1)
	++half;

int ttl=1;
for (int i=0;i<half;i++)
	ttl*=3;

for (int mask=0;mask<ttl;mask++)
{
	int cur=mask;
	for (int i=half-1;i>=0;--i)
	{
		take[i]=cur%3;
		cur/=3;
	}
	int score1,score2,score3;
	score1=score2=score3=0;
	for (int i=0;i<half;i++)
	{
		if (take[i]==0)
			score2+=b[i],
			score3+=c[i];
		if (take[i]==1)
			score1+=a[i],
			score3+=c[i];
		if (take[i]==2)
			score1+=a[i],
			score2+=b[i];
	}
	
	V.push_back(make_pair(make_pair(score2-score1,score3-score1),make_pair(-score1,mask)));
}

sort(V.begin(),V.end());

// CP - p2

int ascore=-2e9;

int rem=n-half;

ttl=1;
for (int i=0;i<rem;i++)
	ttl*=3;

for (int mask=0;mask<ttl;mask++)
{
	int cur=mask;
	for (int i=n-1;i>=half;--i)
	{
		take[i]=cur%3;
		cur/=3;
	}
	int score1,score2,score3;
	score1=score2=score3=0;
	for (int i=half;i<n;i++)
	{
		if (take[i]==0)
			score2+=b[i],
			score3+=c[i];
		if (take[i]==1)
			score1+=a[i],
			score3+=c[i];
		if (take[i]==2)
			score1+=a[i],
			score2+=b[i];
	}
	int need1=score1-score2;
	int need2=score1-score3;
	pair<pair<int, int> ,pair<int, int> > need=make_pair(make_pair(need1,need2),make_pair(-2e9,-1));
	int id=lower_bound(V.begin(),V.end(),need)-V.begin();
	if (id==V.size())
		continue;
	if (V[id].first.first!=need.first.first||V[id].first.second!=need.first.second)
		continue;
	int sum_here=-V[id].second.first+score1;
	if (sum_here>ascore)
	{
		ascore=sum_here;
		amask1=V[id].second.second;
		amask2=mask;
	}
}

if (ascore<-1e9)
{
	cout<<"Impossible"<<endl;
	return 0;
}

for (int i=half-1;i>=0;--i)
{
	take[i]=amask1%3;
	amask1/=3;
}
for (int i=n-1;i>=half;i--)
{
	take[i]=amask2%3;
	amask2/=3;
}

int score1,score2,score3;
score1=score2=score3=0;

for (int i=0;i<n;i++)
{
	score1+=a[i];
	score2+=b[i];
	score3+=c[i];
	if (take[i]==0)
		score1-=a[i];
	if (take[i]==1)
		score2-=b[i];
	if (take[i]==2)
		score3-=c[i];
	
	if (take[i]==0)
		cout<<"MW"<<endl;
	if (take[i]==1)
		cout<<"LW"<<endl;
	if (take[i]==2)
		cout<<"LM"<<endl;
}

assert(score1==score2&&score2==score3);
//cout<<score1<<" "<<score2<<" "<<score3<<endl;

//cout<<"@"<<ascore<<endl;

//cin.get();cin.get();
return 0;}