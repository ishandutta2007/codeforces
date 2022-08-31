/*
There is this face in the still water
I can't remember ever wearing
Like fingerprints on your heart
Reading out the last lines of code
To the untrained eye a secret
I bled away the last of you

Sought trust in shapes of combined results
That trickles from a less than solid case
Fought off attacks of resurfaced lust
Burn the gracing grounds

No, what will give in first?
The body or the lash
Monochromatic stains
No, who will cave in first?
The leader or the fake
Monochromatic stains, oh!

This pile of ashes of a soul
Informant pokes abound
These sickly little fingers
Get away from me

Tread not the path of least restraint
Each piece of evidence a lie, a lie
The body, the face all items in place
I don't remember a thing

No, what will give in first?
The body or the lash
Monochromatic stains
No, who will cave in first?
The leader or the fake
Monochromatic stains

A sacrifice made to the loss of mind
Folly a man's demise

Track now the stains that allow my fall
Sickening, the sight of it all
Never shall I claim my innocence
I just was not there

No, what will give in first?
The body or the lash
Monochromatic stains
No, who will cave in first?
The leader or the fake
Monochromatic stains
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
#define right asdashgasrhsdf

#define eps 1e-14
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 200031;

int n,m;
vector<int> entries[N];
int ar[N];
int maps[N];
vector<int> num_list;

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>ar[i];
	}

	int ok=1;
	for (int i=1;i<=n;i++)
	{
		entries[ar[i]].push_back(i);
	}

	for (int i=1;i<=n;i++)
	{
		if (entries[i].size()==0)
			continue;
		int ok_here=0;
		for (int j=0;j<entries[i].size();j++)
		{
			if (entries[i][j]==i)
				ok_here=1;
		}
		if (ok_here==0)
			ok=0;
	}

	if (!ok)
	{
		cout<<-1<<endl;
		return 0;
	}

	for (int i=1;i<=n;i++)
	{
		if (entries[i].size()==0)
			continue;
		num_list.push_back(i);
	}

	m=num_list.size();
	for (int i=0;i<num_list.size();i++)
	{
		maps[num_list[i]]=i+1;
	}

	cout<<m<<endl;
	for (int i=1;i<=n;i++)
	{
		if (i>1)
			cout<<" ";
		cout<<maps[ar[i]];
	}
	cout<<endl;
	for (int i=1;i<=m;i++)
	{
		if (i>1)
			cout<<" ";
		cout<<num_list[i-1];
	}
	cout<<endl;

	cin.get(); cin.get();
	return 0;
}