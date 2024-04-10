/*
The sky is black, the sea is red
The world is coming to an end
Starvation and famine, have spread across the land
All sinners will die in the end
Nailed to the cross, the son of God
He died for all your sins
The seventh day, Sunday the Sabbath
He'll walk the earth again

[Chorus:]
For all those who have sinned
This is hell on earth, burn until
The end the crown of thorns,
The ten commandments the writing is etched in stone
The non believers, playing with evil
This is a power they've never known
Fire and brimstone, eternal hell
God's wrath shall shake the earth
Pleasures of the flesh, a life of greed
You steal, you cheat, you lie

[Chorus]

Rise from the dead. The savior of slaves
His spirit and power are strong!
Pray for your soul, repent for your sins
You know what you've done is wrong!
The crucifix, blood on the cross, symbolic misery
The pain of man who stood and fought
To live and now be free

[Chorus]

Condemned to the land of thieves
Banished from heaven and hell
In purgatory you will wait
For one hundred years you've been scorned

The sky is black, the sea is red
The world is coming to an end
Starvation and famine, have spread across the land
All sinners will die in the end
Nailed to the cross, the son of God
He died for all your sins, the seventh day, Sunday the Sabbath
He'll walk the earth again

[Chorus]

Condemned to the land of thieves
Banished from heaven and hell
In purgatory you will wait
For one hundred years you've been scorned

Hell, Hell
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

#define bsize 256

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 1200031;

const int MAG = 1100000;

int dist[MAG*2];
int have[MAG];

unsigned int bset[MAG];

int n,k;
vector<int> v1,v2;

unsigned int can_add[N];

long long ans=1e18;

vector<int> compress(vector<int> v){
	sort(v.begin(),v.end());
	vector<int> ret;
	for (int i=0;i<v.size();i++)
	{
		if (i==0||v[i]!=v[i-1])
			ret.push_back(v[i]);
	}
	return ret;
}

void clear_bset()
{
	for (int i=0;i<=MAG/32;i++)
	{
		bset[i]=0;
	}
}

queue<int> qu;

unsigned int one = 1;


int MEMO[1<<20];

void set1(int ps)
{
	bset[ps/32]|=(one<<(ps%32));
}

int get_lowest_bit(unsigned int val)
{
	if (val%65536==0)
	{
		return get_lowest_bit(val>>16)+16;
	}
	return MEMO[val%65536];
}

vector<int> solve(vector<int> v){
	v=compress(v);
	clear_bset();
	for(int i=0;i<MAG;i++)
	{
		dist[i]=1e9;
	}

	for (int i=0;i<v.size();i++)
	{
		qu.push(v[i]);
		set1(v[i]);
		dist[v[i]]=1;
	}

	for (int i=0;i<=35;i++)
	{
		can_add[i]=0;
	}

	for (int i=0;i<v.size();i++)
	{
		can_add[v[i]/32]|=(one<<(v[i]%32));
	}

	while (qu.size())
	{
		int v=qu.front();

		qu.pop();
		//cout<<v<<endl;
		//cin.get();
		if (v>MAG-2000)
			continue;

		for (int i=0;i<=34;i++)
		{
			if (v%32==0)
			{
				unsigned int here=(bset[v/32+i]|can_add[i]);
				here^=bset[v/32+i];
				while (here!=0)
				{
					int ps=get_lowest_bit(here);
					here-=(one<<ps);
					dist[ps+v+i*32]=dist[v]+1;
					set1(ps+v+i*32);
					qu.push(ps+v+i*32);
				}
			}
			else
			{
				unsigned int rem=v%32;
				unsigned int in_low=((can_add[i]<<rem)|bset[v/32+i]);
				in_low^=bset[v/32+i];
				unsigned int here=in_low;
				//cout<<"@"<<here<<endl;

				while (here!=0)
				{
					int ps=get_lowest_bit(here);
					here-=(one<<ps);
					dist[ps+v/32*32+i*32]=dist[v]+1;
					set1(ps+v/32*32+i*32);
					qu.push(ps+v/32*32+i*32);
				}
				unsigned int in_high=(can_add[i]>>(32-rem));
				//in_high=(in_high<<(32-rem));
				in_high|=bset[v/32+i+1];
				in_high^=bset[v/32+i+1];
				here=in_high;

//				cout<<"@"<<here<<endl;

				while (here!=0)
				{
					int ps=get_lowest_bit(here);
					here-=(one<<ps);
					dist[ps+v/32*32+i*32+32]=dist[v]+1;
					set1(ps+v/32*32+i*32+32);
					qu.push(ps+v/32*32+32+i*32);
				}
			}
		}
	}
	vector<int> ret;
	for (int i=0;i<MAG;i++)
	{
		ret.push_back(dist[i]);
	}
	return ret;
}

int main(){
	//freopen("cinema.in","r",stdin);
	//freopen("cinema.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>k;

	for (int i=1;i<(1<<16);i++)
	{
		for (int j=0;j<16;j++)
		{
			if (i&(1<<j))
			{
				MEMO[i]=j;
				break;
			}
		}
	}

	for (int i=0;i<k;i++)
	{
		int val;

		scanf("%d",&val);
		if (val==n)
		{
			cout<<1<<endl;
			return 0;
		}
		if (val<n)
		{
			val=n-val;
			v1.push_back(val);
		}
		else
		{
			v2.push_back(val-n);
		}
	}

	vector<int> res1=solve(v1);
	vector<int> res2=solve(v2);

	for (int i=1;i<MAG;i++)
	{
		ans=min(ans,0ll+res1[i]+res2[i]);
	}

	if (ans>1e8)
		ans=-1;
	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}