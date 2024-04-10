/*
I've had it with confession, I've had it with the priest
I'm tired of all the doctor's and I want to be deceased
I can't control the madness and I don't wanna face the day
No artificial numbness, the pain is here to stay

Can you understand what it is like to be me
Climb the highest mountain and then sink in the sea
Won't you come and take a look, I give you the chance
Wrap your arms around me and we'll do the demon dance

A steady black, it multiplies, attacking sanity
A psychological battering, a relentless enemy
Things are getting brighter and the color's turning red
I'm swallowing this nightmare, the demon shall be fed

I can't hold on much longer
There must be another way
Give me something stronger
Or take my breath away

A deep depressive episode, you know not when it strikes
Is this the one to be all, end all, is the end of the fight
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
#define prev asdgSHJsfgsdfhdsh

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 1200031;

struct pt
{
	int x;
	int y;
};

pt a[100],b[100];
inline int area (pt a, pt b, pt c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

inline bool intersect_1 (int a, int b, int c, int d) {
	if (a > b)  swap (a, b);
	if (c > d)  swap (c, d);
	return max(a,c) <= min(b,d);
}

bool intersect (pt a, pt b, pt c, pt d) {
	return (intersect_1 (a.x, b.x, c.x, d.x))
		&& (intersect_1 (a.y, b.y, c.y, d.y))
		&& (area(a,b,c) * area(a,b,d) <= 0)
		&& (area(c,d,a) * area(c,d,b) <= 0);
}

int get_area(pt a,pt b,pt c){
	return abs(area(a,b,c));
}

bool solve(){
	for (int i=0;i<4;i++){
		int s1=0;
		int s2=0;
		s1=get_area(a[0],a[1],a[2])+get_area(a[0],a[2],a[3]);
		for (int j=0;j<4;j++){
			s2+=get_area(b[i],a[j],a[(j+1)%4]);
		}
		if (s1==s2)
			return true;
	}
	for (int i=0;i<4;i++){
		swap(a[i],b[i]);
	}
	for (int i=0;i<4;i++){
		int s1=0;
		int s2=0;
		s1=get_area(a[0],a[1],a[2])+get_area(a[0],a[2],a[3]);
		for (int j=0;j<4;j++){
			s2+=get_area(b[i],a[j],a[(j+1)%4]);
		}
		if (s1==s2)
			return true;
	}


	for (int i=0;i<4;i++){
		for (int j=0;j<4;j++){
			if (intersect(a[i],a[(i+1)%4],b[j],b[(j+1)%4]))
				return true;
		}
	}
	return false;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	for (int i=0;i<4;i++){
		cin>>a[i].x>>a[i].y;
	}
	for(int i=0;i<4;i++){
		cin>>b[i].x>>b[i].y;
	}
	int here=solve();
	if (here)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

//	cin.get(); cin.get();
	return 0;
}