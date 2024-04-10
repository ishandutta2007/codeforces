/*
The black and green scarecrow as everyone knows
Stood with a bird on his hat and straw everywhere.
He didn't care.
He stood in a field where barley grows.

His head did no thinking
His arms didn't move except when the wind cut up
Rough and mice ran around on the ground
He stood in a field where barley grows.

The black and green scarecrow is sadder than me
But now he's resigned to his fate
'Cause life's not unkind, he doesn't mind.
He stood in a field where barley grows.
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
#define M 18
#define N 1050

using namespace std;

int n,m,tests;
string st;
int board[N][N];
int used[N][N];
vector<pair<int, int> >pict;
int C;
int ans[N][N];

void dfs(int a,int b);

void tryy(int a,int b)
{
	if (used[a][b])
		return;
	if (board[a][b]==1)
		++C;
	else
		dfs(a,b);
}

void dfs(int a,int b)
{
	pict.push_back(make_pair(a,b));
	used[a][b]=1;
	tryy(a-1,b);
	tryy(a+1,b);
	tryy(a,b-1);
	tryy(a,b+1);
}

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>tests;

for (int i=1;i<=n;i++)
{
	cin>>st;
	for (int j=1;j<=m;j++)
	{
		if (st[j-1]=='*')
			board[i][j]=1;
		else
			board[i][j]=0;
	}
}

for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	{
		if (used[i][j])
			continue;
		if (board[i][j])
			continue;
		pict.clear();
		C=0;
		dfs(i,j);
		for (int q=0;q<pict.size();q++)
		{
			int qx=pict[q].first;
			int qy=pict[q].second;
			ans[qx][qy]=C;
		}
	}

for (;tests;--tests)
{
	int a,b;
	cin>>a>>b;
	cout<<ans[a][b]<<endl;
}
//cin.get();cin.get();
return 0;}