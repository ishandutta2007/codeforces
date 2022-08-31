/*
She's wearin' dresses on the border line
(Lookin' good)
Oh wakin' senses that were lost in time
(Make amends)
This liberation is the one they'll love for ages
(Hey man, I see them comin')

Just cut those dresses, make you look so fine
(You're a ten)
Put on that shirt and you'll look so divine
(I'm impressed)
This generation won't forgive those signs of agin'
(Hey man, I see them comin')

I've got my ticket for the next makeover
I've got my ticket for a stolen ride

I believe, I believe
I believe in the fallen
I believe, I believe
I believe in the callin'

They've got injections for the facial lines
(Make amends)
Break out the scalpel keep the nose defined
(Look again)
A crucifixion of the love we've known for ages
(Hey man, I see them comin')

You're much too pretty, you don't need your mind
(Just pretend)
Just bat them eyelids, get your heart desires
(Make amends)
A resurrection of the shallow and the vapid
(Hey man, I see them comin')

I've got my ticket for the next makeover
I lost my taste for this, I'll keep my pride

I believe, I believe
I believe in the fallen
I believe, I believe
I believe in the callin'

Reject

I've got my ticket for the next makeover
I lost my taste for this, I'll keep my pride

I believe, I believe
I believe in the fallen
I believe, I believe
I believe in the callin'

I believe, I believe
I believe in the fallen
I believe, I believe
I believe in the callin'
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

#define eps 1e-16
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

const int N = 200005;

using namespace std;

long double x1,y1,x2,y2,r1,r2;

long double gd(long double x1,long double y1,long double x2,long double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

long double solve_cos(long double a,long double b,long double c)
{
	return acos((a*a+b*b-c*c)/(2*a*b));
}

long double cut(long double ang,long double r)
{
	long double s1,s2;
	s1=ang*r*r/2;
	s2=sin(ang)*r*r/2;
	//cout<<s1<<" "<<s2<<endl;
	return s1-s2;
}

long double solve()
{
	if (r1<r2)
	{
		swap(x1,x2);
		swap(y1,y2);
		swap(r1,r2);
	}
	long double cd=gd(x1,y1,x2,y2);
	if (cd+r2<=r1+eps)
		return r2*r2*M_PI;
	if (cd>=r1+r2-eps)
		return 0;
	long double ang1=solve_cos(cd,r1,r2);
	long double ang2=solve_cos(cd,r2,r1);
	//cout<<ang1<<" "<<ang2<<endl;
	return cut(ang1*2,r1)+cut(ang2*2,r2);
}


int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin>>x1>>y1>>r1;
	cin>>x2>>y2>>r2;
	
	cout.precision(12);
	cout<<fixed<<solve()<<endl;
	
	return 0;
}