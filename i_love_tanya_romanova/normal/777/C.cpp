/*
It's caving in around me
What I thought was solid ground
I tried to look the other way
But I couldn't turn around
It's OK for you to hate me
For all the things I've done
I've made a few mistakes
But I'm not the only one

Step away from the ledge
I'm coming down

I could never be
What you want me to
You pulled me under
To save yourself
(Save yourself)
You will never see
What's inside of me
I pulled you under just to save myself

Was there ever any question
On how much I could take?
You kept feeding me your bullshit
Hoping I would break
Is there anybody out there?
Is there anyone who cares?
Is there anybody listening?
Will they hear my final prayers?

Step away from the ledge
I'm coming down

I could never be
What you want me to
You pulled me under
To save yourself
(Save yourself)
You will never see
What's inside of me
I pulled you under just to save myself
(Save myself)

It's caving in around me
(Caving in)
It's tearing me apart
(Tearing me)
It's all coming down around me
(Coming down)
Does anyone
Anyone
Care at all?

I will never be
What you want me to
You pull me under
I pull you under

I could never be
What you want me to
You pulled me under
To save yourself
(Save yourself)
You will never see
What's inside of me
I pulled you under just to save myself
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

#define eps 1e-11
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 111031;

int n,m;
vector<vector<int> > B;
vector<vector<int> > D;
int tests,ans[N];

int main(){
//	freopen("explosion.in","r",stdin);
//	freopen("explosion.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>m;
	B.resize(n);
	D.resize(n);

	for (int i=0;i<n;i++)
	{
		B[i].resize(m);
		D[i].resize(m);

		for (int j=0;j<B[i].size();j++)
		{
			cin>>B[i][j];
		}
	}

	for (int i=n-1;i>=0;--i)
	{
		for (int j=0;j<m;j++)
		{
			if (i==n-1)
				D[i][j]=i;
			else
			{
				D[i][j]=D[i+1][j];
				if (B[i][j]>B[i+1][j])
					D[i][j]=i;
			}
		}
	}

	for (int i=n-1;i>=0;--i)
	{
		int bst=0;
		for (int j=0;j<m;j++)
		{
			bst=max(bst,D[i][j]);
		}
		ans[i]=bst;
	}

	cin>>tests;
	for (;tests;--tests)
	{
		int a,b;
		cin>>a>>b;
		--a;
		--b;
		if (ans[a]>=b)
			cout<<"Yes"<<"\n";
		else
			cout<<"No"<<"\n";
	}

	cin.get(); cin.get();
	return 0;
}