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

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512
#define MAG 1000

using namespace std;

int n;
int P[1<<20];
int used[1<<20];
vector<int> Cycle[1<<19];
int found1,found2,foundodd;

vector<int> get_cycle(int v)
{
	vector<int> res;
	int cl=v;
	while (true)
	{
		if (used[v])
			break;
		res.push_back(v);
		used[v]=cl;
		v=P[v];
	}
	return res;
}

void trace(int v,int cl)
{
	if (used[v])
		return;
	used[v]=cl;
	trace(P[v],3-cl);
}

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
	cin>>P[i];
}

for (int i=1;i<=n;i++)
{
	if (used[i])
		continue;
	Cycle[i]=get_cycle(i);
	if (Cycle[i].size()==1)
	{
		found1=i;
	}
	if (Cycle[i].size()%2)
	{
		foundodd=i;
	}
	if (Cycle[i].size()==2)
	{
		found2=i;
	}
}

if (found1)
{
	cout<<"YES"<<endl;
	for (int i=1;i<=n;i++)
		if (i!=found1)
		{
			cout<<i<<" "<<found1<<endl;
		}
	return 0;
}

if (foundodd)
{
	cout<<"NO"<<endl;
	return 0;
}
if (found2==0)
{
	cout<<"NO"<<endl;
	return 0;
}

int av1,av2;

av1=Cycle[found2][0];
av2=Cycle[found2][1];

for (int i=1;i<=n;i++)
{
	used[i]=0;
}

for (int i=1;i<=n;i++)
{
	if (used[i])
		continue;
	trace(i,1);
}

cout<<"YES"<<endl;
cout<<av1<<" "<<av2<<endl;

for (int i=1;i<=n;i++)
{
	if (i==av1||i==av2)
		continue;
	if(used[i]==1)
		cout<<i<<" "<<av1<<endl;
	else
		cout<<i<<" "<<av2<<endl;
}

//cin.get();cin.get();
return 0;}