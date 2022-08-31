/*
Catholic's dictator
Swine without compasion
No respect for others life
Godsent corrupt saint

Rampant, organized crime of the cross
Rituals justified ways to express
The oldest lie in support of the

Heartless motherfucker
Sympathy there's none
You immoralize prevention
Abortion is not a sin
Heaven none of you'll ever be saved
Awareness drown in devotion
Follow the rules
Dig your own grave

Murder under the cross
Profit ways don't leave no
Room for the scum
Open your eyes the messiah
Will never come (your fuckin' messiah)
You're killing the poor

There is no justice
There is no law
There's no messiah
There is no saviour, there is no god

The truth you teach it ain't
No truth to me
the things you see are not
The thing that I see
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

const int N = 200000;

using namespace std;

int n,m,f[N];
vector<int> ent[N];
int ans[N];
int bad;

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
//	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>f[i];
		ent[f[i]].push_back(i);
	}
	for (int i=1;i<=m;i++)
	{
		int val;
		cin>>val;
		if (ent[val].size()==0)
		{
			cout<<"Impossible"<<endl;
			return 0;
		}
		if (ent[val].size()>1)
			bad=1;
		ans[i]=ent[val][0];
	}
	
	if (bad)
	{
		cout<<"Ambiguity"<<endl;
		return 0;
	}
	
	cout<<"Possible"<<endl;
	for (int i=1;i<=m;i++)
	{
		if (i>1)
			cout<<" ";
		cout<<ans[i];
	}
	cout<<endl;
	
	return 0;
}