/*
Lay your pity on to me
Break your illusions and show me your weakness
A rough taste of the filth you once spread
Mauling a phase in time that you once bled
When you start to scream in silence
When you start to heal in war
Inhale the venom, break the barriers
Show me your true form
As you see the darkness coming
As you hear the pale ones breath
As the final nights are closing in
Scream for me
Shape your twisted mind to the reality around you
Conquer your dream before the world crashes down upon you
Battle the delusions before the poison leaks from our dying breaths
Power our voice to withstand fear
The fiery mind that lingers here
And nothing but a distortion of your true self
Creating the world from nothing at all
Embrace your demons
or cower in hopelessness
Breath tomorrow as it were today
Time is getting short
As you see the darkness coming
As you hear the pale ones breath
As the final nights are closing in
Scream for me
Shape your twisted mind to the reality around you
Conquer your dream before the world crashes down upon you
Battle the delusions before the poison leaks from our dying breaths
Shape your twisted mind to the reality around you
Conquer your dream before the world crashes down upon you
Battle the delusions before the poison leaks from our dying breaths
Bring me down
Bring me down to your personal malevolence
Draw me closer now, or you never will
Bring me down to your personal malevolence
Draw me closer now, or you never will
Bring me down to your personal malevolence
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

const int N = 300000;

using namespace std;

int n,p,q;
int mxx,mxy;

struct pt
{
	int x;
	int y;
};

struct Pt
{
	long double x;
	long double y;
};

Pt get_point(pt a,pt b,long double r)
{
	Pt res;
	res.x=a.x+(b.x-a.x)*r;
	res.y=a.y+(b.y-a.y)*r;
	return res;
}

long double get_dist(Pt a,Pt b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
	
}
vector<pt> v;
vector<pt> hull;

bool cmp(pt p1,pt p2)
{
	if (p1.x!=p2.x)
		return p1.x<p2.x;
	return p1.y>p2.y;
}

long long area(pt p1,pt p2,pt p3)
{
	return 1ll*(p2.x-p1.x)*(p3.y-p1.y)-1ll*(p2.y-p1.y)*(p3.x-p1.x);
}

long double area(pt p1,pt p2,Pt p3)
{
	return 1ll*(p2.x-p1.x)*(p3.y-p1.y)-1ll*(p2.y-p1.y)*(p3.x-p1.x);
}

bool ccw(pt p1,pt p2,pt p3)
{
	return area(p1,p2,p3)>=0;
}

bool ccw(pt p1,pt p2,Pt p3)
{
	return area(p1,p2,p3)>=0;
}

bool cw(pt p1,pt p2,pt p3)
{
	return area(p1,p2,p3)<=0;
}

Pt scale(Pt p,long double l)
{
	p.x*=l;
	p.y*=l;
	return p;
}

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin>>n>>p>>q;
	for (int i=1;i<=n;i++)
	{
		pt temp;
		int x,y;
		cin>>x>>y;
		
		//cin>>temp.x>>temp.y;
		temp.x=x;
		temp.y=y;
		v.push_back(temp);
		mxx=max(mxx,temp.x);
		mxy=max(mxy,temp.y);
	}
	
	pt temp;
	temp.x=0;
	temp.y=mxy;
	v.push_back(temp);
	temp.x=mxx;
	temp.y=0;
	v.push_back(temp);
	
	sort(v.begin(),v.end(),cmp);
	
	hull.push_back(v[0]);
	for (int i=1;i<v.size();i++)
	{
		while (hull.size()>1&&ccw(hull[hull.size()-2],hull[hull.size()-1],v[i]))
			hull.pop_back();
		hull.push_back(v[i]);
	}
/*	
	for (int i=0;i<hull.size();i++)
		cout<<hull[i].x<<" "<<hull[i].y<<endl;
*/	
	pt orig;
	orig.x=orig.y=0;
	
	pt Z;
	Z.x=p;
	Z.y=q;
	
	int ptr=0;
	while (ptr+2<hull.size()&&cw(orig,hull[ptr+1],Z))
		++ptr;
	
//	cout<<ptr<<endl;
	
	long double l,r;
	l=0;
	r=1e8;
	Pt ZZ;
	ZZ.x=Z.x;
	ZZ.y=Z.y;
	
	for (int iter=1;iter<=100;iter++)
	{
		long double mid=l+r;
		mid/=2;
		Pt ZZZ=scale(ZZ,mid);
		if (ccw(hull[ptr],hull[ptr+1],ZZZ))	
			r=mid;
		else
			l=mid;
	}
	/*
	Pt p=get_point(hull[ptr],hull[ptr+1],l);
	cout<<p.x<<"  "<<p.y<<endl;
	long double perday=get_dist(Orig,p);
	
	long double days=get_dist(Orig,ZZ)/perday;
	*/
	cout.precision(12);
	cout<<fixed<<1.0/l<<endl;
	
	return 0;
}