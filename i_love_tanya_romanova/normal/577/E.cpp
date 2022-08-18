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

int n,a,b;
vector<pair<int, int> > order[1<<15];
vector<int> ans;

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
//	cin>>a>>b;
	scanf("%d %d",&a,&b);
	order[a/MAG].push_back(make_pair(b,i));
}
for (int i=0;i<=1000000/MAG+31;i++)
{
	sort(order[i].begin(),order[i].end());
	if (i%2)
		reverse(order[i].begin(),order[i].end());
	for (int j=0;j<order[i].size();j++)
	{
		ans.push_back(order[i][j].second);
	}
}

for (int i=0;i<ans.size();i++)
{
	if (i)
		printf(" ");
	printf("%d",ans[i]);
}
cout<<endl;

//cin.get();cin.get();
return 0;}