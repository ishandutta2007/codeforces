/*
If you wanna make a life playing in a rock and roll band
You've got to take a chance and don't look back
There ain't no easy way, you can't fake it
You've got to be yourself, don't follow the pack
When it seems you'll never get a break
You've got to make a vow to keep the faith

You got to fight
For all that you believe in
You've got to fight
It's you against the world
Stand up and fight
Stand up and fight

If you're looking for the light of inspiration
Waiting for your story to be told
When music is your life and your vocation
You've got to give your soul to rock and roll
When things around you start to fall apart
Don't forget what drove you from the start

You got to fight
For all that you believe in
You've got to fight
It's you against the world
Stand up and fight
Stand up and fight

It's never easy living on the breadline
When every day you're following your dream
If you catch the rising star, you might make it
But nothing's ever as easy as it seems
When it seems you'll never get a break
You've got to make a vow to keep the faith

You got to fight
For all that you believe in
You've got to fight
It's you against the world
Stand up and fight
Stand up and fight
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
#define bsize 256
#define N 1031

using namespace std;

double x1,y1,x2,y2,V,T,vx,vy,wx,wy;

double get_dist(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

bool solve(double time)
{
	double p1,p2;
	if (time<=T)
		p1=time,p2=0;
	else
		p1=T,p2=time-T;
	
	double tx=x2;
	double ty=y2;
	tx-=p1*vx;ty-=p1*vy;// first
	tx-=p2*wx;ty-=p2*wy;//second;
	double DD=get_dist(tx,ty,x1,y1);
	double can=V*time;
	if (can>=DD)
		return 1;
	return 0;
}

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	
	cin>>x1>>y1>>x2>>y2;
	cin>>V>>T;
	cin>>vx>>vy>>wx>>wy;
	
	double l,r;
	l=0;
	r=1e9;
	for (int iter=1;iter<=200;iter++)
	{
		double mid=l+r;
		mid/=2;
		if (solve(mid))
			r=mid;
		else
			l=mid;
	}
	cout.precision(12);
	cout<<fixed<<l<<endl;
	
	return 0;
}