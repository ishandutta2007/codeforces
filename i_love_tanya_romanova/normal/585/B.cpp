/*
Things that I thought I had put far behind
Find the mind, connect to sever
I felt deeply how my feelings combined
That it's like they'll never sever

In a way I started today
to weave guirlands for the grave
It will break me till my knees bend
It will leave me with nothing in the end

In a blatant mind, my thoughts have entwined
But if you feel the real they will divide
From beyond within, the heart plays its part
the real and fake forever sever
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

int n,k,reach[500][500];
int nreach[500];
string st;
string board[10];
int ban[500][500];
int tests;

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>tests;
for (;tests;--tests)
{
	cin>>n>>k;
	
	for (int i=0;i<=100;i++)
		for (int j=0;j<=3;j++)
			reach[j][i]=ban[j][i]=0;
		
	for (int i=1;i<=3;i++)
	{
		cin>>board[i];
		if (board[i][0]=='s')
			reach[i][0]=1;
		for (int j=0;j<board[i].size();j++)
			if (board[i][j]>='A'&&board[i][j]<='Z')
				ban[i][j]=1;
			else
				ban[i][j]=0;
	}
	
	for (int move=0;move<n;move++)
	{
		
		for (int i=1;i<=3;i++)
			nreach[i]=0;
		
		if (move)	
		for(int i=1;i<=3;i++)
			if (ban[i][3*move]||ban[i][3*move-1])
				reach[i][move]=0;
			
		for (int i=1;i<=3;i++)
		{
			if (reach[i][move])
			{
				if (ban[i][move*3+1]==0)
					nreach[i]=1;
			}
		}
		/*
		for (int i=1;i<=3;i++)
			cout<<nreach[i];
		cout<<endl;
		*/
		for (int i=1;i<=3;i++)
			for (int j=1;j<=3;j++)
				if (nreach[i]==1)
					if (abs(i-j)<=1)
						if (ban[j][move*3+1]==0)
							reach[j][move+1]=1;
	///	cout<<reach[1][move+1]<<" "<<reach[2][move+1]<<" "<<reach[3][move+1]<<endl;
	}
	if (reach[1][n-1]+reach[2][n-1]+reach[3][n-1])
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}
//cin.get();cin.get();
return 0;}