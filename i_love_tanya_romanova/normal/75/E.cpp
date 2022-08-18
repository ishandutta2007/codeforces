/*
You know you can't be hurt,
You gotta believe in your star,
They'll always treat you like dirt,
They can only push you so far,
They can't take it away
If you've got something to say,
They might try and fence you in,
But you've only gotta live to win
I know it's hard, a natural drag,
It's a hassle to fight,
If you don't wanna be a slag,
If you believe you're right,
They've got the power now,
But soon it's our hour now,
We all know where we been,
We only live to win
You mustn't shout it out loud,
Don't create a scene,
Don't indulge in being proud
It only feeds their scheme,
Break down the wall,
Live it up, it's their time to fall,
Anarchy is coming in,
If you know we're livin' to win
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
#define bs 1000000009
#define bsize 128

const int N = 2500;

using namespace std;

struct pt
{
	double x;
	double y;
};

struct seg
{
	pt p1;
	pt p2;
};

int n;

pt island[N];
pt start;
pt finish;

double get_dist(pt a,pt b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

pt eval(pt a,pt b,double r)
{
	a.x+=(b.x-a.x)*r;
	a.y+=(b.y-a.y)*r;
	return a;
}

double get_dist(pt p,seg s)
{
	double l,r;
	l=0;
	r=1;
	for (int iter=1;iter<=100;iter++)
	{
		double mid1,mid2;
		mid1=l*2+r;
		mid2=l+r*2;
		mid1/=3;
		mid2/=3;
		pt p1,p2;
		p1=eval(s.p1,s.p2,mid1);
		p2=eval(s.p1,s.p2,mid2);
		double d1,d2;
		d1=get_dist(p,p1);
		d2=get_dist(p,p2);
		if (d1<d2)
			r=mid2;
		else
			l=mid1;
	}
	pt p1=eval(s.p1,s.p2,l);
	return get_dist(p,p1);
}

double get_oriented_area(pt a,pt b,pt c)
{
	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

bool is_inside(pt p)
{
	for (int i=0;i<n;i++)
	{
		double A=get_oriented_area(island[i],island[(i+1)%n],p);
		if (A<0)
			return false;
	}
	return true;
}

double get_p_dist(pt p)
{
	double res=1e18;
	for (int i=0;i<n;i++)
	{
		seg s;
		s.p1=island[i];
		s.p2=island[(i+1)%n];
		res=min(res,get_dist(p,s));
	}
	if (is_inside(p))
		return -res;
	return res;
}

double distance_shoreline(double a,double b,double L)
{
	a=fabs(a-b);
	return min(a,L-a);
}

pt get_p_intersection(pt start, pt goal)
{
	double l,r;
	l=0;
	r=1;
	for (int iter=0;iter<=100;iter++)
	{
		double mid=l+r;
		mid/=2;
		pt temp=eval(start,goal,mid);
		if (is_inside(temp))
			r=mid;
		else
			l=mid;
	}
	pt temp=eval(start,goal,l);
	return temp;
}

double get_ang_pos(pt p)
{
	double res=0;
	for (int i=0;i<n;i++)
	{
		double D=get_dist(island[i],island[(i+1)%n]);
		double d1=get_dist(island[i],p);
		double d2=get_dist(island[(i+1)%n],p);
		//cout<<d1<<"%"<<d2<<" "<<D<<endl;
		if (fabs(d1+d2-D)<eps)
			return res+d1;
		res+=D;
	}
}

void show(pt p)
{
	cout<<"%"<<p.x<<" "<<p.y<<endl;
}

int main(){
//	freopen("path2.in","r",stdin);
//	freopen("path2.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin>>start.x>>start.y>>finish.x>>finish.y;
	
	cin>>n;
	
	for (int i=0;i<n;i++)
	{
		cin>>island[i].x>>island[i].y;
	}
	
	double l,r;
	l=0;
	r=1;
	for (int iter=1;iter<=100;iter++)
	{
		double mid1=l*2+r;
		double mid2=l+r*2;
		mid1/=3;
		mid2/=3;
		double dist1=get_p_dist(eval(start,finish,mid1));
		double dist2=get_p_dist(eval(start,finish,mid2));
		if (dist1<dist2)
			r=mid2;
		else
			l=mid1;
	}
	
	pt P=eval(start,finish,l);
	double d=get_p_dist(P);
	if (d>eps)
	{
		cout.precision(10);
		cout<<fixed<<get_dist(start,finish)<<endl;
		return 0;
	}
	
	pt p1=get_p_intersection(start,P);
	pt p2=get_p_intersection(finish,P);
	
	double ans1=get_dist(start,p1)+2*get_dist(p1,p2)+get_dist(p2,finish);
	/*
	show(p1);
	show(p2);
	
	show(P);
	*/
	double per=0;
	for (int i=0;i<n;i++)
		per+=get_dist(island[i],island[(i+1)%n]);
	
	double d1=get_ang_pos(p1);
	double d2=get_ang_pos(p2);
	
	double shoreline=distance_shoreline(d1,d2,per);
	
//	cout<<d1<<"%"<<d2<<endl;
	
	double ans2=get_dist(start,p1)+get_dist(finish,p2)+shoreline;
	
	cout<<fixed<<min(ans1,ans2)<<endl;
	
	return 0;
}