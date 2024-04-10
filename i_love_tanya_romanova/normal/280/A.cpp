/*
Bleed me, Let it out slow suck me dry
You got to feed me take me down low
Where those angels fly
Aint nothing that I need no more
Like a full truckload of pain
All over like the final score
With a fist full of open veins, you got to bleed me
To all the people that I loved I hated lied
To all my enemies that tried

Bleed me
Read me torn out pages in an open book
Got to please me one more razor now before I cook
Getting hotter as the seconds pass
But I'm told that's what I need
Getting colder now it's flowing fast
But I'm told that's why I bleed
To all the people that I loved I hated lied
To all my enemies that tried

Bleed me
Read me torn out pages in an open book
Got to please me one more razor now before I cook
Getting hotter as the seconds pass
But I'm told that's what I need
Getting colder now it's flowing fast
But I'm told that's why I bleed
To all the people that I loved I hated lied
To all my enemies that tried

I remember sitting in the open air
I remember calling out your name
I remember clearly that I didn't care
I hadn't changed
I need to go away
I need to leave you here
I need to face my fears
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
#define M 18
#define N 1000005

using namespace std;

double w,h,a;

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

pt p[100];
pt p1[100];

pt rot(pt p,double ang)
{
	pt res;
	res.x=p.x*cos(ang)-p.y*sin(ang);
	res.y=p.x*sin(ang)+p.y*cos(ang);
	return res;
}

pt get_point(seg s1,double rat)
{
	pt res;
	res.x=s1.p1.x+(s1.p2.x-s1.p1.x)*rat;
	res.y=s1.p1.y+(s1.p2.y-s1.p1.y)*rat;
	return res;
}

double get_dist(pt p1,pt p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

double get_area(pt p1,pt p2,pt p3)
{
	double res=(p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x);
	if (res<0)
		return -res;
	return res;
}

double get_dist(pt p,seg s)
{
	double d1=get_dist(p,s.p1);
	double d2=get_dist(p,s.p2);
	double d3=get_dist(s.p1,s.p2);
	if (d1*d1>=d2*d2+d3*d3||d2*d2>=d1*d1+d3*d3)
		return min(d1,d2);
	return get_area(p,s.p1,s.p2)/d3;
}

pt get_inter(seg s1,seg s2)
{
	double l,r;
	l=0;
	r=1;
	for (int iter=0;iter<=100;iter++)
	{
		double mid1=2*l+r;
		double mid2=l+2*r;
		mid1/=3;
		mid2/=3;
		pt p1=get_point(s1,mid1);
		pt p2=get_point(s1,mid2);
		double d1=get_dist(p1,s2);
		double d2=get_dist(p2,s2);
		if (d1<d2)
			r=mid2;
		else
			l=mid1;
	}
	pt temp=get_point(s1,l);
	return temp;
}

vector<pt> V;

bool cmp(pt a,pt b)
{
	if (a.x!=b.x)
		return a.x<b.x;
	return a.y<b.y;
}

bool cw(pt p1,pt p2,pt p3)
{
	double d=(p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x);
	if (d<=eps)
		return true;
	return false;
}

bool ccw(pt p1,pt p2,pt p3)
{
	double d=(p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x);
	if (d>=-eps)
		return true;
	return false;
}

vector<pt> convex_hull(vector<pt> v)
{
	sort(v.begin(),v.end(),cmp);
	vector<pt> up,down;
	for (int i=0;i<v.size();i++)
	{
		while (up.size()>1&&ccw(up[up.size()-2],up[up.size()-1],v[i]))
			up.pop_back();
		up.push_back(v[i]);
		while (down.size()>1&&cw(down[down.size()-2],down[down.size()-1],v[i]))
			down.pop_back();
		down.push_back(v[i]);
	}
	if (down.size()>2)
		for (int i=down.size()-2;i>0;--i)
			up.push_back(down[i]);
		return down;
}

void show(vector<pt> v)
{
	cout<<"!"<<endl;
	for (int i=0;i<v.size();i++)
		cout<<v[i].x<<" "<<v[i].y<<endl;
}

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>w>>h>>a;

p[0].x=p[1].x=-w*0.5;
p[2].x=p[3].x=w*0.5;
p[0].y=p[3].y=-h*0.5;
p[1].y=p[2].y=h*0.5;

a=a*M_PI/180;

for (int i=0;i<4;i++)
{
	p1[i]=rot(p[i],a);
}


for (int i=0;i<4;i++)
	for (int j=0;j<4;j++)
	{
		seg s1;
		s1.p1=p[i];
		s1.p2=p[(i+1)%4];
		seg s2;
		s2.p1=p1[j];
		s2.p2=p1[(j+1)%4];
		pt temp=get_inter(s1,s2);
		if (get_dist(temp,s1)<eps&&get_dist(temp,s2)<eps)
		{
			V.push_back(temp);
		}
	}

//show(V);

V=convex_hull(V);

//show(V);

double area=0;
V.push_back(V[0]);

for (int i=0;i+1<V.size();i++)
{
	area+=V[i+1].x*V[i].y-V[i+1].y*V[i].x;
}

if (area<0)
	area=-area;
cout.precision(10);
cout<<fixed<<area<<endl;

//cin.get();cin.get();
return 0;}