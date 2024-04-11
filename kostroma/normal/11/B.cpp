#pragma hdrstop
#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;

#define mp make_pair
#define pb push_back
typedef long long li;
typedef long double ld;

void solve();
int main ()
{
#ifdef _DEBUG
	freopen ("in.txt", "r", stdin);
#endif
	solve();
	return 0;
}
#define int li
int tr[100000];
//vector <int> e[2000];
void solve ()
{
	//e[0].pb (0);
	//for ( int i=0; i<=10; i++ )
	//{
	//	for ( int j=0; j<e[i].size(); j++ )
	//	{
	//		e[i+1].pb ( e[i][j]-i-1 );
	//		e[i+1].pb ( e[i][j]+i+1 );
	//	}
	//	sort (e[i+1].begin(), e[i+1].end());
	//	e[i+1].resize(unique ( e[i+1].begin(), e[i+1].end() )-e[i+1].begin());
	//	for (int j=0; j<e[i+1].size(); j++)
	//		if (e[i+1][j]>0)
	//		cout<<e[i+1][j]<<' ';
	//	cout<<endl<<endl;
	//}
	int x;
	cin>>x;
	if (x<0)
		x=-x;
	if (x==0)
	{
		cout<<"0";
		return;
	}
	for (int i=1; i<100000; i++)
		tr[i]=i*(i+1)/2;
	if (x%2)
	{
		for ( int j=1; j<100000; j++ )
			if ( x<=tr[j] && (j%4==1 || j%4==2))
			{
				cout<<j;
				return;
			}
	}
	for (int j=1; j<100000; j++)
		if (x<=tr[j] && ( j%4==0 || j%4==3 ))
		{
			cout<<j;
			return;
		}
}