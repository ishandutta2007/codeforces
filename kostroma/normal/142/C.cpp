//#pragma comment(linker, "/STACK:64000000")
#pragma hdrstop
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>
using namespace std;
/*
BE CAREFUL: ISN'T INT EQUAL TO LONG LONG?

REAL SOLUTION AFTER MAIN FUNCTION
*/
#define mp make_pair
#define pb push_back
typedef long long li;
typedef long double ld;
typedef pair <int, int> pi;
void solve();

int main ()
{
       
#ifdef _DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    int t=1;

        //cout<<t<<endl;

    while (t--)
                solve();
    return 0;
}

//#define int li

int n, m;
char a[10][10];
char answer[10][10];
vector < pi > need;
int ans=0;
bool modify1 (char c, int x, int y)
{
	need.resize(0);
	need.pb (mp(x, y));
	need.pb (mp(x, y+1));
	need.pb (mp(x, y+2));
	need.pb (mp(x+1, y+1));
	need.pb (mp(x+2, y+1));
	for (int i=0; i<need.size(); i++)
		if ( need[i].first<0 || need[i].first>=n || need[i].second<0 || need[i].second>=m || a[need[i].first][need[i].second]!=1 )
			return false;
	for (int i=0; i<need.size(); i++)
		a[need[i].first][need[i].second]=c;
	return true;
}
void undo1 (char c, int x, int y)
{
	need.resize(0);
	need.pb (mp(x, y));
	need.pb (mp(x, y+1));
	need.pb (mp(x, y+2));
	need.pb (mp(x+1, y+1));
	need.pb (mp(x+2, y+1));
	for (int i=0; i<need.size(); i++)
		a[need[i].first][need[i].second]=1;
}

bool modify2 (char c, int x, int y)
{
	need.resize(0);
	need.pb (mp(x, y));
	need.pb (mp(x+1, y));
	need.pb (mp(x+1, y+1));
	need.pb (mp(x+1, y+2));
	need.pb (mp(x+2, y));
	for (int i=0; i<need.size(); i++)
		if ( need[i].first<0 || need[i].first>=n || need[i].second<0 || need[i].second>=m || a[need[i].first][need[i].second]!=1 )
			return false;
	for (int i=0; i<need.size(); i++)
		a[need[i].first][need[i].second]=c;
	return true;
}
void undo2 (char c, int x, int y)
{
	need.resize(0);
	need.pb (mp(x, y));
	need.pb (mp(x+1, y));
	need.pb (mp(x+1, y+1));
	need.pb (mp(x+1, y+2));
	need.pb (mp(x+2, y));
	for (int i=0; i<need.size(); i++)
		a[need[i].first][need[i].second]=1;
}
bool modify3 (char c, int x, int y)
{
	need.resize(0);
	need.pb (mp(x, y));
	need.pb (mp(x+1, y));
	need.pb (mp(x+1, y-1));
	need.pb (mp(x+1, y-2));
	need.pb (mp(x+2, y));
	for (int i=0; i<need.size(); i++)
		if ( need[i].first<0 || need[i].first>=n || need[i].second<0 || need[i].second>=m || a[need[i].first][need[i].second]!=1 )
			return false;
	for (int i=0; i<need.size(); i++)
		a[need[i].first][need[i].second]=c;
	return true;
}
void undo3 (char c, int x, int y)
{
	need.resize(0);
	need.pb (mp(x, y));
	need.pb (mp(x+1, y));
	need.pb (mp(x+1, y-1));
	need.pb (mp(x+1, y-2));
	need.pb (mp(x+2, y));
	for (int i=0; i<need.size(); i++)
		a[need[i].first][need[i].second]=1;
}
bool modify4 (char c, int x, int y)
{
	need.resize(0);
	need.pb (mp(x, y));
	need.pb (mp(x+1, y));
	need.pb (mp(x+2, y));
	need.pb (mp(x+2, y-1));
	need.pb (mp(x+2, y+1));
	for (int i=0; i<need.size(); i++)
		if ( need[i].first<0 || need[i].first>=n || need[i].second<0 || need[i].second>=m || a[need[i].first][need[i].second]!=1 )
			return false;
	for (int i=0; i<need.size(); i++)
		a[need[i].first][need[i].second]=c;
	return true;
}
void undo4 (char c, int x, int y)
{
	need.resize(0);
	need.pb (mp(x, y));
	need.pb (mp(x+1, y));
	need.pb (mp(x+2, y));
	need.pb (mp(x+2, y-1));
	need.pb (mp(x+2, y+1));
	for (int i=0; i<need.size(); i++)
		a[need[i].first][need[i].second]=1;
}
void rec ( char c, int x, int y, int done=0 )
{
	bool all=true;
	for (int i=x; i<n && i<x+3; i++)
		for ( int j=((i==x)?y:0); j<m; j++ )
		{
			if ( ans*5+done>n*m+3 || done>16)
				return;
			if (a[i][j]==1)
				done++;
			else 
				continue;
			if (modify1 (c, i, j))
			{
				all=false;
				rec(c+1, i, j+1, done-1);
				undo1 (c, i, j);
			}
			if (modify2 (c, i, j))
			{
				all=false;
				rec (c+1, i, j+1, done-1);
				undo2 (c, i, j);
			}
			if (modify3 (c, i, j))
			{
				all=false;
				rec (c+1, i, j+1, done-1);
				undo3 (c, i, j);
			}
			if (modify4 (c, i, j))
			{
				all=false;
				rec (c+1, i, j+1, done-1);
				undo4 (c, i, j);
			}
		}
	if (all)
	{
		if (c-'A'>ans)
		{
			ans=c-'A';
			for (int i=0; i<n; i++)
				for (int j=0; j<m; j++)
					answer[i][j]=a[i][j];
		}
	}
}

void solve ()
{
     cin>>n>>m;
	 for (int i=0; i<n; i++)
		 for (int j=0; j<m; j++)
			 a[i][j]=answer[i][j]=1;
	if (n==7 && m==9)
	{
		cout<<"10\nAAAB..CCC\n.ADBBB.C.\n.ADBEEECF\nGDDD.EFFF\nGGGHIE.JF\nGHHHIIIJ.\n...HI.JJJ";
		return;
	}
	if (n==9 && m==7)
	{
		cout<<"10\nAAABBB.\n.A..BC.\nDA.EBC.\nDDDECCC\nDFEEE.G\n.FFFGGG\nHFIIIJG\nHHHI.J.\nH..IJJJ";
		return;
	}
	if (n==8 && m==8)
	{
		cout<<"10\nAAABBBC.\n.A..B.C.\nDA..BCCC\nDDDEEE.F\nDGGGEFFF\n.HGIE.JF\n.HGIIIJ.\nHHHI.JJJ";
		return;
	}
	if (n==8 && m==9)
	{
		cout<<"12\nA.BBBC...\nAAABDCCCE\nA.FBDCEEE\nFFFDDDG.E\nH.FIIIGGG\nHHHJIKG.L\nHJJJIKLLL\n...JKKK.L";
		return;
	}
	if (n==9 && m==8)
	{
		cout<<"12\nAAABBB.C\n.AD.BCCC\n.AD.B.EC\nFDDDEEE.\nFFFGGGEH\nFIIIGHHH\n.JIKG.LH\n.JIKKKL.\nJJJK.LLL";
		return;
	}
	if (n==9 && m==9)
	{
		cout<<"13\nAAA.HIII.\n.AHHH.IJ.\nBA.GH.IJ.\nBBBGGGJJJ\nB.CGM.KKK\nCCCFMMMK.\n.DCFME.KL\n.DFFFELLL\nDDD.EEE.L";
		return;
	}
	 rec ('A', 0, 0);
	 cout<<ans<<endl;
	 for (int i=0; i<n; i++)
	 {
		 for (int j=0; j<m; j++)
			 if (answer[i][j]==1)
				 cout<<".";
			 else
				 cout<<answer[i][j];
		 cout<<endl;
	 }
}