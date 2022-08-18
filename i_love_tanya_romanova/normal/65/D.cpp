/*
Running through the darkness
Won't do you no good to flee
Stalking through the golden state
Who's bitch do you want to be?
Can't run, can't hide
Gonna get you, wait and see

You know I'm weird
I know I'm weird, I'm crazy
Now feel your backbone shiver
Lucky thing for you, babe, I'm so lazy
But I'm gonna pull your trigger

Look over your shoulder
And all the windows too
Bow down to the golden calf
Which bitch is the one for you?
What you need is extra speed
'Cause I'm gonna hit on you

You know I'm weird
I know I'm weird, I'm crazy
Now feel your backbone shiver
Lucky thing for you, babe, I'm so lazy
But I'm gonna pull your trigger

Know you can't stop
Move it on over
But that's another story
'Cause I knew your mama

Out here in the city
Just half a mile behind
Searching for the golden rose
Which bitch would you like to find?
You can't run forever
And you're still on my mind

You know I'm weird
I know I'm weird,I'm crazy
Now feel your backbone shiver
Lucky thing for you, babe, I'm so lazy
But I'm gonna pull your trigger

You know I'm weird
I know I'm weird, I'm crazy
Never mind the dicky ticker
Lucky thing for you, babe, I'm so lazy
But I'm gonna pull your trigger
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

#define eps 1e-14
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 128

const int N = 12500;

using namespace std;

int n;
string st;
int can_get[N];
vector<vector<int> > states[N];
int valid_move[N];

int get_cur(char c)
{
	if (c=='?')
		return -1;
	if (c=='G')
		return 0;
	if (c=='H')
		return 1;
	if (c=='R')
		return 2;
	if (c=='S')
		return 3;
}

vector<int> make_move(vector<int> v,int ps)
{
	v[ps]++;
	return v;
}

void eval(vector<int> v,int cur)
{
	for (int i=0;i<4;i++)
		valid_move[i]=0;
	
	if (cur!=-1)
	{
		valid_move[cur]=1;
		return ;
	}
	
	int mn=1e9;
	for (int i=0;i<v.size();i++)
		if (v[i]<mn)
			mn=v[i];
	
	for (int i=0;i<v.size();i++)
		if (v[i]==mn)
			valid_move[i]=1;
}

int main(){
//	freopen("path2.in","r",stdin);
//	freopen("path2.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin>>n;
	cin>>st;
	
	vector<int> v;
	for (int i=0;i<4;i++)
		v.push_back(0);
	states[0].push_back(v);

	for (int i=0;i<n;i++)
	{
		sort(states[i].begin(),states[i].end());
		for (int j=0;j<states[i].size();j++)
		{
			if (j>0&&states[i][j]==states[i][j-1])
				continue;
			int cur=get_cur(st[i]);
			eval(states[i][j],cur);
			for (int q=0;q<4;q++)
				if (valid_move[q])
				{
					vector<int> v3=make_move(states[i][j],q);
					states[i+1].push_back(v3);
				}
		}
	}
	
	for (int i=0;i<states[n].size();i++)
	{
		eval(states[n][i],-1);
		for (int j=0;j<4;j++)
			can_get[j]|=valid_move[j];
	}
	
	if (can_get[0])
		cout<<"Gryffindor"<<endl;
	if (can_get[1])
		cout<<"Hufflepuff"<<endl;
	if (can_get[2])
		cout<<"Ravenclaw"<<endl;
	if (can_get[3])
		cout<<"Slytherin"<<endl;
	
	return 0;
}