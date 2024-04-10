/*
Hello don't you know me
I'm the dirt beneath your feet
The most important fool you forgot to see
I've seen how you give it
Now I want to receive
I know that you
Would do the same for me

I know I'm headed for the bottom
But I'm riding you all the way

For all of your kisses turned
To spit in my face
For all that reminds me
Which is my place
For all the times when
You made me disappear
This time I'm sure you will
Know that I'm here

I know I'm headed for the bottom
But I'm riding you all the way

My place was beneath you
But now I'm above
And now I send you a message
Of love
A simple reminder of what
You won't see
A future so holy without me

I know I'm headed for the bottom
But I'm riding you all the way
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
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 200031;

int n;
string prepare_basic_string(){
	string res="";
	for (int i=1;i<=n;i++)
		res+="0";
	return res;
}

int ps[10];

int make_query(string st){
	cout<<"? "<<st<<endl;
	int ret;
	cin>>ret;
	return ret;
}

string update(string st,int l,int r){
	for (int i=l;i<=r;i++)
	{
		st[i-1]='1';
	}
	return st;
}

string normalize(string st,int l,int r){
	for (int i=l;i<=r;i++)
	{
		st[i-1]='0';
	}
	return st;
}
void run_solver(string st,int l,int r,int basic_val,int mask){
	if (mask==0)
		return;
	if (l==r){
		if (mask&1)
			ps[0]=l;
		if (mask&2)
			ps[1]=l;
		return ;
	}

	while (true){
		//cout<<l<<" "<<r<<" "<<st<<" "<<mask<<endl;
		int mid=l+r;
		mid/=2;
		st=update(st,l,mid);
		int span=mid-l+1;
		int new_val=make_query(st);
		if (new_val==basic_val+span) // all 0 there
		{
			if (mask&1)
				ps[0]=l;
			if (mask&2)
				run_solver(st,mid+1,r,new_val,2);
			return ;
		}
		if (new_val==basic_val-span)// all 1 there
		{
			if (mask&2)
				ps[1]=l;
			if (mask&1)
				run_solver(st,mid+1,r,new_val,1);
			return;
		}
		//basic_val=new_val;
		st=normalize(st,l,r);
		r=mid;
	}
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;

	string here=prepare_basic_string();

	int orig=make_query(here);

	run_solver(here,1,n,orig,3);

	cout<<"! "<<ps[0]<<" "<<ps[1]<<endl;

	cin.get(); cin.get();
	return 0;
}