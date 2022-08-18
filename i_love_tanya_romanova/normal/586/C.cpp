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

int n;
int v[1<<20],d[1<<19],p[1<<18],used[1<<18];
vector<int> ans;

void run2(int x)
{
	used[x]=1;
	for (int i=x+1;i<=n;i++)
	{
		if (used[i])
			continue;
		p[i]-=d[x];
		if (p[i]<0)
			run2(i);
	}
}

void cab(int x)
{
	used[x]=1;
	int vv=v[x];
	for (int i=1;i<=n;i++)
	{
		if (used[i])
			continue;
		if (vv<0)
			continue;
		p[i]-=vv;
		vv--;
	}
	for (int i=1;i<=n;i++)
		if (used[i]==0&&p[i]<0)
			run2(i);
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
	cin>>v[i]>>d[i]>>p[i];

for (int i=1;i<=n;i++)
{
	if (used[i])
		continue;
	cab(i);
	ans.push_back(i);
	/*
	for (int j=1;j<=n;j++)
		if (used[j]==0)
			cout<<p[j]<<" ";
		cout<<endl;*/
}

cout<<ans.size()<<endl;
for (int i=0;i<ans.size();i++)
{
	if (i)	
		cout<<" ";
	cout<<ans[i];
}
cout<<endl;

//cin.get();cin.get();
return 0;}