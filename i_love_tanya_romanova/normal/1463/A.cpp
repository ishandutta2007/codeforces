/*
I have a home
Longing to roam
I have to find you
I have to meet you

Signs of your face
Slowing your pace
I need your guidance
I need to seek my innervision
Innervision

My pupils dance
Lost in a trance
Your sacred silence
Losing all violence

Stars in their place
Mirror your face
I need to find you
I need to seek my innervision
Innervision.

It's never too late to reinvent the bicycle
A smile brings forth energy or life
Giving your force

It's never too late to reinvent the bicycle
A smile brings forth energy or life
Giving your force
Vision

There is only one true path to life
the road that leads to all, leads to one
(Innervision, innervision)
There is only one true path to life
the road that leads to one.
Innervision.

Your sacred silence,
Losing all violence.
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

int tests,a,b,c;
int solve(int a,int b,int c){
	int sum=a+b+c;
	if (sum%9)
		return false;
	int iters=sum/9;
	return a>=iters&&b>=iters&&c>=iters;
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>a>>b>>c;
    	if (solve(a,b,c))
    		cout<<"YES"<<endl;
    	else
    		cout<<"NO"<<endl;
    }
    //cin.get(); cin.get();
    return 0;
}