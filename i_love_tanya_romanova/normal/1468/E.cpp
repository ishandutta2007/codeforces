/*
Cool night gave my truth for a lie
Will you be here when I try
I'm not set cannot do it yet
Will you be here when I try
Our wealth breeds emptiness
Another day to compress

My lips are dry you gave me drugs to try
Hold me when I die
The sky has frozen to a wall
We die we all
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

int tests;
int a,b,c,d;

int P(int a,int b,int c,int d){
	return min(a,b)*min(c,d);
}

int solve(int a,int b,int c,int d){
	int ret=0;
	ret=max(ret,P(a,b,c,d));
	ret=max(ret,P(a,c,b,d));
	ret=max(ret,P(a,d,b,c));
	ret=max(ret,P(b,c,a,d));
	ret=max(ret,P(b,d,a,c));
	return ret;
}
int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>a>>b>>c>>d;
    	cout<<solve(a,b,c,d)<<endl;
    }
    //cin.get(); cin.get();
    return 0;
}