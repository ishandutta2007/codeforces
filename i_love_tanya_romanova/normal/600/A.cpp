/*
Yeah

Here she comes again, she's feeling like she's already won
I believe it's gonna end again, all for naught
My philosophy is things are just as wrong as they seem
I believe it's gonna end this way, atrocity

Do you believe in love like I believe in pain
Nobody died for you, somebody pray for me

When you see me cut me down
And I will force it underground
There's no one left to hurt but me
And it's because of me, right?

There he walks away, he's feeling like he's having them on
I believe he's gonna bend again and all for no
My philosophy is things are just as wrong as they seem
I've gotta get you off of my mind, in oddity

Do you believe in love like I believe in pain
Nobody died for you, somebody pray for me

When you see me cut me down
And I will force it underground
There's no one left to hurt but me
And it's because of me, right?

I want to see you suffer, suffer

When you see me cut me down
And I will force it underground
There's no one left to hurt but me
And it's because of me, right?

When you see me cut me down
And when you see me cut me down
And when you see me cut me down
And it's because of me, suffer
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

const int N = 100005;

using namespace std;

string st;
vector<string> v1,v2;

bool good(string st)
{
	if (st.size()==0)
		return false;
	for (int i=0;i<st.size();i++)
		if (st[i]<'0'||st[i]>'9')
			return false;
	if (st.size()>1&&st[0]=='0')
		return false;
	return true;
}

void add_string(string st)
{
	if (good(st))
		v1.push_back(st);
	else
		v2.push_back(st);
}
int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	getline(cin,st);
	
	string temp="";
	
	for (int i=0;i<st.size();i++)
	{
		if (st[i]==';'||st[i]==',')
		{
			add_string(temp);
			temp="";
		}
		else
			temp+=st[i];
	}
	
	add_string(temp);
	
	if (v1.size()==0)
		cout<<"-"<<endl;
	else
	{
		cout<<"\"";
		for (int i=0;i<v1.size();i++)
		{
			if (i)
				cout<<",";
			cout<<v1[i];
		}
		cout<<"\"";
		cout<<endl;
	}
	
	if (v2.size()==0)
		cout<<"-"<<endl;
	else
	{
		cout<<"\"";
		for (int i=0;i<v2.size();i++)
		{
			if (i)
				cout<<",";
			cout<<v2[i];
		}
		cout<<"\"";
		cout<<endl;
	}
	
	return 0;
}