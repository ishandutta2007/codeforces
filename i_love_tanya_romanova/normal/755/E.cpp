/*
Decoction of Jimsonweed
Slimy trailing plants distil
Claustrophobia and blood mixed seed
Cursed downstairs against my will

Cobweb sticks to molten years
Cockroaches served with cream
I wipe the silver bullet tears
And with every tear a dream

With every tear a dream..

Honey tea, psilocybe larvae
Honeymoon, silver spoon
Psilocybe tea

Energy trickles with the tide
Masterminds and the suicide squad
Drink acid water by my side
Stake the saviour of thier daily fraud

Overfilled toothpaste tubes
Sleepless and timeless faces
Drippety drop on sugarcubes
The one eyed's eye twinkles and gazes

Twinkles and gazes...

Honey tea, psilocybe larvae
Honeymoon, silver spoon
Psilocybe tea
*/

#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
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
#include <assert.h>

#define y0 sdkfaslhagaklsldk

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 2100031;

vector<pair<int,int> > edges;
int n;
int ar[100][100];

int get_d()
{
	for (int k=1;k<=n;k++)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				ar[i][j]=min(ar[i][j],ar[i][k]+ar[k][j]);
			}
		}
	}

	int res=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
		res=max(res,ar[i][j]);
		}
	}
	if (res>100)
		res=-1;
	return res;
}
int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	/*cin>>n;

	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			edges.push_back(make_pair(i,j));
		}
	}


	for (int mask=0;mask<(1<<edges.size());mask++)
	{
		if (mask%1000==0)
		{
			cout<<mask<<" "<<(1<<edges.size())<<endl;
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				ar[i][j]=1e9;
			}
			ar[i][i]=0;
		}

		for (int i=0;i<edges.size();i++)
		{
			if (mask&(1<<i))
			{
				int a=edges[i].first;
				int b=edges[i].second;
				ar[a][b]=ar[b][a]=1;
			}
		}
		int res1=get_d();
		for (int i=1;i<=n;i++)
				{
					for (int j=1;j<=n;j++)
					{
						ar[i][j]=1e9;
					}ar[i][i]=0;
				}

				for (int i=0;i<edges.size();i++)
				{
					if (!(mask&(1<<i)))
					{
						int a=edges[i].first;
						int b=edges[i].second;
						ar[a][b]=ar[b][a]=1;
					}
				}
		int res2=get_d();
		if (min(res1,res2)==3)
		{
			cout<<"FOUND"<<endl;
			for (int i=0;i<edges.size();i++)
			{
				if (mask&(1<<i))
				{
					cout<<edges[i].first<<" "<<edges[i].second<<" ";
				}
			}
			cout<<endl;
			break;
		}
	}
*/
	int k;

	cin>>n;
	cin>>k;

	if (k>3)
	{
		cout<<-1<<endl;
		return 0;
	}

	if (k==3)
	{
		if (n<4)
		{
			cout<<-1<<endl;
			return 0;
		}
		cout<<n-1<<endl;
		for (int i=2;i<=n;i++)
		{
			if (i!=3)
			cout<<1<<" "<<i<<endl;
		}
		cout<<2<<" "<<3<<endl;
		return 0;
	}

	if (k==1)
	{
		cout<<-1<<endl;
		return 0;
	}

	//k=2
	if (n<5)
	{
		cout<<-1<<endl;
		return 0;
	}

	cout<<n-1<<endl;
	for (int i=1;i<n;i++)
	{
		cout<<i<<" "<<i+1<<endl;
	}

	cin.get(); cin.get();
	return 0;
}