/*
There was a game we used to play
We would hit the town on Friday night
And stay in bed until Sunday
We used to be so free
We were living for the love we had and
Living not for reality

It was just my imagination
Just my imagination
Just my imagination...

There was a time I used to pray
I have always kept my faith in love
It's the greatest thing from the man above
The game I used to play
I've always put my cards upon the table
Let it never be said that I'd be unstable

It was just my imagination
Just my imagination
Just my imagination...

There is a game I like to play
I like to hit the town on Friday night
And stay in bed until Sunday
We'll always be this free
We will be living for the love we have
Living not for reality

It's not my imagination
It's not my imagination
It's not my imagination
Not my
Not my
Not my...
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

using namespace std;

int n,m,ans,deg[4050],ar[4050][4050];
vector<pair<int, int> > edges;

int main(){
//freopen("center.in","r",stdin);
//freopen("center.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
ans=1e9;
for (int i=1;i<=m;i++)
{
	int a,b;
	cin>>a>>b;
	deg[a]++;
	deg[b]++;
	ar[a][b]=1;
	ar[b][a]=1;
	edges.push_back(make_pair(a,b));
}

for (int i=0;i<edges.size();i++)
{
	int v1=edges[i].first;
	int v2=edges[i].second;
	for (int nxt=1;nxt<=n;nxt++)
		if (ar[nxt][v1]&&ar[nxt][v2])
			ans=min(ans,deg[v1]+deg[v2]+deg[nxt]);
}

if (ans>1e7)
	cout<<-1<<endl;
else
	cout<<ans-6<<endl;
	
//cin.get();cin.get();
return 0;}