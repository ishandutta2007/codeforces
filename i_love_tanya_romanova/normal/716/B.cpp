/*
Cut off my wings and come lock me up
Just pull the plug yeah, I've had enough
Tear me to pieces, sell me for parts
You're all vampires so here

You can have my heart (my heart, my heart...)
You can have my heart (my heart, my heart...)
You can have my heart (my heart, my heart...)

The world's a funeral, I run with ghosts
No hint of movement, no sign of pulse
Only an echo, just skin and bone
They kick the chair but we, we help tie the rope

(My heart, my heart...)
You can have my heart (my heart, my heart...)
You can have my heart (my heart, my heart...)
You can have my heart (my heart, my heart...)

So come rain on my parade
'Cause I want to feel it
Come shove me over the edge
'Cause my head is in overdrive
I'm sorry but it's too late
And it's not worth saving
So come rain on my parade
I think we're doomed, I think we're doomed
And there is no way back

You must've made some kind of mistake
I asked for death, but instead I'm awake
The devil told me "No room for cheats"
I thought I sold my soul, but he kept the receipt

So leave the lights on, Im coming home
It's getting darker but I carry on
The sun don't shine here, it never did
And when it rains, it fucking pours
But I think I like it
And you know that I'm in love with the pain
I think I like it

So come rain on my parade
'Cause I want to feel it
Come shove me over the edge
'Cause my head is in overdrive
I'm sorry but it's too late
And it's not worth saving
So come rain on my parade

I think we're doomed, I think we're doomed
And there is no way back

I think we're doomed, I think we're doomed
And there is no way back

So come rain on my parade
'Cause I want to feel it
Come show me over the edge
'Cause my head is in overdrive
I'm sorry but it's too late
And it's not worth saving
So come rain on my parade

I think we're doomed, I think we're doomed
And there is no way back
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 220031;

string st;
int cnt[10000];
int found;

void make_good(int ps)
{
	for (int i='A';i<='Z';i++)
	{
		cnt[i]=0;
	}

//	cout<<"%"<<endl;

	for (int i=ps;i<ps+26;i++)
	{
		if (st[i]!='?')
		{
			cnt[st[i]]=1;
		}
	}
	int ptr='A';
	for (int i=ps;i<ps+26;i++)
	{
		if (st[i]!='?')
			continue;
		//cout<<ptr<<endl;
		while (cnt[ptr]!=0)
		{
			++ptr;
		}
		st[i]=ptr;
		ptr++;
	}
}

bool is_good(int ps)
{
	for (int i='A';i<='Z';i++)
	{
		cnt[i]=0;
	}
	for (int i=ps;i<ps+26;i++)
	{
		if (st[i]=='?')
			continue;
		if (cnt[st[i]])
			return false;
		cnt[st[i]]=1;
	}
	return true;
}


int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>st;
	for (int start=0;start+26<=st.size();start++)
	{
		if (is_good(start))
		{
			found=1;
			make_good(start);
			break;
		}
	}
	//cout<<found<<endl;

	if (!found)
		cout<<-1<<endl;
	else
	{
		for (int i=0;i<st.size();i++)
		{
			if (st[i]=='?')
				st[i]='A';
		}
		cout<<st<<endl;
	}
	cin.get(); cin.get();
	return 0;
}