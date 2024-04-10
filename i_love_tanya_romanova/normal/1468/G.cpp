/*
So solitary
You have been
Your time starts to fade
Distorted sky
And you find me
Revolve inside
My blood is yours too
That's what you say
It couldn't be further from the truth

I find
The soul in medication
All my loving has turned and washed away

You took my mind's eye
You bring it wherever you go
How could you take away
The burning I had
My rage
Static
The closing line
Whatever you say
It's my heart you leech
You crushed the edge of symmetry

Insignificant
You are still
But my words in your mouth
Lingering
Spilling over

I see
You don't want liberation
You keep belonging to what's not even here
*/

#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <math.h>
#include <memory.h>
#include <stdio.h>

#include <algorithm>
#include <complex>
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define left asdgashgrketwjklrej
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

const int bs = 1000000007;

const int N = 600031;

int n;
double H,x[N],y[N];
double dx,dy;
double worst_so_far;
double ang_here;

struct pt{
	double x;
	double y;
};

double eval(double x,double y){

	if (x>=dx-1e-12)
		return -1e12;
	double res=-(y-dy)/(x-dx);
	return res;
}

bool is_visible(pt &p){
	//cout<<p.x<<" "<<p.y<<" "<<worst_so_far<<endl;
	double y_lim=dy+(dx-p.x)*worst_so_far;
	return (p.y>=y_lim-1e-12);
}

pt make_point(double x,double y){
	pt ret;
	ret.x=x;
	ret.y=y;
	return ret;
}

double get_dist(pt a,pt b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

pt get_pt(int id1,int id2,double rat){
	pt ret;
	ret.x=x[id1]+(x[id2]-x[id1])*rat;
	ret.y=y[id1]+(y[id2]-y[id1])*rat;
	return ret;
}

pt P[N];

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>n>>H;
    for (int i=1;i<=n;i++){
    	int a,b;
    	cin>>a>>b;
    	x[i]=a;
    	y[i]=b;
    	P[i].x=a;
    	P[i].y=b;
    }

    double ans=0;

    dx=x[n];
    dy=y[n]+H;
    worst_so_far=-1e18;
    /*for (int i=1;i<=n;i++){
    	cout<<eval(x[i],y[i])<<endl;
    }*/

    for (int i=n;i>1;--i){
    	ang_here=eval(x[i],y[i]);
    	worst_so_far=max(worst_so_far,ang_here);
    	double l,r;
    	l=0;
    	r=1;
    	if (is_visible(P[i-1])&&is_visible(P[i])){
    		ans+=get_dist(P[i-1],P[i]);
    		continue;
    	}
    	if (!is_visible(P[i-1])&&!is_visible(P[i])){
    		continue;
    	}
    	int V=is_visible(P[i-1]);
		for (int iter=1;iter<=30;iter++){
			double mid=l+r;
			mid/=2;
			pt temp=get_pt(i-1,i,mid);
			if (is_visible(temp)==V)
				l=mid;
			else
				r=mid;
		}
		pt cut=get_pt(i-1,i,l);
		double D1=get_dist(make_point(x[i-1],y[i-1]),cut);
		double D2=get_dist(make_point(x[i],y[i]),cut);
		if (V==1)// visible
			ans+=D1;
		else
			ans+=D2;
    }
    cout.precision(12);
    cout<<fixed<<ans<<endl;

    //cin.get(); cin.get();
    return 0;
}