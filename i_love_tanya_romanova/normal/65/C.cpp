/*
Don't talk to me, I don't believe a word
Don't try to make me feel alright
All the love in all the world
Is not enough to save my soul tonight
Don't be my friend I'm not a fool
Don't talk of things that we cannot see
When all the ones that sing the blues
Sometimes I think of how it used to be

I have seen the Devil laugh
I have seen God turn his face away
I have nothing left to lose
I have nothing left to say
I have seen the sky turn black
I have seen the seas run dry
I have nothing that is yours
I have nothing now that is not mine

Don't look at me your eyes are cold and hard
Don't wonder that I turn to you
All the grief in all the world
Is not enough to make me comfort you
Don't tell me lies, I'm not a dog
Don't talk of love it seems to me
All the people that we rob
Sometimes I think of how they used me

I have seen the fires of Hell
I have seen angels with flaming swords
I have nothing that is mine
I have much that could be yours
I have seen the eye of God
I have heard lies that are true
I have nothing for myself
I have nothing I would give to you

Don't say that word, I know it's only fools
Who do not know their fate is just
All the justice in the world
Is not enough to buy my faith and trust
Don't make that face I won't be pleased
Don't make a sideshow of yourself
All the people we released
Sometimes I think you're someone else

I have been where none have been
In the empty howling rooms
I have everything I need
I have everything you stand to lose
I have seen the diamond worlds
I have seen the shape of space
I have nothing but the world
I have nothing to take its place
I don't believe a word, I don't believe a word [x3] I don't believe a word
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
double vp,vs;
double len;

struct pt
{
	double x;
	double y;
	double z;
};

pt tr[N];
pt orig;

double get_dist(pt a,pt b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}

pt eval(pt a,pt b,double rat)
{
	a.x+=(b.x-a.x)*rat;
	a.y+=(b.y-a.y)*rat;
	a.z+=(b.z-a.z)*rat;
	return a;
}

pt get_point(double need)
{
	for (int i=0;i<n;i++)
	{
		double D=get_dist(tr[i],tr[i+1]);
		if (D<need)
		{
			need-=D;
			continue;
		}
		double rat=need/D;
		return eval(tr[i],tr[i+1],rat);
	}
}

int main(){
//	freopen("path2.in","r",stdin);
//	freopen("path2.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin>>n;
	for (int i=0;i<=n;i++)
	{
		cin>>tr[i].x>>tr[i].y>>tr[i].z;
	}
	cin>>vp>>vs;
	
	cin>>orig.x>>orig.y>>orig.z;
	
	len=0;
	for (int i=1;i<=n;i++)
		len+=get_dist(tr[i-1],tr[i]);
	
	double d1=get_dist(orig,tr[n]);
	
	if (d1/vp>len/vs+eps)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	
	double l,r;
	l=0;
	r=len;
	
	for (int iter=1;iter<=70;iter++)
	{
		double mid=l+r;
		mid/=2;
		pt P=get_point(mid);
		double time1=mid/vs;
		double time2=get_dist(orig,P)/vp;
		if (time2>time1+eps)// too late
			l=mid;
		else
			r=mid;
	}
	
	cout.precision(10);
	
	cout<<"YES"<<endl;
	cout<<fixed<<l/vs<<endl;
	pt P=get_point(l);
	cout<<P.x<<" "<<P.y<<" "<<P.z<<endl;
	
	return 0;
}