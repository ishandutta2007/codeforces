
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

#define eps 1e-11
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 200031;

int n;
string st1[N],st2[N],name1[N],name2[N];

int pick[N];

void redraw(int id)
{
	pick[id]=2;
	for (int i=1;i<=n;i++)
	{
		if (name1[i]==name2[id]&&pick[i]==1)
		{
			redraw(i);
		}
	}
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>st1[i]>>st2[i];
	}

	for (int i=1;i<=n;i++)
	{
		name1[i]="";
		name1[i]+=st1[i][0];
		name1[i]+=st1[i][1];
		name1[i]+=+st1[i][2];
		name2[i]=st1[i][0];
		name2[i]+=st1[i][1];
		name2[i]+=st2[i][0];
		//cout<<i<<" "<<name1[i]<<" "<<name2[i]<<endl;
	}

	for (int i=1;i<=n;i++)
	{
		pick[i]=1;
	}

	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (i==j)
				continue;
			if (name1[i]==name1[j])
				pick[i]=pick[j]=2;
		}
	}

	int ok=1;


	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			string a,b;
			if (pick[i]==1)
				a=name1[i];
			else
				a=name2[i];
			if (pick[j]==1)
				b=name1[j];
			else
				b=name2[j];
			if (a==b)
			{
				if (pick[i]==1)
					redraw(i);
				if (pick[j]==1)
					redraw(j);
			}
		}
	}

	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			string a,b;
			if (pick[i]==1)
				a=name1[i];
			else
				a=name2[i];
			if (pick[j]==1)
				b=name1[j];
			else
				b=name2[j];
			if (a==b)
				ok=0;
		}
	}

	if (!ok)
	{
		cout<<"NO"<<endl;
		return 0;
	}

	cout<<"YES"<<endl;
	for (int i=1;i<=n;i++)
	{
		string a;
		if (pick[i]==1)
			a=name1[i];
		else
			a=name2[i];
		cout<<a<<endl;
	}

	cin.get(); cin.get();
	return 0;
}