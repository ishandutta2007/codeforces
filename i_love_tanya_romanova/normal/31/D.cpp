/*
Vengeance will be mine
Riders from hell
Black on black
The magic will never cease
The metal troops will increase
Believers of the holy flame
Fools are no part of the game
Nothing is gonna stand in our way
We fight forevermore
Until the last man will fall
Time to start the war
Raise the metal fist in the air
Brothers everywhere
Raise the metal fist in the air
Unbeliever's nightmare
Raise the metal fist in the air
Brothers everywhere
Raise the metal fist in the air
Riders from hell
Steel invaders
People try to put us down
We hold the key and the crown
The crusade will never end
To the kingdom we assent
Nothing is gonna stand in our way
We fight forevermore
Until the last man will fall
Time to start the war
Raise the metal fist in the air
Brothers everywhere
Raise the metal fist in the air
Unbeliever's nightmare
Raise the metal fist in the air
Brothers everywhere
Raise the metal fist in the air
Riders from hell
Steel invaders
Nothing is gonna stand in our way
We fight forevermore
Until the last man will fall
Time to start the war
Raise the metal fist in the air
Brothers everywhere
Raise the metal fist in the air
Unbeliever's nightmare
Raise the metal fist in the air
Brothers everywhere
Raise the metal fist in the air
Riders from hell
Steel invaders
Raise the metal fist in the air
Raise the metal fist in the air
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

int w,h,n,x1,y1,x2,y2,banned1[105][105],banned2[105][105];
vector<int> ans;
int cnt;
int used[200][200];

bool outside(int x,int y)
{
	return (x<1||x>w||y<1||y>h);
}

bool valid(int x1,int y1,int x2,int y2)
{
	if (outside(x2,y2))
		return false;
	if (used[x2][y2])
		return false;
	if (x1==x2)
	{
		return !banned2[x1][min(y1,y2)];
	}
	return !banned1[min(x1,x2)][y1];
}

void dfs(int a,int b)
{
	//cout<<"!"<<a<<" "<<b<<endl;
	
	cnt++;
	used[a][b]=1;
	if (valid(a,b,a-1,b))
		dfs(a-1,b);
	if (valid(a,b,a+1,b))
		dfs(a+1,b);
	if (valid(a,b,a,b-1))
		dfs(a,b-1);
	if (valid(a,b,a,b+1))
		dfs(a,b+1);
}

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>w>>h>>n;

for (int i=1;i<=n;i++)
{
	cin>>x1>>y1>>x2>>y2;
	if (x1==x2)
	{
		for (int j=y1+1;j<=y2;j++)
			{
				banned1[x1][j]=1;
			//	cout<<"ban "<<x1<<" "<<j<<endl;
			}
	}
	else
	{
		for (int j=x1+1;j<=x2;j++)
			banned2[j][y1]=1;
	}
}

for (int i=1;i<=w;i++)
	for (int j=1;j<=h;j++)
	{
		if (used[i][j])
			continue;
		
		//cout<<"@"<<i<<" "<<j<<endl;
		
		cnt=0;
		dfs(i,j);
		ans.push_back(cnt);
	}

sort(ans.begin(),ans.end());
for (int i=0;i<ans.size();i++)
{
	if (i)
		cout<<" ";
	cout<<ans[i];
}
cout<<endl;

//cin.get();cin.get();
return 0;}