/*
If I gave you the truth, would it keep you alive?
Though I'm closer to wrong, I'm no further from right
And now I'm convinced on the inside that something's wrong with me
Convinced on the inside, you're so much more than me, yeah

No there's nothing you say that can salvage the lie
But I'm trying to keep my intentions disguised
And now I'm deprived of my conscience and something's got to give
Deprived of my conscience, this all belongs to me, yeah

I'm beaten down again, I belong to them
Beaten down again, I've failed you
I'm weaker now my friend, I belong to them
Beaten down again, I've failed you

The deception you show is your own parasite
Just a word of advice you can heed if you like
And now I'm convinced on the inside that something's wrong with me
Convinced on the inside you're so much more than me, yeah

I'm beaten down again, I belong to them
Beaten down again, I've failed you
I'm weaker now my friend, I belong to them
Beaten down again, I've failed you

I'm beaten down again, I belong to them
Beaten down again, I've failed you
I'm weaker now my friend, I belong to them
Beaten down again, I've failed you

I'm beaten down
I'm beaten down
I'm beaten down
I'm beaten down, yeah
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

int n,m,ar1[500][500],ar2[500][500];

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			ar1[i][j]=1e9,
			ar2[i][j]=1;
			
	for (int i=1;i<=m;i++)
	{
		int a,b;
		
		cin>>a>>b;
		ar1[a][b]=1;
		ar1[b][a]=1;
		ar2[a][b]=ar2[b][a]=1e9;
	}
	
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				ar1[i][j]=min(ar1[i][j],ar1[i][k]+ar1[k][j]),
				ar2[i][j]=min(ar2[i][j],ar2[i][k]+ar2[k][j]);
	
	if (ar1[1][n]>1e7||ar2[1][n]>1e7)
		cout<<-1<<endl;
	else
		cout<<max(ar1[1][n],ar2[1][n])<<endl;
		
	return 0;
}