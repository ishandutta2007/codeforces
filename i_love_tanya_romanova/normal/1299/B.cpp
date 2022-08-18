/*
Those wounds have been revealed
Clawing through this wasteland
No emotion lives, suffocate on hope
Swallow your last rational thought
It tastes of every heart you've devoured
Your veins constrict, they are choking you
Wrapped in vanity, you're dying.
Unveiled by searing hatred
You gasp for life, you can't hold me now
I've let you go, bleed into obscurity
Clawing through this wasteland
No emotion lives, suffocate on hope
Swallow your last rational thought.
It tastes of every heart you've devoured
Your veins constrict
They are choking you
Wrapped in vanity, you're dying
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
#define left asdgashgrketwjklrej
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-9
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 300031;

int n;
struct pt{
	int x;
	int y;
};

pt p[N];
int cx[N],cy[N];

bool solver(){
	if (n%2==1)
		return false;
	for (int i=0;i<n;i++){
		cx[i]=p[i].x+p[i+n/2].x;
		cy[i]=p[i].y+p[i+n/2].y;
	}
	for (int i=0;i<n;i++){
		if (cx[i]!=cx[0]||cy[i]!=cy[0])
			return false;
	}
	return true;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n;
    for (int i=0;i<n;i++){
    	cin>>p[i].x>>p[i].y;
    	p[i+n].x=p[i].x;
    	p[i+n].y=p[i].y;
    }

    if (solver())
    	cout<<"Yes"<<endl;
    else
    	cout<<"No"<<endl;

    //    cin.get(); cin.get();
    return 0;
}