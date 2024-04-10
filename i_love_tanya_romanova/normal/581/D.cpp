/*
Imagine every morbid thought
You've had throughout your life
Becoming real in the eyes
Every sucker with a weak mind

You're invited to a place
A sinister fearful haven
Where a human sacrifice
Is some stupid ass religion

What the hell is wrong with the world?
Views are so distorted
No regard for human life
No law and order

Darkness
Sure can be a rude awakening
No guest
Has ever escaped the torturing

Creepy
Feelings coming over you
Creepy feelings
Lock 'em away in a room

This is all created from
Their wild imagination
The difference between truth and false
Depends on your fascination

Creepy feelings
Coming over you
Protest
Fools who will lead you into it
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

int a[10],b[10];
vector<int> order;
int ans[500][500];
int found;
int side;
int board[500][500];
int ta[10],tb[10];
int area;

int get_root(int x)
{
	int p=sqrt(x+.5);
	if (p*p!=x)
		return -1;
	return p;
}

bool check(vector<int> order,int mask)
{
	for (int i=0;i<3;i++)
		if (mask&(1<<i))
			ta[i]=b[i],
			tb[i]=a[i];
		else
			ta[i]=a[i],
			tb[i]=b[i];
	
	for (int i=0;i<side;i++)
		for (int j=0;j<side;j++)
			board[i][j]=-1;
	
	int ptr=0;
	
	for (int i=0;i<side;i++)
		for (int j=0;j<side;j++)
		{
			if (board[i][j]!=-1)
				continue;
			if (ptr==3)
				return false;
			for (int q=0;q<ta[ptr];q++)
				for (int w=0;w<tb[ptr];w++)
					{
						if (q+i>=side||w+j>=side||board[q+i][w+j]!=-1)
							return false;
						board[q+i][w+j]=ptr;
					}
				++ptr;
		}
	
	for (int i=0;i<side;i++)
		for (int j=0;j<side;j++)
			ans[i][j]=board[i][j];
	found=1;
	return true;
}

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

for (int i=0;i<3;i++)
{
	cin>>a[i]>>b[i];
	area+=a[i]*b[i];
}

side=get_root(area);
if (side==-1)
{
	cout<<-1<<endl;
	return 0;
}

for (int i=0;i<3;i++)
	order.push_back(i);

do
{
	for (int mask=0;mask<8;mask++)
	{
		check(order,mask);
	}
}while(next_permutation(order.begin(),order.end()));

if (!found)
{
	cout<<-1<<endl;
	return 0;
}

cout<<side<<endl;

for (int i=0;i<side;i++)
{
	for (int j=0;j<side;j++)
		cout<<char(ans[i][j]+'A');
	cout<<endl;
}
//cin.get();cin.get();
return 0;}